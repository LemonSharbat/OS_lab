# Lab Handbook

A small, static website for organising lab questions, notes and source programs. The `programs/` directory is the content source of truth. The website is generated from those files; there is no admin panel, database or separate copy of your code to maintain.


## Requirements

- Bun (1.4.4)
- Git

## Run locally

```bash
bun install
bun run dev
```

Astro prints a local URL, normally `http://localhost:4321/`.

Useful commands:

```bash
bun run validate         # Validate program metadata and source files
bun run check            # Astro and TypeScript diagnostics
bun run build            # Generate static website
bun run preview          # Preview generated website
```

## Add a new program

1. Create a new directory under the correct subject and part, for example:

   `programs/operating-systems/part-a/fcfs/`

2. Add a source file, such as `program.c`.
3. Add an `info.md` file beside it. Start with this frontmatter:

   ```yaml
   ---
   title: First Come First Serve Scheduling
   subject: Operating Systems
   part: A
   category: CPU Scheduling
   language: c
   source: program.c
   order: 2
   tags:
     - scheduling
     - cpu
   ---
   ```

4. Write any Markdown content below the frontmatter. All sections are optional: include only what helps for that program. You can use headings, paragraphs, lists, tables, links and fenced code blocks.
5. Run `bun run validate` and `bun run build` locally if you want to check before pushing.
6. Commit and push to `main` (or open a pull request). The workflow validates and builds the site. A successful push to `main` is deployed to GitHub Pages once Pages is configured.

### Frontmatter fields

| Field | Required | Meaning |
|---|---|---|
| `title` | Yes | Display title |
| `subject` | No | Defaults to `Operating Systems` |
| `part` | No | `A` or `B`; defaults to `A` |
| `category` | No | Optional grouping/short description |
| `language` | Yes | `c`, `cpp`, `bash` or `text` |
| `source` | Yes | Source filename relative to this program folder |
| `order` | No | Sort order within a part; defaults to 999 |
| `tags` | No | Searchable keywords |

### Flexible Markdown

There is no mandatory template for the body. For example, a program may have only a question and source code. Another may include an algorithm, compilation commands, sample input, sample output, notes or multiple examples. Use the headings that make sense; omit everything else.

Fenced Markdown code blocks are syntax-highlighted automatically. Use language labels such as `c`, `bash`, `text`, `console` or `shell` after the opening backticks. Sample output should normally use `text` so it is displayed as output rather than treated as executable code.

The main source file is rendered separately from the Markdown body. It receives a filename header and a copy button. The copy button copies the original source text, not the highlighted HTML.

### Multiple source files

The current first version expects one primary source file per program page. The folder can still contain supporting files, but displaying multiple source files with separate tabs/blocks is a future enhancement. For now, set `source` to the file you want featured.

## Tech choices

- **Astro** builds the pages at build time. The deployed `dist/` directory is static HTML, CSS and JavaScript.
- **Astro Content Collections** discover each `info.md` file and validate its frontmatter schema.
- **Shiki** highlights the standalone source code at build time using a VS Code-style grammar engine.
- **Plain CSS and small browser scripts** handle layout, mobile navigation, search and copy. There is no client-side framework runtime.
- **GitHub Actions** checks pull requests and deploys successful builds from `main`.

No backend or database is needed for this use case.
