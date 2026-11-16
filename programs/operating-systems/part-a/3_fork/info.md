---
title: fork
subject: Operating Systems
part: A
category: System calls
language: c
source: main.c
tags:
  - fork
  - process creation
---

## Question
Write the program to create five Child Processes using system call fork() and display their ids.

## Output

```
Parent Process ID: 225364
--------------------------------
child: 1 | PID: 225365 | Parent PID: 225364
child: 2 | PID: 225366 | Parent PID: 225364
child: 3 | PID: 225367 | Parent PID: 225364
child: 4 | PID: 225368 | Parent PID: 225364
child: 5 | PID: 225369 | Parent PID: 225364
--------------------------------
Parent: All children have terminated.
```
