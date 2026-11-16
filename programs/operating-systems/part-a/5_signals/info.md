---
title: signals
subject: Operating Systems
part: A
category: signals
language: c
source: main.c
---

## Question
Write a C program that registers a signal handler for SIGINT, SIGTERM, SIGHUP, SIGALRM, and SIGUSR1. The handler should receive each signal and perform some operation.

## Notes

A **signal** is an asynchronous notification delivered to a process to inform it that a particular event has occurred or that it should perform a particular action.

| Signal                                | How?              | Default Action              |
| ------------------------------------- | ----------------- | --------------------------- |
| `SIGINT` (**Signal Interrupt**)       | `Ctrl + C`        | Terminate process           |
| `SIGTERM` (**Signal Terminate**)      | `kill -TERM 1234` | Terminate process           |
| `SIGHUP` (**Signal Hangup**)          | `kill -HUP 1234`  | termination                 |
| `SIGALRM` (**Signal Alarm**)          | `signal(3)`       | Timer notification          |
| `SIGUSR1` (**User-Defined Signal 1**) | `kill -USR1 5678` | Custom process notification |


```sh
# find pid of currect program
pgrep main
# or
ps -aux | grep main
```
