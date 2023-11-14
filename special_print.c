#include "main.h"

/**
 * print_from_to - a function that print a specified string
 *
 * @start: the starting of the string
 * @stop: the end of the string
 * @skip: chars that can be skipped
 *
 * Return: the number of bytes printed
 */

int print_from_to(char *start, char *stop, char *skip)
{
	int sum = 0;

	while (start <= stop)
	{
		if (start != skip)
			sum += _putchar(*start);
		start++;
	}
	return (sum);
}

/**
 * print_reverse - print a given string in reverse
 *
 * @ap: the va list given
 * @para: the parameters list pointer
 *
 * Return: numbre of bytes printed
 */

int print_reverse(va_list ap, para_list *para)
{
	int len, sum = 0;
	char *str = va_arg(ap, char *);

	(void)para;
	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		str--;
		for (; len > 0; len--, str--)
			sum += _putchar(*str);
	}
	return (sum);
}

/**
 * print_rot13 - a function that print a given string in rot13 codeing
 *
 * @ap: the va list given
 * @para: the parameters list pointer
 *
 * Return: number of bytes printed
 */

int print_rot13(va_list ap, para_list *para)
{
	int i, index, count = 0;
char array[] = "NOPQRSTUVWXYZABCDEFGHIJKLM	nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(ap, char *);

	(void)para;
	i = 0;
	index = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z') ||
			(a[i] >= 'a' && a[i] <= 'z'))
		{
			index = a[i] - 65;
			count += _putchar(array[index]);
		}
		else
			count += _putchar(a[i]);
		i++;
	}
	return (count);
}
