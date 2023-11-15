#include "main.h"

/**
 * convert_to_base - a function that convert given char to different base
 *
 * @number: the given number or ascii code
 * @base: the abse to convert to
 * @flags: arguments flags
 * @para: the parameters list pointer
 *
 * Return: the string after convertion
 */

char *convert_to_base(long int number, int base, int flags, para_list *para)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *p;
	unsigned long n = number;

	(void)para;

	if (!(flags & UNSIGNED) && number < 0)
	{
		n = -number;
		sign = '-';
	}

	if (flags & LOWERCASE)
		array = "0123456789abcdef";
	else
		array = "0123456789ABCDEF";
	p = &buffer[49];
	*p = '\0';

	do {
		p--;
		*p = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
	{
		p--;
		*p = sign;
	}

	return (p);
}

/**
 * print_unsigned_num - a function that print a given unsigned number
 *
 * @ap: the va list given
 * @para: the aprameters pointer given
 *
 * Return: number of printed bytes
 */

int print_unsigned_num(va_list ap, para_list *para)
{
	unsigned long l;

	if (para->modifier_l)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (para->modifier_h)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	para->unsign = 1;

	return (print_number(convert_to_base(l, 10, UNSIGNED, para), para));
}

/**
 * print_address -  a function taht prints a given address
 *
 * @ap: the va list given
 * @para: the parameters pointer given
 *
 * Return: number of the bytes printed
 */

int print_address(va_list ap, para_list *para)
{
	char *str;
	unsigned long int n = va_arg(ap, unsigned long int);

	if (!n)
		return (_puts("(nil)"));

	str = convert_to_base(n, 16, UNSIGNED | LOWERCASE, para);
	str--;
	*str = 'x';
	str--;
	*str = '0';

	return (print_number(str, para));
}
