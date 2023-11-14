#include "main.h"

/**
 * get_flag - the function that handle the flags
 *
 * @s: given flag token
 * @para: the parameters list pointer
 *
 * Return: 1 if any falg is on, 0 if no flag is on
 */
int get_flag(char *s, para_list *para)
{
	int i = 0;	/*flag detector*/

	if (*s == '+')
		i = para->flag_plus = 1;
	else if (*s == '-')
		i = para->flag_minus = 1;
	else if (*s == ' ')
		i = para->flag_space = 1;
	else if (*s == '#')
		i = para->flag_hash = 1;
	else if (*s == '0')
		i = para->flag_zero = 1;

	return (i);
}

/**
 * get_modifier - a function to handle the modifier (l/h)
 *
 * @s: given modifier token
 * @para: the parameters list pointer
 *
 * Return: 1 if a modifier is found or 0 if none found
 */

int get_modifier(char *s, para_list *para)
{
	int i = 0;

	if (*s == 'h')
		i = para->modifier_h = 1;
	else if (*s == 'l')
		i = para->modifier_l = 1;

	return (i);
}

/**
 * get_width -  a function to ahndle the width given
 *
 * @s: the given width token
 * @para: teh parameterslist pointer
 * @ap: the var list
 *
 * Return: the string pointer after the width is considered
 */

char *get_width(char *s, para_list *para, va_list ap)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(ap, int);
		s++;
	}
	else
	{
		while (is_digit(*s))
		{
			d = d * 10 + (*s - '0');
			s++;
		}
	}

	para->width = d;
	return (s);
}

/**
 * get_specifier - a function to handle the specifier tokens
 *
 * @s: the string format given
 *
 * Return: the number of bytes printed after calling the corresponding function
 */

int (*get_specifier(char *s))(va_list ap, para_list *para)
{
	specifier_list specifiers[] = {

		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_HEX},
		{"u", print_unsigned_num},
		{"p", print_address},
		{"S", print_custom_S},
		{"r", print_reverse},
		{"R", print_rot13},
		{NULL, NULL}
	};

	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
			return (specifiers[i].f);
		i++;
	}
	return (NULL);
}

/**
 * call_print_function - find the required format function
 *
 * @s: the given string
 * @ap: the va list given
 * @para: the parameters list pointer
 *
 * Return: the number of bytes printed
 */
int call_print_function(char *s, va_list ap, para_list *para)
{
	int (*f)(va_list, para_list *) = get_specifier(s);

	if (f)
		return (f(ap, para));

	return (0);
}
