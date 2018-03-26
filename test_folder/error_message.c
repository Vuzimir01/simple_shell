#include "holberton.h"
/**
 * _putchar - puts a char to the STD
 * @c: character to write out
 *
 * Return: int to print 
 */
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}
/**
 * build_error_message - builds and writes an error message similar to the sh error
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
	
	write(1, av[0], _strlen(av[0]));
	write(1, ": ", 2);

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
			_putchar((count / mul + '0'));
		else
			_putchar((count / mul) % 10 + '0');
		--numlength;
		mul /= 10;
	}
	_putchar(count % 10 + '0');
	write(1, ": ", 2);
	write(1, fir_com, _strlen(fir_com));
	write(1, ": not found\n", 12);
}

