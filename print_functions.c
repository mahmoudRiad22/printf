#include "main.h"

/**
 * print_string -  a fucntion that print a given string
 *
 * @ap: given va list
 * @para: teh parameters pointer given
 *
 * Return: the number of bytes printed
 */

int print_string(va_list ap, para_list *para)
{
	char *str = va_arg(ap, char *);
	char padding_char = ' ';
	unsigned int pad = 0, sum = 0, i = 0, j;

	(void)para;
	if ((int)(!str) == 1)
		str = NULL_STRING;
	j = pad = str_len(str);
	if (para->percision < pad)
		j = pad = para->percision;

	if (para->flag_minus)
	{
		if (para->percision != UINT_MAX)
			for (i = 0; i < pad; i++)
			{
				sum += _putchar(*str);
				str++;
			}
		else
			sum += _puts(str);
	}
	while (j < para->width)
	{
		sum += _putchar(padding_char);
		j++;
	}
	if (!para->flag_minus)
	{
		if (para->percision != UINT_MAX)
			for (i = 0; i < pad; i++)
			{
				sum += _putchar(*str);
				str++;
			}
		else
			sum += _puts(str);
	}
	return (sum);
}

/**
 * print_custom_S - a function that print a string and hexa of non-visable char
 *
 * @ap: the va list given
 * @para: the parameters pointer given
 *
 * Return: the number of bytes printed
 */

int print_custom_S(va_list ap, para_list *para)
{
	char *str = va_arg(ap, char *);
	char *hex;
	int sum = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));

	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = convert_to_base(*str, 16, 0, para);

			if (!hex[1])
				sum += _putchar('0');

			sum += _puts(hex);
		}
		else
			sum += _putchar(*str);
	}
	return (sum);
}

/**
 * print_percent - a function that prints the '%' char
 *
 * @ap: the va list given
 * @para: the parameters pointer given
 *
 * Return: the number of bytes printed
 */

int print_percent(va_list ap, para_list *para)
{
	(void)ap;
	(void)para;

	return (_putchar('%'));
}

/**
 * print_char - a function that print a single char
 *
 * @ap: the va list given
 * @para: the parameters pointer given
 *
 * Return: the number of bytes printed
 */

int print_char(va_list ap, para_list *para)
{
	char padding_char = ' ';
	unsigned int pad = 1, sum = 0;
	unsigned int ch = va_arg(ap, int);

	if (para->flag_minus)
		sum += _putchar(ch);

	while (pad < para->width)
	{
		sum += _putchar(padding_char);
		pad++;
	}

	if (!para->flag_minus)
		sum += _putchar(ch);

	return (sum);
}

/**
 * print_int - a fucntion taht print an integer
 *
 * @ap: the va list given
 * @para: the parameters pointer given
 *
 * Return: number of bytes printed
 */

int print_int(va_list ap, para_list *para)
{
	long x;

	if (para->modifier_l)
		x = va_arg(ap, long);
	else if (para->modifier_h)
		x = (short int)va_arg(ap, int);
	else
		x = (int)va_arg(ap, int);

	return (print_number(convert_to_base(x, 10, 0, para), para));
}

