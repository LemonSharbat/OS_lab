---
title: Basic system information using Bash
subject: Operating Systems
part: B
category: Shell scripting
language: bash
source: program.sh
order: 1
tags:
  - bash
  - system commands
---

## Question

Write a shell script that displays the current user, current working directory and current date.

## How to run

```bash
chmod +x program.sh
./program.sh
```

You can also run it without changing its executable permission:

```bash
bash program.sh
```

## Sample output

```text
Current user: nish
Working directory: /home/nish/lab
Date: Tue Nov 10 12:30:00 IST 2026
```

The values depend on the machine and the time when the script is executed.
