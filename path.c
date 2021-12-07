#include "main.h"

/**
 * look_file - looks a file using its absolute path
 * @head: head of linked list
 *
 * Return: the absolute path of a file if it's founded, otherwise NULL
 */
char *look_file(list_t *head)
{
	char *file;
	struct stat st;

	for (; head != NULL; head = head->next)
	{
		if (stat(head->str, &st) == 0)
		{
			file = _strdup(head->str);
			break;
		}
	}
	if (head == NULL)
		return (NULL);
	return (file);
}

/**
 * concat_dir - concatenates the command with the directories of the path
 * @node: head of the linked list
 * @command: entered command in the input
 */
void concat_dir(list_t *node, char *command)
{
	char *buff_dir, *dir_path;

	while (node)
	{
		buff_dir = malloc(100);
		if (buff_dir == NULL)
			exit(97);
		dir_path = _strcpy(buff_dir, node->str);
		free(node->str);
		node->str = _strcat(dir_path, "/");
		node->str = _strcat(dir_path, command);

		node = node->next;
	}
}

/**
 * search_path - searches the entered command in the path
 * @argv: contains the input and its flags
 *
 * Return: 1 if the command is founded, otherwise 0
 */
int search_path(char *argv[])
{
	char *path, *token, *cmd;
	list_t *head = NULL;

	path = _getenv("PATH");

	token = strtok(path, ":");
	while (token)
	{
		add_node_list(&head, token);
		token = strtok(NULL, ":");
	}
	free(path);
	concat_dir(head, argv[0]);
	cmd = _strdup(argv[0]);
	free(argv[0]);
	argv[0] = look_file(head);
	free_list(head);
	if (argv[0] == NULL)
	{
		argv[0] = cmd;
		return (0);
	}
	free(cmd);
	return (1);
}
