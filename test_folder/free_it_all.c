#include "holberton.h"

void free_all_double_ptr(char **d_ptr)
{
	unsigned int i = 0;
	while (d_ptr[i])
	{
		free(d_ptr[i]);
		++i;
	}
	
	if (d_ptr[i] == NULL)
		free(d_ptr[i]);

	free(d_ptr);
}	
