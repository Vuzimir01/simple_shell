#include "holberton.h"
int _puterror(char c)
{
	return (write(STDERR_FILENO, &c, 1));
}
void build_error_message(char **av, char *fir_com, int count)
{
	int mul, numlength, copy;

	write(STDERR_FILENO, av[0], _strlen(av[0]));
	write(STDERR_FILENO, ": ", 2);

	copy = count;
	mul = 1;
	numlength = 1;
	while (copy >= 10)
	{
		copy /= 10;
		mul *= 10;
		++numlength;
	}
	while (numlength > 1)
	{
		if ((count / mul) < 10)
			_puterror((count / mul + '0'));
		else
			_puterror((count / mul) % 10 + '0');
		--numlength;
		mul /= 10;
	}
	_puterror(count % 10 + '0');
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, fir_com, _strlen(fir_com));
	if (isatty(STDIN_FILENO))
		write(STDERR_FILENO, ": not found\n", 12);
	else
		write(STDERR_FILENO, ": not found", 11);
}
void end_of_file(char *buffer)
{
	write(STDOUT_FILENO, "\n", 1);
	free(buffer);
	exit(0);
}
void fork_fail(void)
{
	perror("Error:");
	exit(EXIT_FAILURE);
}
