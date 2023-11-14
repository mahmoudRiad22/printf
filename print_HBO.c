#include "main.h"

/**
 * print_octal - a function that prints the number in octal base
 *
 * @ap: the va list given
 * @para: the parameters pointer given
 *
 * Return: the number of bytes printed
 */

int print_octal(va_list ap, para_list *para)
{
	unsigned long x;
	char *str;
	int c = 0;

	if (para->modifier_l)
		x = (unsigned long)va_arg(ap, unsigned long);
	else if (para->modifier_h)
		x = (unsigned short int)va_arg(ap, unsigned int);
	else
		x = (unsigned int)va_arg(ap, unsigned int);

	str = convert_to_base(x, 8, UNSIGNED, para);

	if (x && para->flag_hash)
	{
		str--;
		*str = '0';
	}
	para->unsign = 1;

	return (c += print_number(str, para));
}

/**
 * print_binary -  a function to print in a binary formation
 *
 * @ap: the va list given
 * @para: the parameters list given
 *
 * Return: the number of bytes printed
 */

int print_binary(va_list ap, para_list *para)
{
	unsigned int x = va_arg(ap, unsigned int);
	char *str = convert_to_base(x, 2, UNSIGNED, para);
	int counter = 0;

	if (x && para->flag_hash)
	{
		str--;
		*str = '0';
	}
	para->unsign = 1;

	return (counter += print_number(str, para));
}

/**
 * print_hex - a function to print in the lowercase hexa format
 *
 * @ap: the va list given
 * @para: the parameters pointer given
 *
 * Return: number of bytes printed
 */

int print_hex(va_list ap, para_list *para)
{
	unsigned long x;
	int counter = 0;
	char *str;

	if (para->modifier_l)
		x = (unsigned long)va_arg(ap, unsigned long);
	else if (para->modifier_h)
		x = (unsigned short int)va_arg(ap, unsigned int);
	else
		x = (unsigned int)va_arg(ap, unsigned int);

	str = convert_to_base(x, 16, UNSIGNED | LOWERCASE, para);

	if (para->flag_hash && x)
	{
		str--;
		*str = 'x';
		str--;
		*str = '0';
	}
	para->unsign = 1;

	return (counter += print_number(str, para));
}

/**
 * print_HEX - print given string in Capital HEXA format
 *
 * @ap: teh va list given
 * @para: the parameteres pointer given
 *
 * Return: number of bytes printed
 */

int print_HEX(va_list ap, para_list *para)
{
	unsigned long x;
	int counter = 0;
	char *str;

	if (para->modifier_l)
		x = (unsigned long)va_arg(ap, unsigned long);
	else if (para->modifier_h)
		x = (unsigned short int)va_arg(ap, unsigned int);
	else
		x = (unsigned int)va_arg(ap, unsigned int);

	str = convert_to_base(x, 16, UNSIGNED, para);

	if (para->flag_hash && x)
	{
		str--;
		*str = 'X';
		str--;
		*str = '0';
	}
	para->unsign = 1;

	return (counter = print_number(str, para));
}
