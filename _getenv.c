#include "main.h"

/**
 * _getenv - obtains the value of a environment variable
 * @name: name of the environment variable
 *
 * Return: the value of the environment variable, otherwise NULL
 */
char *_getenv(char *name)
{
	char *environ_var, *token, *value_var;
	int i;

	for (i = 0; *(environ + i); i++)
	{
		environ_var = _strdup(*(environ + i));
		token = strtok(environ_var, "=");
		if (_strcmp(environ_var, name) == 0)
		{
			token = strtok(NULL, "\0");
			value_var = _strdup(token);
			free(environ_var);
			return (value_var);
		}
		free(environ_var);
	}
	return (NULL);
}
