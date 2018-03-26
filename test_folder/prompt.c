#include "holberton.h"
/**
 * main - basic shell recreation
 *
 *
 * Return: 0 on exit, 1 if any failures happen
 */
int main(int argc, char **argv, char **env)
{
	char *buffer;
	char **commands, **all_directories;
	size_t length;
	ssize_t characters;
	char *dolla_dolla = "$ ", *exit_command = "exit", *env_command = "env";
	pid_t pid;
	struct stat fileStat, fileStat2;
	int i, status, count;
	(void)argc;

	buffer = NULL, length = 0, count = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, dolla_dolla, 2);

	while ((characters = getline(&buffer, &length, stdin)) != EOF)
	{
		/* 
		 * counting the number of times the prompt 
		 * shows up to display correct error
		 */
		++count;
		commands = array_from_strtok(buffer);
		pid = fork();
		if (pid == -1)
		{
			perror("Error:");
			exit(1);
		}
		if (pid == 0)
		{
			/* check if commands is NULL or all empty spaces */
			if (commands == NULL)
			{
				free(buffer);
				exit(0);
			}
			/* check if the command is a EXIT to exit the shell */
			else if (_strcmp(exit_command, commands[0]))
			{
				free_all_double_ptr(commands);
				free(buffer);
				exit(0);
			}
			/* check if the command is ENV to print out environment variables */
			else if (_strcmp(env_command, commands[0]))
			{
				free(buffer);
				free_all_double_ptr(commands);
				print_env(env);
				exit(0);
			}
			/* check if the command is a $PATH that has an executable */
			else if (stat(commands[0], &fileStat) == 0)
				execve(commands[0], commands, NULL);
			/* check all $PATH VARIABLES for executable commands */
			else
			{
				i = 0;
				all_directories = store_env_variables(commands[0], env);
				while (all_directories[i])
				{
					if (stat(all_directories[i], &fileStat2) == 0)
						execve(all_directories[i], commands, NULL);
					++i;
				}

				build_error_message(argv, commands[0], count);
				/*write(1, "No such file or directory\n", 26);*/
				free(buffer);
				free_all_double_ptr(commands);
				free_all_double_ptr(all_directories);
				exit(0);
			}
		}
		/* DON'T FORGET TO FREE YOUR MALLOCS FROM THE TOKEN YOU BUILT */
		else
		{
			wait(&status);

			if (commands == NULL)
			{
				free(buffer);
				free_all_double_ptr(commands);
			}
			else if (_strcmp(exit_command, commands[0]))
			{
				free(buffer);
				free_all_double_ptr(commands);
				exit(0);
			}
			else if (commands != NULL)
			{
				free_all_double_ptr(commands);
				free(buffer);
			}
		}
		length = 0;
		buffer = NULL;

		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, dolla_dolla, 2);
	}
	if (characters == -1)
		return (EXIT_FAILURE);

	free(buffer);
	return (EXIT_SUCCESS);
}
