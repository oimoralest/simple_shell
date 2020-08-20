
# Simple Shell
Simple Shell is a simple implementation of the UNIX command interpreter project for Holberton school students, where we build and understand how the simple shell command works. The project is to replicate the basic functionality of a LINUX Shell
<img with = "150" src ="https://github.com/oimoralest/simple_shell/blob/master/imag/LOGO.png" />

## Learning Objectives

- Who designed and implemented the original Unix operating system
- Who wrote the first version of the UNIX shell
- Who invented the B programming language (the direct predecessor to the C programming language)
- Who is Ken Thompson
- How does a shell work
- What is a pid and a ppid
- How to manipulate the environment of the current process
- What is the difference between a function and a system call
- How to create processes
- What are the three prototypes of main
- How does the shell use the PATH to find the programs
- How to execute another program with the execve system call
- How to suspend the execution of a process until one of its children terminates
- What is EOF / “end-of-file”?

## Requirements

- All your files will be compiled on Ubuntu 14.04 LTS.
- Your C programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic.
- All your files should end with a new line.
- Your code should use the Betty style.
- No more than 5 functions per file.
- All your header files should be include guarded.
- Use system calls only when you need to.

## Contained files
| FILE | DESCRIPTION FILE |
| --- | --- |
| header.h | contains the prototypes of the functions |
| PATH.c | contain functions search command in the PATH	|
| simple_shell.c | contain Main functions |
| str_tok.c | contain function split buffer and aux |
| _atoi.c | convert string in a number |
| _cd.c | Function change directory |
| _execve.c| execute commnads with fork |
| buffer.c | works in buffer |
| node.c | creates and deletes node |
| set_buffer.c | set buffer with NULL |
| setenv.c | overwrite environment |
| str_cmp.c | function compare string |
| str_cpy.c | function copy stryng |
| str_len.c | function count leng string |
| str_tok.c | function break strings in tokens |
| unsetenv.c | function remove variable environment | 
| free.c | free dinamic memory (malloc) |
| errors.c | Management errors |
| README.md | README file |

# Clone Code

simple_shell is clone in your terminal using the next code

git clone https://github.com/oimoralest/simple_shell.git

## How to Copile the code

gcc -Wall -Wextra -Werror -pedantic *.c -o hsh

## Run the code

./hsh

## Examples to Use
### Basics
SHell reads the entry, it proceeds through many sequence of operations and divide it in words and operators.

```ShellSession
ls -la
```

```ShellSession
vagrant@vagrant-ubuntu-trusty-64:$ ./hsh
$ ls -la
total 176
drwxrwxr-x 3 vagrant vagrant  4096 Mar 22 22:27 .
drwxrwxr-x 4 vagrant vagrant  4096 Mar 22 22:27 ..
drwxrwxr-x 7 vagrant vagrant  4096 Mar 21 21:05 SHELL_TEST
-rwxrwxr-x 1 vagrant vagrant 13986 Mar 22 20:45 a.out
-rw-rw-r-- 1 vagrant vagrant   369 Mar 22 20:47 free_it_all.c
-rw-rw-r-- 1 vagrant vagrant  1179 Mar 22 20:31 helper_functions.c
-rw-rw-r-- 1 vagrant vagrant   815 Mar 22 20:42 holberton.h
-rwxrwxr-x 1 vagrant vagrant 13891 Mar 21 23:20 hsh
-rwxrwxr-x 1 vagrant vagrant  3259 Mar 22 22:27 print_environ.c
-rwxrwxr-x 1 vagrant vagrant  2363 Mar 22 20:18 prompt.c
-rw-rw-r-- 1 vagrant vagrant  1302 Mar 22 20:25 strtok_example.c
$ pwd
/home/vagrant/simple_shell
$ /bin/pwd
/home/vagrant/simple_shell
```

## Authors
OSCAR MORALES &
LUIS CARVAJAL