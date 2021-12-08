#include "main.h"

/**
 * _strlen - calculate the length of a string
 * @s: pointer to a char
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int count, len;

	len = 0;

	for (count = 0; s[count] != '\0'; count++)
		len++;
	return (len);
}

/**
 * _strcpy - copies the pointed string to the pointed buffer
 * @dest: string destiny
 * @src: string source
 *
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int len, i;

	len = _strlen(src);

	for (i = 0; i < len + 1; i++)
		dest[i] = src[i];
	return (dest);
}

/**
 * _strcat - concatenates two strings
 * @dest: first pointer to character
 * @src: second pointer to character
 *
 * Return: pointer to the dest
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	while (*(dest + i))
		i++;

	while (*(src + j))
	{
		*(dest + i) = *(src + j);
		i++;
		j++;
	}
	*(dest + i) = '\0';
	return (dest);
}

/**
 * _strcmp - compares 2 strings
 * @s1: first string
 * @s2: second string
 *
 * Return: 0 if they are equal, otherwise the diference
 */
int  _strcmp(char *s1, char *s2)
{

	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}

/**
 * _strdup - copies the string to a newly allocated memory
 * @str: pointer to dynamic memory
 *
 * Return: NULL if the string is null or there is insufficient memory,
 *	otherwise the pointer to the dynamic memory
 */
char *_strdup(char *str)
{
	int i, size;
	char *str1;

	if (str == NULL)
		return (NULL);

	size = 0;
	while (*(str + size))
		size++;
	str1 = malloc(size + 1);

	i = 0;
	if (str1 == NULL)
		return (NULL);
	while (*(str + i))
	{
		*(str1 + i) = *(str + i);
		i++;
	}
	*(str1 + i) = '\0';
	return (str1);
}
