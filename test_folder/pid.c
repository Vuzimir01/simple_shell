#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(void)
{
	int my_pid;
	/*	
	my_pid = getpid();
	parent_pid = getppid();
	printf("PID: %u\n", my_pid);
	printf("PARENT: %u\n", parent_pid);
	*/
	my_pid = fork();
	if (my_pid == 0)
	{
		exit(0);
	}

	printf("%d\n", my_pid);
	return (0);
}
