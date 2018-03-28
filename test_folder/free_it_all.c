#include "holberton.h"
/**
 * free_all_double_ptr - frees all the memory associated with a double pointer
 * @d_ptr: the double pointer to free
 *
 * Return: void
 */
void free_all_double_ptr(char **d_ptr)
{
	unsigned int i = 0;

	if (d_ptr == NULL)
		return;

	while (d_ptr[i])
	{
		free(d_ptr[i]);
		++i;
	}

	if (d_ptr[i] == NULL)
		free(d_ptr[i]);

	free(d_ptr);
}

