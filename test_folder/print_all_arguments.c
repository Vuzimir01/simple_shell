#include <stdio.h>
#include <unistd.h>
unsigned int _strlen(char *s)
{
	unsigned int counter = 0;
	
	while (s[counter] != '\0')
		++counter;

	return (counter);
}

int main(int argc, char **argv)
{
	unsigned int i, length;
	(void)argc;

	/*find all the arguments in the argv pointer */
	i = 0;
	length = 0;
	while (*(argv + i))
	{
		length = _strlen(argv[i]);
		write(1, argv[i], length);
		++i;
	}
	return (0);
}
