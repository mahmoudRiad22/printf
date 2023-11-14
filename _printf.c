#include "main.h"

/**_printf - a clone of the printf function
 *
 * @format:  the given format string
 *
 * return:  number of bytes printed
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int sum = 0;
	char *p, *start;
	para_list parameters = PARAMETERS_INIT;

	va_start(ap, format);
/**if the input = "%" --> invalid***/
	if (!format || (format[0] == '%' && !format[2]))
		return (-1);
/**if the input = "% " --> invalid***/
	if(format[0] == "%" && format[1] == " " && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_para(&parameters, ap);

		if (*p != "%")
		{
			sum += _putchar(*p);
			continue;
		}

		start = p;
		p++;
/**1st-FLAGS*/
		while (get_flag(p, &parameters))
			p++;
/**2nd-WIDTH**/
		p = get_width(p, &parameters, ap);
/**3rd-PERCISION**/
		p = get_percision(p, &parameters, ap);
/**4th-MODIFIER**/
		if (get_modifier(p, &parameters))
			p++;
/**5th-SPECIFIER**/
		if (!get_specifier)
		{
			sum += printf_from_to(start, p,
				para.modifier_l || para.modifier_h ? p - 1 : 0)
		}
		else 
			sum += call_print_function(p, ap, &parameters)
	}

	_putchar(BUFFER_FLUSH);
	va_end(ap);

	return (sum);
	

}
