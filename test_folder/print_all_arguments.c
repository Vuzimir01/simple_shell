#include <stdio.h>

int main(int argc, char **argv)
{
	unsigned int i;
	(void)argc;

	/*find all the arguments in the argv pointer */
	i = 0;
	while (*(argv + i))
	{
		printf("%s ", argv[i]);
		++i;
	}
	printf("\n");
	return (0);
}
