#include "main.h"


/**
 * splitstring - splits a string and makes it an array of 
 * pointers to a specific words
 * @str: string to be split
 * @delim: the delimiter
 * Return: array
 */

char **splitstring(char *str, const char *delim)
{
int i, wn;
char **array;
char *token;
char *copy;
copy = malloc(_strlen(str) + 1);
if (copy == NULL)
{
perror(_getenv("_"));
return (NULL);
}
i = 0;
while (str[i])
{
copy[i] = str[i];
i++;
}
copy[i] = '\0';
token = strtok(copy, delim);
array = malloc((sizeof(char *) * 2));
array[0] = _strdup(token);
i = 1;
wn = 3;
while (token)
{
token = strtok(NULL, delim);
array = _realloc(array, (sizeof(char *) * (wn - 1)), (sizeof(char *) * wn));
array[i] = _strdup(token);
i++;
wn++;
}
free(copy);
return (array);
}

/**
 * execute - executes a command
 * @argv: array of arguments
 */

void execute(char **argv)
{

int d, status;

if (!argv || !argv[0])
return;
d = fork();
if (d == -1)
{
perror(_getenv("_"));
}
if (d == 0)
{
execve(argv[0], argv, environ);
perror(argv[0]);
exit(EXIT_FAILURE);
}
wait(&status);
}