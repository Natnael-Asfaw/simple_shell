#include "main.h"

/**
 * verify_path - Verify if the first command can be executed
 * @arguments: Array of entries by the user
 * Return: 0 if success, or -1 if the exe file doesn't exist
 */

int verify_path(char **arguments)

{
	char *global_path = NULL; /**"/usr/bin:/bin:/usr/games:/usr/local/games"*/
	char *global_dup = NULL;
	char *dir_path = NULL; /**"   /usr/bin    "*/
	char *command_path = NULL; /**"   /usr/bin/touch      "*/
	char *test_cph[121];
	int exist_stat = -1, i = 0;

	global_path = _getenv("PATH");
	if (global_path == NULL)
		return (-1);
	global_dup = (_strdup(global_path));
	dir_path = strtok(global_dup, ":");
	if (dir_path == NULL)
		return (-1);
	free(global_path);
	while (exist_stat == -1 && dir_path != NULL)
	{
		command_path = append_command(dir_path, arguments[0]);
		test_cph[i] = command_path;
		exist_stat = exist(test_cph[i]);
		dir_path = strtok(NULL, ":");
		i++;
	}
	i--;
	free(global_dup);
	free_grid(test_cph, i);
	if (exist_stat == 0)
	{
		arguments[0] = test_cph[i];
		return (0);
	}
	else
	{
		free(test_cph[i]);
		return (-1);
	}
}

/**
 * verify_blt - Verify if the input is a builtin
 * @arguments: Pointer to the array of arguments
 * @exit_stat: Current exit status
 * Return: -1 if the command is not a builtin, 0 if it is
 */

int verify_blt(char **arguments, int exit_stat)

{
	char *builtins[2] = {
		"exit",
		"env"
	};
	int i = 0;

	while (i < 2)
	{
		if (_strcmp(arguments[0], builtins[i]) == 0)
			break;
		i++;
	}
	if (i == 2)
		return (-1);
	if (_strcmp(builtins[i], "exit") == 0)
	{
		free(arguments[0]);
		exit(exit_stat);
	}
	if (_strcmp(builtins[i], "env") == 0)
	{
		if (environ == NULL)
			return (0);
		write(1, environ, 1000);
	}
	return (0);
}
