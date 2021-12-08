#include "main.h"

/**
 * create_process - creates a process and execute a program in the process son
 * @argv: contains the input and its flags
 */
void create_process(char *argv[])
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error:");
			_exit(1);
		}
	}
	else
		wait(&status);
}
