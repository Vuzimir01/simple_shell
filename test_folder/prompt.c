#include "holberton.h"

int main(void)
{
	char *buffer;
	char **commands;
	size_t length;
	ssize_t characters;
	char *dolla_dolla = "$ ";
	pid_t pid;
	
	(void)pid;
	buffer = NULL;
	length = 0;

	write(1, dolla_dolla, 2);
	while ((characters = getline(&buffer, &length, stdin)) != EOF)
	{
			commands = array_from_strtok(buffer);
			execve(commands[0], commands, NULL);
			/*
			i = 0;
			while (commands[i])
			{
				printf("%s\n", commands[i]);
				++i;
			}
			*/
			/*write(1, buffer, characters);*/ 
			write(1, dolla_dolla, 2);
	}
	if (characters == -1)
		return (EXIT_FAILURE);

	free(buffer);	
	return (EXIT_SUCCESS);	
}
