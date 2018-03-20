#include "holberton.h"

int main(void)
{
	char *buffer;
	char **commands, **all_directories;
	size_t length;
	ssize_t characters;
	char *dolla_dolla = "$ ";
	pid_t pid;
	struct stat fileStat;
	int i, status;

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
				/* check if the command is a a $PATH that has an executable */
				if (stat(commands[0], &fileStat) == 0)
					execve(commands[0], commands, NULL);
				/* check all $PATH VARIABLES for executable commands */
				else
				{
					i = 0;
					all_directories = store_env_variables(commands[0]);
					while (all_directories[i])
					{
						if (stat(all_directories[i], &fileStat) == 0)									execve(all_directories[i], commands, NULL);
						++i;
					}
				
					free_all_directories(all_directories);
					/*
					write(1, "No such file or directory\n", 26);
					*/
				}
			}	/* DON'T FORGET TO FREE YOUR MALLOCS FROM THE TOKEN YOU BUILT */
			else
				wait(&status);

			write(1, dolla_dolla, 2);
	}
	if (characters == -1)
		return (EXIT_FAILURE);

	free(buffer);	
	return (EXIT_SUCCESS);	
}
