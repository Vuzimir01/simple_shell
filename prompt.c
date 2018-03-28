#include "holberton.h"
/**
 * INThandler - handles signals and write the prompt
 * @sig: signal to handle
 *
 * Return: void
 */
void INThandler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n$ ", 3);
}

/**
 * main - basic shell recreation
 * @argc: argument count
 * @argv: argument vector
 * @env: environment variables
 *
 * Return: 0 on exit, 1 if any failures happen
 */
int main(int argc, char **argv, char **env)
{
	char *buffer; char **commands;
	size_t length; ssize_t characters;
	char *dolla_dolla = "$ ", *exit_command = "exit", *env_command = "env";
	pid_t pid; struct stat fileStat;
	int status, count;
	(void)argc;

	buffer = NULL, length = 0, count = 0;
	/* write prompt only if it's from standard input */
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, dolla_dolla, 2);
	/*signal kill for ctrl + c */
	signal(SIGINT, INThandler);
	/* while loop contining forever */
	while ((characters = getline(&buffer, &length, stdin)))
	{
		/* checks for end of file */
		if (characters == EOF)
			end_of_file(buffer);
		/*
		 * counting the number of times the prompt
		 * shows up to display correct error
		 */
		++count;
		/* collects commands from prompt and store in a double pointer array */
		commands = array_from_strtok(buffer);
		/*create a new process */
		pid = fork();
		if (pid == -1)
			fork_fail();
		if (pid == 0)
		{
			/* check if commands is NULL or all empty spaces */
			if (commands == NULL)
				command_is_null(buffer);
			/* check if the command is an EXIT to exit the shell */
			else if (_strcmp(exit_command, commands[0]))
				exit_out(buffer, commands);
			/* check if the command is ENV to print out environment variables */
			else if (_strcmp(env_command, commands[0]))
				env_out(buffer, commands, env);
			/* check if the command is a full path to an executable file */
			else if (stat(commands[0], &fileStat) == 0)
				execve(commands[0], commands, NULL);
			/* check all $PATH directories for executable commands */
			else
				c_path(commands, buffer, env, argv, count);
		}
		/* DON'T FORGET TO FREE YOUR MALLOCS FROM THE TOKEN YOU BUILT */
		else
		{
			/* wait for the child process to finish first */
			wait(&status);
			if (commands == NULL)
				parent_free_buff_commands(buffer, commands);
			/* if exit, free buffer and commands, then exit program */
			else if (_strcmp(exit_command, commands[0]))
				exit_out(buffer, commands);
			/*free buffer and commands double ptr from parent process */
			else
				parent_free_buff_commands(buffer, commands);
		}
		/* reset length and buffer for getline funciton */
		length = 0; buffer = NULL;
		/* write outs prompt only if from standard input */
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, dolla_dolla, 2);
	}
	if (characters == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
