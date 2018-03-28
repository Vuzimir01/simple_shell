#include "holberton.h"
/**
 * find_semis - finds the total number of directories in your path
 * @path: the path string
 *
 * Return: number of directories in the path
 */
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
/**
 * _strncpycmd - copies paths and appens a / + command to each path
 * @dest: destination
 * @src: source
 * @command: command to append
 * @n: length of the destination
 * @c: length of the command
 *
 * Return: destination address
 */
char *_strncpycmd(char *dest, char *src, char *command, int n, int c)
{
	int i, j;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	/* appends "/" + "command" to the src */
	dest[i] = '/';
	i++;
	for (j = 0; j < c && command[j] != '\0'; j++, i++)
		dest[i] = command[j];

	dest[i] = '\0';

	return (dest);
}
/**
 * store_env_variables - creates a double pointer array,
 * where it stores each path directory as a single pointer, NULL terminated
 * @fir_com: first command that you type in the prompt
 * @environ: the environment variables
 *
 * Return: memory address of the double pointer array
 */
char **store_env_variables(char *fir_com, char **environ)
{
	/* fir_com is the first command from the shell */
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
		/* add 2 to malloc for \0 and extra "/" for the slash to append ls */
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
/**
 * _getenv - gets the environment variable value
 * @name: name of the environment vaariable you are looking for
 * @environ: the enviroment variables
 *
 * Return: the value associated with the variable
 */
char *_getenv(const char *name, char **environ)
{
	char *env_value;
	char *name_copy;
	unsigned int i, length;

	/* find the length of the argument, then malloc space for it */
	length = _strlen_const(name);
	name_copy = malloc((sizeof(char) * length) + 1);
	if (name_copy == NULL)
		return (NULL);
	/* copy the contents of the name argument to the new variable, name_copy */
	_strncpyconst(name_copy, name, length);
	/*
	 * find the enviroment variable that matches the name_copy variable
	 * assign the value to the value variable and return the address
	 */
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

/**
 * print_env - prints all of the environment variables to the output
 * @environ: all environment variables for the user
 *
 * Return: void
 */
void print_env(char **environ)
{
	unsigned int i, length;

	i = 0;
	while (environ[i])
	{
		/* find the length of each env variable */
		length = _strlen(environ[i]);
		/* write it out the the stdout */
		write(STDOUT_FILENO, environ[i], length);
		write(STDOUT_FILENO, "\n", 1);
		++i;
	}
}
