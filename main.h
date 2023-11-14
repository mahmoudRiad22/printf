#ifndef _MAHMOUD_H
#define _MAHMOUD_H

/******INCLUDES******/
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

/*********DEFINTIONS********/
#define BUFFER_SIZE 1024
#define BUFFER_FLUSH -1
#define NULL_STRING "(null)"

#define PARAMETERS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define LOWERCASE 1
#define UNSIGNED 2

/***********STRUCTURES*********/

/**
 * struct parameters - parameters structure
 *
 * @unsign: a flag for an unsigned value
 *
 * @flag_plus: the flag is on if the flag_plus is given
 * @flag_minus: the flag is on if the flag_minus is given
 * @flag_hash: the flag is on if the flag_hash is given
 * @flag_space: the flag is on if the flag_space is given
 * @flag_zero: the flag is on if the flag_zero is given
 *
 * @width: 1 if the field width is given
 * @percision: 1 if the field percision is given
 *
 * @modifier_l: on if the modifier_l for (long) is given
 * @modifier_h: on if the modifier_h for (short) is given
 */
typedef struct parameters
{
	unsigned int unsign : 1;

	unsigned int flag_plus	: 1;
	unsigned int flag_minus	: 1;
	unsigned int flag_hash	: 1;
	unsigned int flag_space	: 1;
	unsigned int flag_zero	: 1;

	unsigned int width	: 1;
	unsigned int percision	: 1;

	unsigned int modifier_l	: 1;
	unsigned int modifier_h	: 1;
} para_list;


/**
 * struct specifier - the specifier structure
 *
 * @specifier: the format char given
 * @f: a pointer to the function associated to it
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, para_list *);
} specifier_list;

/******FILE: parameters_initializing.c****/
void init_para(para_list *para, va_list ap);
/*DONE*/

/*****FILE: put_functions.c ************/
int _puts(char *str);
int _putchar(int c);
/*DONE*/

/*****FILE: handle_specifier.c ************/
int get_flag(char *s, para_list *para);
int get_modifier(char *s, para_list *para);
char *get_width(char *s, para_list *para, va_list ap);
int (*get_specifier(char *s))(va_list ap, para_list *para);
int call_print_function(char *s, va_list ap, para_list *para);
/*DONE*/

/*******FILE: get_percision.c ******/
char *get_percision(char *p, para_list *para, va_list ap);
/*DONE*/


#endif
