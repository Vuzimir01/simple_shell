#include "holberton.h"

void free_all_double_ptr(char **d_ptr)
{
	unsigned int i = 0;
	while (d_ptr[i])
	{
		/* write(1, d_ptr[i], _strlen(d_ptr[i]));*/
		/*write(1, "FREE\n", 5); */
		free(d_ptr[i]);
		++i;
	}
	if (d_ptr[i] == NULL)
	{
		/*write(1, "NULL", 4); */
		free(d_ptr[i]);
		/* write(1, "FREE\n", 5); */
	}
	if (d_ptr)
	{
		free(d_ptr);
		/* write(1, "Double pointer: FREE\n", 21); */
	}
}	
