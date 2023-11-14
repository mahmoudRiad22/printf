#include "main.h"

/**
 * _printf - Entry point
 * @format:  the given format string
 *
 * Return:  number of bytes printed
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int sum = 0;
	char *p, *start;
	para_list parameters = PARAMETERS_INIT;

	va_start(ap, format);
/**if the input = '%' --> invalid***/
	if (!format || (format[0] == '%' && !format[2]))
		return (-1);
/**if the input = '% ' --> invalid***/
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_para(&parameters, ap);

		if (*p != '%')
		{
			sum += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (get_flag(p, &parameters))
			p++;
		p = get_width(p, &parameters, ap);
		p = get_percision(p, &parameters, ap);
		if (get_modifier(p, &parameters))
			p++;
	if (!get_specifier)
	{
	sum += printf_from_to(start, p,
		parameters.modifier_l || parameters.modifier_h ? p - 1 : 0);
	}
	else
		sum += call_print_function(p, ap, &parameters);
	}
	_putchar(BUFFER_FLUSH);
	va_end(ap);
	return (sum);
}
