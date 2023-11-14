#include "main.h"

/**
 * is_digit - a function to check if the char is a number or not
 *
 * @c: given number
 *
 * Return: 1 if digit or 0 if NOT digit
 */

int is_digit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * str_len -  a function that return the length of a given string
 *
 * @s: the given string
 *
 * Return: the length fo the string
 */

int str_len(char *s)
{
	int i = 0;

	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

/**
 * print_number - a function that print a number according to the flags
 *
 * @str: the string given
 * @para: the parameters pointer given
 *
 * Return: the number of print ed chars
 */

int print_number(char *str, para_list *para)
{
	unsigned int i = str_len(str);
	int negative = !(para->unsign && *str == '-');

	if (!para->percision && *str == '0' && !str[1])
		str = "";
	if (negative)
	{
		str++;
		i--;
	}
	if (para->percision != UINT_MAX)
	{
		while (i < para->percision)
		{
			str--;
			*str = '0';
			i++;
		}
	}

	if (negative)
	{
		str--;
		*str = '-';
	}

	if (para->flag_minus)
		return (print_number_RS(str, para));
	else
		return (print_number_LS(str, para));
}

/**
 * print_number_RS - print the number according to given oprtions
 *
 * @str: the given string of the number
 * @para: teh parameters ponter given
 *
 * Return: number of bytes printed
 */

int print_number_RS(char *str, para_list *para)
{
	unsigned int n = 0, negative1, negative2, len = str_len(str);
	char padding_char = ' ';

	if (para->flag_zero && !para->flag_minus)
		padding_char = '0';
	negative1 = negative2 = (!para->unsign && *str == '-');
	if (negative1 && len < para->width && padding_char == '0' &&
			!para->flag_minus)
		str++;
	else
		negative1 = 0;
	if ((para->flag_plus && !negative2) ||
		(!para->flag_plus && para->flag_space && !negative2))
		len++;
	if (negative1 && padding_char == '0')
		n += _putchar('-');
	if (!negative2 && padding_char == '0' &&
			para->flag_plus && !para->unsign)
		n += _putchar('+');
	else if (!negative2 && !para->flag_plus && para->flag_space &&
			para->flag_zero && !para->unsign)
		n += _putchar(' ');
	while (len < para->width)
	{
		n += _putchar(padding_char);
		len++;
	}
	if (negative1 && padding_char == ' ')
		n += _putchar('-');
	if (para->flag_plus && !negative2 && padding_char == ' '
			&& !para->unsign)
		n += _putchar('+');
	else if (!para->flag_plus && !negative2 && para->flag_space &&
			!para->unsign && !para->flag_zero)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}

/**
 * print_number_LS - print a number with given options
 *
 * @str: the number given as a string
 * @para: the parameters pointers given
 *
 * Return: number of printed chars
 */

int print_number_LS(char *str, para_list *para)
{
	unsigned int n = 0, negative1, negative2, len = str_len(str);
	char padding_char = ' ';

	if (para->flag_zero && !para->flag_minus)
		padding_char = '0';
	negative1 = negative2 = (!para->unsign && *str == '-');
	if (negative1 && len < para->width && padding_char == '0' &&
			!para->flag_minus)
		str++;
	else
		negative1 = 0;
	if (para->flag_plus && !negative2 && !para->unsign)
		n += _putchar('+'), len++;
	else if (!negative2 && para->flag_plus && !para->unsign)
		n += _putchar(' '), len++;
	n += _puts(str);
	while (len < para->width)
	{
		n += _putchar(padding_char);
		len++;
	}

	return (n);
}
