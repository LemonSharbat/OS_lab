# OS Lab Programs

A simple, static website for organising Operating Systems lab questions, notes and source code.

The idea is: **keep the actual programs and their documentation inside `programs/`, and let the website take care of presenting them.**

There is no admin panel, database or separate copy of the source code to maintain. Edit your files, and the website is generated from them during the build.

## ✨ Features

- **One source of truth:** All questions, notes and source programs live in `programs/`.
- **Flexible notes:** Write documentation in Markdown. Include only the sections relevant to a particular program.
- **Syntax highlighting:** Source code and Markdown code blocks are highlighted automatically.
- **Copy code:** Copy the original source directly from a program page.
- **Static website:** No backend, database or client-side framework runtime.
- **Automated deployment:** GitHub Actions validates, builds and deploys the website to GitHub Pages.

## 🚀 Getting Started

### Requirements

- [Bun](https://bun.com/) — version `1.4.4`
- [Git](https://git-scm.com/)

### Run locally

Clone the repository and enter the project directory:

```bash
git clone https://github.com/LemonSharbat/OS_lab.git
cd OS_lab
```

Install dependencies:

```bash
bun install
```

Start the development server:

```bash
bun run dev
```

Astro will print a local URL, usually:

```text
http://localhost:4321/
```

The development server updates the website as you make changes to the project files.

### Useful commands

| Command | Purpose |
|---|---|
| `bun run dev` | Start the local development server |
| `bun run validate` | Validate program metadata and source files |
| `bun run check` | Run Astro and TypeScript diagnostics |
| `bun run build` | Generate the static website |
| `bun run preview` | Preview the generated website locally |

## 📚 Adding a New Program

The `programs/` directory is the content source of truth. To add a program, create a folder under the appropriate subject and lab part.

For example:

```text
programs/
└── operating-systems/
    └── part-a/
        └── fcfs/
            ├── info.md
            └── program.c
```

Each program folder currently needs two files:

- `program.c` — the actual source code (the filename can be different).
- `info.md` — the question, metadata and any supporting notes.

### 1. Add the source file

Write your program normally in the appropriate source file.

For example, `program.c`:

```c
#include <stdio.h>

int main() {
    printf("Hello, OS Lab!\\n");
    return 0;
}
```

### 2. Add `info.md`

Start with the following frontmatter:

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

### 3. Write your notes

Below the frontmatter, write whatever documentation is useful for that program.

For example:

```markdown
## Question

Implement the First Come First Serve CPU scheduling algorithm.

## Algorithm

1. Read the number of processes.
2. Accept the burst time for each process.
3. Calculate waiting time and turnaround time.
4. Display the results.

## Compilation

```bash
gcc program.c -o program
./program
```

## Sample Output

```text
Enter number of processes: 3
...
```

There is no mandatory template for the Markdown content. You can use headings, paragraphs, lists, tables, links and fenced code blocks as needed.

An algorithm, compilation instructions, sample input, output and additional notes are all optional.

### Frontmatter reference

| Field | Required | Description |
| --- | --- | --- |
| `title` | Yes | Name displayed on the program page |
| `subject` | No | Subject name. Defaults to `Operating Systems` |
| `part` | No | Lab part: `A` or `B`. Defaults to `A` |
| `category` | No | Optional grouping or short description |
| `language` | Yes | Source language: `c`, `cpp`, `bash`, or `text` |
| `source` | Yes | Primary source filename, relative to the program folder |
| `order` | No | Sorting order within a part. Defaults to `999` |
| `tags` | No | Keywords used for searching and filtering |

### Code blocks and syntax highlighting

Use fenced Markdown code blocks with a language identifier:

````markdown
```c
printf("Hello World");
```

```bash
gcc program.c -o program
```

```text
Hello World
```
````

Common identifiers include `c`, `cpp`, `bash`, `text`, `console` and `shell`.

Use `text` for sample output so it is displayed as plain output rather than treated as executable code.

The primary source file is rendered separately from the Markdown notes. It includes a filename header and a copy button. The button copies the original source text, not the highlighted HTML.

### Multiple source files

The current version supports **one primary source file per program page**.

You can still keep supporting files in the same folder, but only the file specified by the `source` field in `info.md` is displayed as the main program.

Displaying multiple source files using separate tabs or code blocks can be added later.

## 🛠️ How It Works

The project uses a small set of tools, each with a specific responsibility.

| Technology | Responsibility |
|---|---|
| **Astro** | Generates the website at build time |
| **Astro Content Collections** | Discovers program documentation and validates its frontmatter |
| **Shiki** | Highlights source code during the build |
| **HTML, CSS and JavaScript** | Handle the interface, navigation, search and copy functionality |
| **Bun** | Installs dependencies and runs project scripts |
| **GitHub Actions** | Validates, builds and deploys the website |
| **GitHub Pages** | Hosts the generated website |

The build produces a `dist/` directory containing static HTML, CSS, JavaScript and other assets.

That generated output is what gets deployed. The deployed website does not need a running server, database or application backend.

## 🚢 Deployment

Deployment is handled through GitHub Actions.

The intended workflow is:

1. Make changes to your programs or documentation.
2. Push your changes to a development branch.
3. Open a pull request targeting `main`.
4. GitHub Actions validates the content, checks the Astro project and builds the website.
5. Once the pull request is merged into `main`, the deployment workflow builds and publishes the website to GitHub Pages.

For the first deployment, GitHub Pages must be configured to use **GitHub Actions** as its deployment source.

See the project documentation for more details about the architecture, workflows and deployment setup.

## 📖 Project Documentation

Additional documentation is available in the `docs/` directory.

comming soon...

---

**The main principle:** Write and maintain your programs in `programs/`. The website is just a generated view of that content.
