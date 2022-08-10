#include "main.h"

/**
 * exitt - exits the shell
 * @arv: array of words that are entered in the line
 */
void exitt(char **arv)
{
int i, n;
if (arv[1])
{
n = _atoi(arv[1]);
if (n <= -1)
n = 2;
freearv(arv);
exit(n);
}
for (i = 0; arv[i]; i++)
free(arv[i]);
free(arv);
exit(0);
}


/**
 * env - prints the environment its on
 * @arv: array of arguments
 */
void env(char **arv __attribute__ ((unused)))
{

int i;

for (i = 0; environ[i]; i++)
{
_puts(environ[i]);
_puts("\n");
}
}

/**
 * _setenv - Initializing or modifying environment variable
 * @arv: array of entered words
 */
void _setenv(char **arv)
{
int i, j, k;
if (!arv[1] || !arv[2])
{
perror(_getenv("_"));
return;
}
for (i = 0; environ[i]; i++)
{
j = 0;
if (arv[1][j] == environ[i][j])
{
while (arv[1][j])
{
if (arv[1][j] != environ[i][j])
break;
j++;
}
if (arv[1][j] == '\0')
{
k = 0;
while (arv[2][k])
{
environ[i][j + 1 + k] = arv[2][k];
k++;
}
environ[i][j + 1 + k] = '\0';
return;
}
}
}
if (!environ[i])
{

environ[i] = concat_all(arv[1], "=", arv[2]);
environ[i + 1] = '\0';

}
}

/**
 * _unsetenv - Remove an environment variable
 * @arv: array of entered words
 */
void _unsetenv(char **arv)
{
int i, j;

if (!arv[1])
{
perror(_getenv("_"));
return;
}
for (i = 0; environ[i]; i++)
{
j = 0;
if (arv[1][j] == environ[i][j])
{
while (arv[1][j])
{
if (arv[1][j] != environ[i][j])
break;

j++;
}
if (arv[1][j] == '\0')
{
free(environ[i]);
environ[i] = environ[i + 1];
while (environ[i])
{
environ[i] = environ[i + 1];
i++;
}
return;
}
}
}
}
