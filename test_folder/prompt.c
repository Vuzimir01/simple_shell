#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	char *buffer;
	size_t bufsize;
	ssize_t characters;
	char *dolla_dolla = "$ ";

	buffer = NULL;
	bufsize = 0;

	write(1, dolla_dolla, 2);
	while ((characters = getline(&buffer, &bufsize, stdin)) != EOF)
	{
			write(1, buffer, characters); 
			write(1, dolla_dolla, 2);
	}
	if (characters == -1)
		return (EXIT_FAILURE);

	free(buffer);	
	return (EXIT_SUCCESS);	
}
