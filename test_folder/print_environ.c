#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int _strcmp(char *s1, char *s2);
extern char **environ;
char *_getenv(const char *name);

unsigned int _strlen(char *s)
{
	unsigned int counter = 0;
	while (s[counter])
		++counter;
	return (counter);
}
unsigned int _strlen_const(const char *name)
{
	unsigned int i = 0;
	while (name[i])
		++i;
	return (i);
}

unsigned int find_semis(char *path)
{
	unsigned int semis, i;

	i = 0;
	semis = 1;
	while (path[i])
	{
		if (path[i] == ':')
			++semis;
		++i;
	}
	return (semis);
}

char *_strncpy(char *dest, char *src, int n)
{
	int i;
	
	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	for ( ; i < n; i++)
		dest[i] = '\0';

	return (dest);
}
void print_env(const char *name)
{
	char **all_directories;
	char *path_env, *directory;
	unsigned int length, i;
	path_env = _getenv(name);
	
	length = find_semis(path_env);
	all_directories = malloc(sizeof(char *) * (length + 1));

	i = 0;
	directory = strtok(path_env, ":");
	while (directory != NULL)
	{
		all_directories[i] = malloc(_strlen(directory) + 1);
		_strncpy(all_directories[i], directory, _strlen(directory));	
		++i;
		directory = strtok(NULL, ":");
	}
	all_directories[i] = NULL;
}

char *_getenv(const char *name)
{
	extern char **environ;
	char *env_value;
	char *name_copy;
	unsigned int i, length;

	/* find the length of the argument, then malloc space for it */	
	length = _strlen_const(name);
	name_copy = malloc((sizeof(char) * length) + 1);
	
	/* copy the contents of the name argument to the new variable, name_copy */
	i = 0;
	while (name[i])
	{
		name_copy[i] = name[i];	
		++i;
	}
	name_copy[i] = '\0';
	
	/*find the enviroment variable that matches the name_copy variable, assign the value to the value variable and return the address */
	i = 0;
	env_value = strtok(environ[i], "=");
	while (environ[i])
	{
		if (_strcmp(env_value, name_copy))
		{
			env_value = strtok(NULL, "\n");
			free(name_copy);
			return (env_value);
		}
		++i;
		env_value = strtok(environ[i], "=");
	}

	free(name_copy);
	return (NULL);
}

int _strcmp(char *s1, char *s2)
{
	unsigned int i = 0;

	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (0);
		++i;
	}

	return (1);
}

int main(void)
{
	print_env("PATH");
	return (0);
}
