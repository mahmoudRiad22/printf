#include "main.h"

/**
 * _puts - a function that prints a given string
 * @str: the string given
 *
 * Return: number of bytes printed
 */

int _puts(char *str)
{
	char *x = str;

	while (*str)
	{
		_putchar(*str);
		str++;
	}
	return (str - x);
}

/**
 * _putchar -  a function that prints a given char only
 *
 * @c: the ascii code of the given char
 *
 * Return: number of bytes printed
 */

int _putchar(int c)
{
	static int i;
	static char buffer[BUFFER_SIZE];

	if (c == BUFFER_FLUSH || i >= BUFFER_SIZE)
	{
		write(1, buffer, i);
		i = 0;
	}

	if (c != BUFFER_FLUSH)
	{
		buffer[i] = c;
		i++;
	}

	return (1);
}
