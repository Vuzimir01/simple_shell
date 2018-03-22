SIMPLE SHELL
============

Simple Shell is a end of semester project for students at [Holberton](https://www.holbertonschool.com/) where we explore, understand and build a working functional simple shell program.

## Audience

Simple Shell is intended for engineers and computer science enthusiasts looking to learn basic source code that supports implementation of a shell program. It's not for people looking for a commercially supported shell, but for people who want to install and play with a simple shell.

## Environment
Simple Shell was built and tested in the Ubuntu 14.04 LTS via Vagrant in VirtualBox and compiled with GCC version 4.8.4

## Respository Contents
Simple Shell files:

| **File** | **Description** |
|----------|-----------------|
| prompt.c | Contains the int main(void) function, entry point |
| strtok_example.c | Contains function that store commands in double pointer: **find_command_length**, **array_form_strtok functions** |
| helper_function.c | Contains all helper functions: **_strncpy**,**_strlen_const**, **_strcmp**,**_strlen** |
| environment.c | Contains all functions that handle environment/path: **find_semis**, **store_env_variables**, **_getenv**, **_strncpycmd**, **print_env** |
| free_it_all.c | Contains function that frees memory: **print_env** |

## How to Install
Clone the repo below
```
https://github.com/nickolasteixeira/simple_shell.git
```

## How to Compile
```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```

## Example Output
```
vagrant@vagrant-ubuntu-trusty-64:$ ./hsh
$ pwd
/home/vagrant/simple_shell
$ /bin/pwd
/home/vagrant/simple_shell
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
```
## Example Video
[![simpleshell](https://i.ytimg.com/vi/qtsAFMF0wRc/hqdefault.jpg)](https://www.youtube.com/embed/qtsAFMF0wRc?autoplay=1 "simpleshell")

## To do
TBD

## Authors
* [**Amy Galles**](https://github.com/AmyLGalles)
* [**Nickolas Teixeira**](https://github.com/NickolasTeixiera)

-----

Legal
=====

Use and transfer of Simple Shell may be subject to certain restrictions
by the United States and other governments.

It's your responsibility to ensure that you use and/or transfer does not
violate applicable laws.

For more information, please see http://www.bis.doc.gov

Licensing
=========
Simple Shell is licensed under the MIT License. 
