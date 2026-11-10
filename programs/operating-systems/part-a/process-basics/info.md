---
title: Basic process information
subject: Operating Systems
part: A
category: Processes
language: c
source: program.c
order: 1
tags:
  - process
  - system calls
---

## Question

Write a C program that prints the process ID and parent process ID of the running process.

## How to run

Compile and execute on a POSIX-compatible system:

```bash
gcc program.c -o process-info
./process-info
```

## Sample output

The numeric IDs will differ each time the program runs. A typical output looks like this:

```text
Process ID: 24810
Parent process ID: 24102
```

## Notes

- `getpid()` returns the process ID of the calling process.
- `getppid()` returns the process ID of its parent process.
- These functions are declared in `unistd.h`.
