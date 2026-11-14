---
title: file to stdout
subject: Operating Systems
part: A
category: System calls
language: c
source: main.c
tags:
  - read
  - open
---

## Question

Write a C program that uses the appropriate Unix system calls to read the contents of a file and display it on the terminal. The program should prompt the user to enter the filename as input from the keyboard.


## Errors

```
# open error
Enter file name: dont-exists
Error opening the file: No such file or directory

# . -> directory. open will succeed but read will fail
Enter file name: .
Error reading the file: Is a directory
```
