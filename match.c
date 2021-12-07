#include "main.h"

/**
 * my_exit - exits the shell
 * @argv: contains the input and its flags
 */
void my_exit(char *argv[])
{
	free_argv(argv);
	exit(1);
}

/**
 * _env - prints the environment variables
 * @argv: contains the input and its flags
 */
void _env(__attribute__((unused)) char *argv[])
{
	int i, len;

	for (i = 0; *(environ + i); i++)
	{
		len = _strlen(*(environ + i));
		write(1, *(environ + i), len);
		write(1, "\n", 1);
	}
}

/**
 * match - match the command with the built-in command
 * @argv: contains the input and its flags
 *
 * Return: 1 if the match is success, otherwise 0
 */
int match(char *argv[])
{
	built_in b[] = {
		{"exit", my_exit},
		{"env", _env},
		{NULL, NULL}
	};
	int i;

	for (i = 0; b[i].btin; i++)
	{
		if (_strcmp(argv[0], b[i].btin) == 0)
		{
			(b[i].f)(argv);
			return (1);
		}
	}
	return (0);
}
