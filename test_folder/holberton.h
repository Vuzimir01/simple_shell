#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>


char *_strncpy(char *dest, char *src, int n);
unsigned int _strlen(char *s);
unsigned int find_command_length(char *s);
char **array_from_strtok(char *str);

unsigned int _strlen_const(const char *name);
unsigned int find_semis(char *path);
char **store_env_variables(char *first_command);
char *_getenv(const char *name);
int _strcmp(char *s1, char *s2);
char *_strncpycmd(char *dest, char *src, char *command, unsigned int n, unsigned int c);
void print_env(void);

void free_all_double_ptr(char **d_ptr);
#endif /* _HOLBERTON_H_ */
