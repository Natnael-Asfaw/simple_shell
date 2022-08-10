#include "main.h"

/**
 * print_numbers - Prints numbers, used to print the error message
 * @n: number to print
 * Return: Number
 */

int print_numbers(int n)

{
	unsigned int number;
	int i = 0;

	if (n < 0)
	{
		number = -n;
		i = i + _putchar('-');
	}
	else
	{
		number = n;
	}
	if (number / 10 != '\0')
		i = i + print_numbers(number / 10);
	i = i + _putchar(number % 10 + '0');
	return (i);
}


/**
 * _printp - Prints the prompt in the standar input
 * @prompt: Pointer to the string to be printed
 * @size: Length ot the prompt
 * Return: 0 if success or -1 if fails
 */

int _printp(const char *prompt, unsigned int size)

{
	int written;

	if (isatty(STDIN_FILENO))
	{
		written = write(1, prompt, size);
		if (written == -1)
			return (-1);
	}
	return (0);
}


/**
 * print_not_found - Prints error message when a command is not found
 * @arguments: array of args typed by the user
 * @counter: Times that the shell has been executed
 * Return: Exit status
 */

int print_not_found(char **arguments, int counter)

{
	char *imode_shell_name = "hsh";
	char *non_i_mode_shell_name = "./hsh";

	if (isatty(STDIN_FILENO))
		write(2, imode_shell_name, 3);
	else
	{
		write(2, non_i_mode_shell_name, 5);
	}
	write(2, ": ", 2);
	print_numbers(counter);
	write(2, ": ", 2);
	write(2, arguments[0], _strlen(arguments[0]));
	write(2, ": not found\n", 12);
	return (127);
}
