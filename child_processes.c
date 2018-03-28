#include "holberton.h"
/**
 * command_is_null - frees the buffer we create when the double ptr command
 * returned null
 * @buffer: the buffer we created from getline
 *
 * Return: void
 */
void command_is_null(char *buffer)
{
	free(buffer);
	exit(EXIT_SUCCESS);
}
/**
 * exit_out - frees the buffer and commands we created from the
 * getline function, then exits child process
 * @buffer: buffer we created from getline
 * @commands: double pointer array we created to store all commands
 * from the prompt
 *
 * Return: void
 */
void exit_out(char *buffer, char **commands)
{
	free(buffer);
	free_all_double_ptr(commands);
	exit(EXIT_SUCCESS);
}

/**
 * env_out - frees the buffer and commands we created from the
 * getline function, prints the env, then exits child process
 * @buffer: buffer we created from getline
 * @commands: double pointer array we created to store all commands
 * from the prompt
 * @env: environment variables from your login
 *
 * Return: void
 */
void env_out(char *buffer, char **commands, char **env)
{
	free(buffer);
	free_all_double_ptr(commands);
	print_env(env);
	exit(EXIT_SUCCESS);
}
/**
 * parent_free_buff_commands - frees buffer and commands you created
 * with the getline function from the prompt
 * @buffer: buffer we created from getline
 * @commands: double pointer array we created to store all commands
 * from the prompt
 *
 * Return: void
 */
void parent_free_buff_commands(char *buffer, char **commands)
{
	free(buffer);
	free_all_double_ptr(commands);
}

/**
 * c_path - creates a double ptr array of all your directories
 * from your $PATH variable, checks if the first command you
 * entered is a executable in all your directories, then executes.
 * If not found, prints out an error message, then frees buffer and
 * commands you created with the getline function from the prompt
 * @buffer: buffer we created from getline
 * @commands: double pointer array we created to store all commands
 * from the prompt
 * @env: environment variables from your login
 * @argv: argument vector from int main
 * @count: number of times you've entered commands to the prompt
 *
 * Return: void
 */
void c_path(char **commands, char *buffer, char **env, char **argv, int count)
{
	struct stat fileStat2;
	int i;
	char **all_directories;

	i = 0;
	all_directories = store_env_variables(commands[0], env);
	while (all_directories[i])
	{
		if (stat(all_directories[i], &fileStat2) == 0)
			execve(all_directories[i], commands, NULL);
		++i;
	}

	/* if no command found, print error message */
	build_error_message(argv, commands[0], count);

	free(buffer);
	free_all_double_ptr(commands);
	free_all_double_ptr(all_directories);
	exit(EXIT_SUCCESS);
}
