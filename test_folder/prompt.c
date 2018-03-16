#include "holberton.h"

int main(void)
{
	char *buffer;
	char **commands;
	size_t length;
	ssize_t characters;
	char *dolla_dolla = "$ ";
	pid_t pid;
	
	buffer = NULL;
	length = 0;

	write(1, dolla_dolla, 2);
	while ((characters = getline(&buffer, &length, stdin)) != EOF)
	{
			commands = array_from_strtok(buffer);
			pid = fork();
			if (pid == -1)
			{
				perror("Error:");
				return (1);
			}
			if (pid == 0)
				execve(commands[0], commands, NULL);
			else
				wait(NULL);
			write(1, dolla_dolla, 2);
	}
	if (characters == -1)
		return (EXIT_FAILURE);

	free(buffer);	
	return (EXIT_SUCCESS);	
}
