#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *buffer;
	size_t bufsize = 32;
	size_t characters;

	buffer = malloc(bufsize * sizeof(char));
	if (buffer == NULL)
		return (EXIT_FAILURE);
	
	printf("$ ");
	characters = getline(&buffer, &bufsize, stdin);
	(void)characters;	
	/*
	 not sure how to compare signed size_t to -1 to check if getline fails
	if (characters == -1)
		return (EXIT_FAILURE);
	*/
	printf("%s", buffer);
	free(buffer);
	return (EXIT_SUCCESS);	
}
