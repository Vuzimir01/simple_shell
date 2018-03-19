#include "holberton.h"

int main(void)
{
	char *buffer;
	char **commands;
	size_t length;
	ssize_t characters;
	char *dolla_dolla = "$ ";
	pid_t pid;
	struct stat fileStat;

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
			{	
				if (stat(commands[0], &fileStat) == 0)
					execve(commands[0], commands, NULL);
				else
					write(1, "No such file or directory\n", 26); 		
			}	/* DON'T FORGET TO FREE YOUR MALLOCS FROM THE TOKEN YOU BUILT */
			else
				wait(NULL);
			write(1, dolla_dolla, 2);
	}
	if (characters == -1)
		return (EXIT_FAILURE);

	free(buffer);	
	return (EXIT_SUCCESS);	
}
