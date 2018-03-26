#include "holberton.h"
/**
 * _strcmp - compares two strings for equality
 * @s1: string 1
 * @s2: string 2
 *
 * Return: 1 if equal, 0 if not equal
 */
int _strcmp(char *s1, char *s2)
{
	unsigned int i = 0;

	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (0);
		++i;
	}

	return (1);
}
/**
 * _strlen_const - finds the length of a constant string
 * @name: string to find length of
 *
 * Return: length of the constant string
 */
unsigned int _strlen_const(const char *name)
{
	unsigned int i = 0;

	while (name[i])
		++i;
	return (i);
}
/**
 * _strlen - finds the length of a string
 * @s: string to find the length of
 *
 * Return: unsigned int length of the string
 */
unsigned int _strlen(char *s)
{
	unsigned int counter = 0;

	while (s[counter] != '\0')
		++counter;

	return (counter);
}
/**
 * _strncpy - copies ones string to another string in memory
 * @dest: destination string to copy from
 * @src: string to copy to
 * @n: the length to copy
 *
 * Return: the dest memory address
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];

	for ( ; i < n; i++)
		dest[i] = '\0';

	return (dest);
}
/**
 * _strncpyconst - copies one constant string to another string
 * @dest: destination string to copy from
 * @src: string to copy to
 * @n: the length to copy
 *
 * Return: the dest memory address
 */
char *_strncpyconst(char *dest, const char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];

	for ( ; i < n; i++)
		dest[i] = '\0';

	return (dest);
}
