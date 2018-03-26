#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

/* strtok_example.c */
unsigned int find_command_length(char *s);
char **array_from_strtok(char *str);

/* helperfunctions.c */
char *_strncpy(char *dest, char *src, int n);
unsigned int _strlen_const(const char *name);
int _strcmp(char *s1, char *s2);
unsigned int _strlen(char *s);

/* print_environ.c */
unsigned int find_semis(char *path);
char **store_env_variables(char *fir_com);
char *_getenv(const char *name);
char *_strncpycmd(char *dest, char *src, char *command, int n, int c);
void print_env(char **environ);

/*free_it_all.c */
void free_all_double_ptr(char **d_ptr);
#endif /* _HOLBERTON_H_ */
