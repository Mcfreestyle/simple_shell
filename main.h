#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <stddef.h>

/**
 * struct built_in - struct built_in
 * @btin: string
 * @f: the function associated
 */
typedef struct built_in
{
	char *btin;
	void (*f)(char *argv[]);
} built_in;

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;

extern char **environ;

void get_input(char *argv[]);
int match(char *argv[]);
void create_process(char *argv[]);
int search_path(char *argv[]);
char *_getenv(char *name);
void free_argv(char *argv[]);
list_t *add_node_list(list_t **head, char *str);
void free_list(list_t *head);

/* function about strings */
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int  _strcmp(char *s1, char *s2);
char *_strdup(char *str);

#endif
