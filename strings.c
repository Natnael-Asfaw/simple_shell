#include "main.h"

/**
 * _strlen - Sizes the length of a string
 * @string: String to be sized
 * Return: The length ot the string
 */

int _strlen(const char *string)

{
	int length = 0;

	if (string == NULL)
		return (0);
	while (string[length] != '\0')
		length++;
	return (length);
}


/**
 * _strdup - Duplicates a string
 * @str: String to be duplicated
 * Return: Pointer to the duplicated string
 */

char *_strdup(char *str)

{
	unsigned int i, len;
	char *duplicate;

	if (str == NULL)
		return (NULL);
	for (len = 0; str[len] != '\0'; len++)
		;
	duplicate = (char *) malloc(sizeof(char) * (len + 1));
	if (duplicate == NULL)
		return (NULL);
	for (i = 0; i <= len; i++)
	{
		duplicate[i] = str[i];
	}
	return (duplicate);
}


/**
 * _strcmp - Compares two strings
 * @str1: String to be compared
 * @str2: String to be compared
 * Return: 0 if are the same, > 0 if str1 is greater, < 0 if str2 is greater
 */

int _strcmp(char *str1, char *str2)

{
	int a;

	for (a = 0; str1[a] != '\0'; a++)
		;
	for (a = 0; str2[a] != '\0'; a++)
	{
		if (str1[a] != str2[a])
		{
			return (str1[a] - str2[a]);
		}
	}
	return (0);
}
