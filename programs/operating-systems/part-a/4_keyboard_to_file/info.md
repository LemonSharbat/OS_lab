---
title: keyboard to file
subject: Operating Systems
part: A
category: System calls
language: c
source: main.c
---

## Question
Write a C program using Unix system calls to open a file for writing (create it if it does not exist). The program should read text from the keyboard and write it into file until Ctrl+D.

## Notes

#### open() flags
```c
open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 0664);
```

- O_CREAT	 -> Create the file if it doesn't exist
- O_WRONLY -> Open for writing only
- O_TRUNC  -> Erase existing contents when opening a regular file for writing
- 0664     -> Permissions used when creating the file

0664 means:
- Owner: read + write (6)
- Group: read + write (6)
- Others: read (4)
