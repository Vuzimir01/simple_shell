#include <string.h>
#include <stdio.h>
#include <stdlib.h>
unsigned int _strlen(char *s)
{
	unsigned int counter = 0;
	
	while (s[counter] != '\0')
		++counter;
	
	return (counter);
}

char **array_from_strtok(char *str)
{
	char **res = NULL;
	char *p = strtok(str, " ");
	
	int n_spaces, i;

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
	
	i = 0;
	while (i < (n_spaces + 1))
	{
		printf("res[%d] = %s\n", i, res[i]);
		++i;
	}
	/*
	unsigned int i, length;
	char *token;
	char *token_cage[3];
	char *token_cage_malloc;

	i = 0;
	length = 0;
	token = strtok(str," ");
	token_cage_malloc = malloc(_strlen(token));
	
	while (token != NULL)
	{
		token_cage[i] = token;
		length += _strlen(token);
		printf("Token: %s\tLength: %d\n", token_cage[i], length);
		token = strtok(NULL, " ");
		++i;
	}
	
	printf("Length: %d\n", length);
	*/
	return (res);
}

int main(void)
{
	char holberton[100] = "HOLBERTON SCHOOL ROCKS!";
	char **arrays_string;
	int i;

	arrays_string = array_from_strtok(holberton);
		
	i = 0;
	while (arrays_string[i])
	{
		printf("%s\n", arrays_string[i]);
		++i;
	}
	return (EXIT_SUCCESS);
}
