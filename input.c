#include "main.h"

/**
 * get_input - gets the input and store it into array
 * @argv : array that will has the input
 */
void get_input(char *argv[])
{
	char *buff = NULL;
	char *token;
	size_t sizbuff = 0;
	int i, input;

	input = getline(&buff, &sizbuff, stdin);
	if (input == EOF)
	{
		free(buff);
		exit(EXIT_SUCCESS);
	}
	token = strtok(buff, " ");
	for (i = 0; token != NULL; i++)
	{
		argv[i] = _strdup(token);
		token = strtok(NULL, " ");
	}
	if (_strcmp(argv[i - 1], "\n") != 0)
	{
		strtok(argv[i - 1], "\n");
		argv[i] = NULL;
	}
	else
	{
		free(argv[i - 1]);
		argv[i - 1] = NULL;
	}
	free(buff);
}
