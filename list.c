#include "main.h"

/**
 * add_node_list - adds a new node at the end of a linked list
 * @head: pointer to head
 * @str: string
 *
 * Return: address of the new element, otherwise NULL if it failed
 */
list_t *add_node_list(list_t **head, char *str)
{
	list_t *new;
	list_t *htemp;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	new->str = _strdup(str);
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (*head);
	}

	for (htemp = *head; htemp->next != NULL; htemp = htemp->next)
	{ }

	htemp->next = new;

	return (*head);
}

/**
 * free_list - frees a linked list
 * @head: pointer to head
 */
void free_list(list_t *head)
{
	list_t *htemp;

	while (head != NULL)
	{
		free(head->str);
		htemp = head;
		head = head->next;
		free(htemp);
	}
}
