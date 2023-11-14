#include "main.h"

/**
 * init_para - a function to intialize the parameters list
 *
 * @para: the parameters list pointer
 * @ap: the variable list
 *
 * return: void
 */

void init_para(para_list *para, va_list ap)
{
	para->unsign = 0;
	para->flag_plus = 0;
	para->flag_minus = 0;
	para->flag_space = 0;
	para->flag_hash = 0;
	para->flag_zero = 0;
	para->width = 0;
	para->percision = UINT_MAX;
	para->modifier_l = 0;
	para->modifier_h = 0;

	(void)ap;

}
