#include "holberton.h"
/**
 * find_command_length - finds the number of commands in the string
 * @s: the string to find the commands
 *
 * Return: number of commands, unsigned int
 */
unsigned int find_command_length(char *s)
{
	unsigned int commands, i, flag;

	flag = 0;
	commands = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != ' ')
			flag = 1;

		if ((flag && s[i + 1] == ' ') || (flag && s[i + 1] == '\0'))
		{
			++commands;
			flag = 0;
		}
		++i;
	}
	return (commands);
}
/**
 * array_from_strtok - creates a double pointer array that holders pointers
 * to each string from the command line
 * @str: the commands from the terminal when you type them to the standard
 * input
 *
 * Return: double pointer array of pointers that are commands to interpret
 * and execute
 */
char **array_from_strtok(char *str)
{
	char **token_holder;
	char *token;
	unsigned int length;
	int i;

	/* replace '\n' added by getline with '\0'*/
	str[_strlen(str) - 1] = '\0';
	length = find_command_length(str);
	if (length == 0)
		return (NULL);

	/* +1 accounts for NULL token that will be added */
	token_holder = malloc((sizeof(char *)) * (length + 1));
	if (token_holder == NULL)
		return (NULL);
	i = 0;
	token = strtok(str, " ");
	while (token != NULL)
	{
		token_holder[i] = malloc(_strlen(token) + 1);
		if (token_holder[i] == NULL)
		{
			free_all_double_ptr(token_holder);
			return (NULL);
		}
		_strncpy(token_holder[i], token, _strlen(token) + 1);
		token = strtok(NULL, " ");
		++i;
	}
	token_holder[i] = NULL;
	return (token_holder);
}
