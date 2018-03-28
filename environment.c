#include "holberton.h"
unsigned int find_semis(char *path)
{
	unsigned int semis, i, flag;

	i = 0, semis = 0, flag = 0;
	while (path[i])
	{
		if (path[i] != ':')
			flag = 1;

		if ((flag && path[i + 1] == ':') || (flag && path[i + 1] == '\0'))
		{
			++semis;
			flag = 0;
		}
		++i;
	}
	return (semis);
}
char *_strncpycmd(char *dest, char *src, char *command, int n, int c)
{
	int i, j;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '/';
	i++;
	for (j = 0; j < c && command[j] != '\0'; j++, i++)
		dest[i] = command[j];

	dest[i] = '\0';

	return (dest);
}
char **store_env_variables(char *fir_com, char **environ)
{
	char **all_directories;
	char *path_env, *directory;
	unsigned int length, i;
	int dir_length, com_length;

	path_env = _getenv("PATH", environ);
	length = find_semis(path_env);
	all_directories = malloc(sizeof(char *) * (length + 1));
	if (all_directories == NULL)
		return (NULL);

	i = 0;
	directory = strtok(path_env, ":");
	while (directory != NULL)
	{
		dir_length = _strlen(directory);
		com_length = _strlen(fir_com);
		all_directories[i] = malloc(sizeof(char) * (dir_length + com_length + 2));
		if (all_directories[i] == NULL)
		{
			free_all_double_ptr(all_directories);
			return (NULL);
		}
		_strncpycmd(all_directories[i], directory, fir_com, dir_length, com_length);
		++i;
		directory = strtok(NULL, ":");
	}
	all_directories[i] = NULL;

	return (all_directories);
}
char *_getenv(const char *name, char **environ)
{
	char *env_value;
	char *name_copy;
	unsigned int i, length;

	length = _strlen_const(name);
	name_copy = malloc((sizeof(char) * length) + 1);
	if (name_copy == NULL)
		return (NULL);
	_strncpyconst(name_copy, name, length);
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

void print_env(char **environ)
{
	unsigned int i, length;

	i = 0;
	while (environ[i])
	{
		length = _strlen(environ[i]);
		write(STDOUT_FILENO, environ[i], length);
		write(STDOUT_FILENO, "\n", 1);
		++i;
	}
}
