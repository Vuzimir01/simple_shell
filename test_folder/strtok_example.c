#include <string.h>
#include <stdio.h>
#include <stdlib.h>
char *_strncpy(char *dest, char *src, int n)
{
	int i;
	
	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	
	for ( ; i < n; i++)
		dest[i] = '\0';
	
	return (dest);
}

unsigned int _strlen(char *s)
{
	unsigned int counter = 0;
	
	while (s[counter] != '\0')
		++counter;
	
	return (counter);
}

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
char **array_from_strtok(char *str)
{
	/*
	char **res = NULL;
	char *p = strtok(str, " ");
	int n_spaces;

	n_spaces = 0;
	while (p)
	{
		res = realloc(res, sizeof(char *) * ++n_spaces);
		if (res == NULL)
			return (NULL);
		
		res[n_spaces - 1] = p;
		p = strtok(NULL, " ");
	}

	res = realloc(res, sizeof(char *) * (n_spaces + 1));
	res[n_spaces] = 0;
	
	return (res);
	*/
	char **token_holder;
	char *token;
	unsigned int length, i;

	length = find_command_length(str);
	token_holder = malloc(sizeof(char *) * (length + 1));
	i = 0;
	token = strtok(str," ");
	while (token != NULL)
	{
		token_holder[i] = malloc(_strlen(token) + 1);
		_strncpy(token_holder[i], token, _strlen(token));
		token = strtok(NULL, " ");
		++i;
	}
	*(token_holder + i) = NULL;
	return (token_holder);
}

int main(void)
{
	char holberton[100] = "  HOLBERTON SCHOOL       ROCKS! ";
	char **commands;
	unsigned int i;

	commands = array_from_strtok(holberton);

	i = 0;
	while (commands[i] != '\0')
	{
		printf("%s\n", commands[i]);
		++i;
	}		
	return (EXIT_SUCCESS);
}
