#include "holberton.h"
/**
 * _puterror - puts a char to the STD
 * @c: character to write out
 *
 * Return: int to print
 */
int _puterror(char c)
{
	return (write(STDERR_FILENO, &c, 1));
}
/**
 * build_error_message - writes an error message similar to the sh error
 * when command not found
 * @av: the argv from the int main function
 * @fir_com: first command to print if not found
 * @count: the number of times you've done a command
 *
 * Return: void
 */
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
	write(STDERR_FILENO, ": not found\n", 12);
}
/**
 * end_of_file - function to handle ctrl+c interrupt signal
 * writes a new line, then frees the buffer from getline
 * @buffer: buffer array created by new line
 *
 * Return: void
 */
void end_of_file(char *buffer)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(buffer);
	exit(0);
}
/**
 * fork_fail - function that handles a fork fail
 *
 * Return: void
 */
void fork_fail(void)
{
	perror("Error:");
	exit(EXIT_FAILURE);
}
