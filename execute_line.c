#include "main.h"
/**
 * exec - Creates a new child process,
 * executes a command and wait for the child process
 * to update the status
 * @arguments: Array of inputs by the user
 * Return: 0 if success
 */
int exec(char **arguments)
{
pid_t pid = 0;
int stat = 0, exe_stat = 0;
pid = fork();
if (pid == -1)
_printp("failed\n", 7);
else if (pid == 0)
{
exe_stat = execve(arguments[0], arguments, environ);
if (exe_stat == -1)
{
exe_stat = 126;
perror("hsh");
exit(exe_stat);
}
exit(0);
}
else
wait(&stat);
exe_stat = WEXITSTATUS(stat);
return (exe_stat);
}

/**
 * exist - Verify if a file exist
 * @pathname: path to the file
 * Return: 0 if the file exist or -1 if not
 */
int exist(char *pathname)
{
int exist_stat;

exist_stat = (open(pathname, O_RDONLY));
if (exist_stat != -1)
{
close(exist_stat);
return (0);
}
else
return (-1);
}

/**
 * fill_args - fills an array with every input typed by the user
 * @entry: String with the input
 * @arguments: Array to be filled
 * Return: Length of the array
 */

int fill_args(char *entry, char **arguments)
{
int i = 0;
char *options, *aux = entry, *command;
command = strtok(entry, "\n\t\r ");
arguments[i] = command;
while (aux != NULL)
{
++i;
options = strtok(NULL, "\n\t\r ");
aux = options;
arguments[i] = options;
}
arguments[i] = NULL;
return (i);
}
