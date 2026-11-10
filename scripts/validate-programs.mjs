import { readdir, readFile, stat } from 'node:fs/promises';
import path from 'node:path';

const root = path.resolve('programs');
const allowedExtensions = new Set(['.c', '.h', '.cpp', '.hpp', '.sh', '.txt']);
const errors = [];
let count = 0;

async function walk(directory) {
  const entries = await readdir(directory, { withFileTypes: true });
  for (const entry of entries) {
    const fullPath = path.join(directory, entry.name);
    if (entry.isDirectory()) {
      await walk(fullPath);
      continue;
    }
    if (entry.name !== 'info.md') continue;

    count++;
    const relative = path.relative(root, fullPath);
    const text = await readFile(fullPath, 'utf8');
    const match = text.match(/^---\s*\n([\s\S]*?)\n---/);
    if (!match) {
      errors.push(`${relative}: missing YAML frontmatter`);
      continue;
    }

    const fields = Object.fromEntries(
      match[1].split('\n').filter((line) => /^[\w-]+\s*:/.test(line)).map((line) => {
        const index = line.indexOf(':');
        return [line.slice(0, index).trim(), line.slice(index + 1).trim().replace(/^['"]|['"]$/g, '')];
      })
    );
    for (const required of ['title', 'part', 'language', 'source']) {
      if (!fields[required]) errors.push(`${relative}: missing required field "${required}"`);
    }
    if (fields.part && !['A', 'B'].includes(fields.part)) errors.push(`${relative}: part must be A or B`);

    const programDirectory = path.dirname(fullPath);
    if (fields.source) {
      const sourcePath = path.resolve(programDirectory, fields.source);
      if (!sourcePath.startsWith(`${programDirectory}${path.sep}`)) {
        errors.push(`${relative}: source must be a file inside the program directory`);
      } else {
        try {
          const sourceStat = await stat(sourcePath);
          if (!sourceStat.isFile()) errors.push(`${relative}: source is not a file`);
          if (!allowedExtensions.has(path.extname(sourcePath))) errors.push(`${relative}: unsupported source extension`);
        } catch {
          errors.push(`${relative}: source file not found (${fields.source})`);
        }
      }
    }
  }
}

try {
  await walk(root);
} catch (error) {
  console.error(`Could not scan programs/: ${error.message}`);
  process.exit(1);
}

if (count === 0) errors.push('No programs found. Add a folder containing info.md and its source file.');
if (errors.length) {
  console.error('\nProgram validation failed:\n');
  for (const error of errors) console.error(`- ${error}`);
  process.exit(1);
}
console.log(`Validated ${count} program entr${count === 1 ? 'y' : 'ies'}.`);
