#include "main.h"
/**
 *free_grid - Free the allocated memory used in the last excercise
 *@grid: pointer to grid
 *@heigth: Heigth of the grid
 */

void free_grid(char **grid, int heigth)
{
	int i = 0;

	if (grid == NULL)
	{
		return;
	}

	while (i < heigth)
	{
		free(grid[i]);
		i++;
	}
}

/**
 * last_free - Free the memory for the last execution
 * @entry: Input typed by the user
 */
void last_free(char *entry)
{
	if (isatty(STDIN_FILENO))
	{
		_putchar('\n');
		free(entry);
	}
	if (!isatty(STDIN_FILENO))
		free(entry);
}