#include "main.h"

/**
 * get_percision - a function to handle the percision when given
 *
 * @p: given percision token
 * @para: the parameters list pointer
 * @ap:  the var_list given
 *
 * Return: the string after the percision is counted
 */
char *get_percision(char *p, para_list *para, va_list ap)
{
        int d = 0;

        if (*p != '.')
                return (p);

        p++;
        if (*p == '*')
        {
                d = va_arg(ap, int);
                p++;
        }
        else
        {
                while (is_digit(*p))
                {
                        d = d * 10 + (*p - '0');
                        p++;
                }
        }
        para->percision = d;

        return (p);
}


