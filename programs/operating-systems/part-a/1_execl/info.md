---
title: execl
subject: Operating Systems
part: A
category: Library functions
language: c
source: main.c
---

## Question

Write a C program using the execl() system call that:
  i. Reads the name of a shell script from the keyboard.
  ii. Executes that script using /bin/sh.
  iii. Displays an appropriate error message if the script cannot be found or executed.
  iv. The shell script should prompt the user to enter three numbers, find and display the greatest of the three numbers.


## shell program

```sh
echo "Enter three numbers: "

read a
read b
read c

if [ $a -gt $b ] && [ $a -gt $c ]; then
	echo "$a is greatest"
elif [ $b -gt $c ] && [ $b -gt $a ]; then
	echo "$b is greatest"
else
	echo "$c is greatest"
fi
```
