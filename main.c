#include "main.h"

/**
 * handler_error - prints a error message
 * @argv: contains the input and its flags
 * @av: contains the arguments of main
 */
void handler_error(char *argv[], char **av)
{
	int len1, len2;

	len1 = _strlen(av[0]);
	len2 = _strlen(argv[0]);
	write(2, av[0], len1);
	write(2, ": 1: ", 5);
	write(2, argv[0], len2);
	write(2, ": not found\n", 12);
}

/**
 * free_argv - frees the array that contains the input
 * @argv: contains the input and its flags
 */
void free_argv(char *argv[])
{
	int i;

	for (i = 0; *(argv + i); i++)
		free(*(argv + i));
}

/**
 * handler - prints the prompt when receive the SIGINT signal
 * @sig: signal
 */
void handler(__attribute__((unused)) int sig)
{
	write(STDOUT_FILENO, "\n$ ", 3);
}

/**
 * exist_path - verify if PATH exists
 * @argv: contains the input and its flags
 * @av: contains the values of the arguments of main
 *
 * Return: 1 if the PATH exists, otherwise 0
 */
int exist_path(char *argv[], char **av)
{
	char *path;

	path = _getenv("PATH");
	if (path == NULL)
	{
		handler_error(argv, av);
		free_argv(argv);
		return (0);
	}
	free(path);
	return (1);
}

/**
 * main - simulate a shell
 * @ac: number of arguments
 * @av: contains the values of arguments
 *
 * Return: 0
 */
int main(__attribute__((unused)) int ac, char **av)
{
	struct stat st;
	char *argv[100];
	int inte = 1;

	if (isatty(STDIN_FILENO) != 1)
		inte = 0;
	signal(SIGINT, handler);
	while (1)
	{
		if (inte == 1)
			write(STDOUT_FILENO, "$ ", 2);
		get_input(argv);
		if (argv[0] == NULL)
			continue;
		if (_strcmp(argv[0], "\n") == 0)
		{
			free_argv(argv);
			continue;
		}
		if (match(argv) == 1)
		{
			free_argv(argv);
			continue;
		}
		if (exist_path(argv, av) == 0)
			continue;
		if (stat(argv[0], &st) != 0)
		{
			if (search_path(argv) == 0)
			{
				handler_error(argv, av);
				free_argv(argv);
				continue;
			}
		}
		create_process(argv);
		free_argv(argv);
	}
	return (0);
}
