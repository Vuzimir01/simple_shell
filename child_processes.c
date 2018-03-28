#include "holberton.h"
void command_is_null(char *buffer)
{
	free(buffer);
	exit(EXIT_SUCCESS);
}
void exit_out(char *buffer, char **commands)
{
	free(buffer);
	free_all_double_ptr(commands);
	exit(EXIT_SUCCESS);
}
void env_out(char *buffer, char **commands, char **env)
{
	free(buffer);
	free_all_double_ptr(commands);
	print_env(env);
	exit(EXIT_SUCCESS);
}
void parent_free_buff_commands(char *buffer, char **commands)
{
	free(buffer);
	free_all_double_ptr(commands);
}
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

	build_error_message(argv, commands[0], count);

	free(buffer);
	free_all_double_ptr(commands);
	free_all_double_ptr(all_directories);
	exit(EXIT_SUCCESS);
}
