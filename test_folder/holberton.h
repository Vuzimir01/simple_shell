#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stats.h>

char *_strncpy(char *dest, char *src, int n);
unsigned int _strlen(char *s);
unsigned int find_command_length(char *s);
char **array_from_strtok(char *str);


#endif /* _HOLBERTON_H_ */
