#ifndef _MAIN_H
#define _MAIN_H

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

	unsigned int width;
	unsigned int percision;

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

/******FILE: _printf.c*********/
int _printf(const char *format, ...);
/*DONE*/

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

/*******FILE: special_print.c******/
int print_rot13(va_list ap, para_list *para);
int print_from_to(char *start, char *stop, char *skip);
int print_reverse(va_list ap, para_list *para);
/*DONE*/

/*******FILE: number_functions.c****/
char *convert_to_base(long int number, int base, int flags, para_list *para);
int print_unsigned_num(va_list ap, para_list *para);
int print_address(va_list ap, para_list *para);
/*DONE*/

/*******FILE: print_number_functions.c****/
int print_number(char *str, para_list *para);
int is_digit(int c);
int str_len(char *s);
int print_number_RS(char *str, para_list *para);
int print_number_LS(char *str, para_list *para);
/*DONE*/

/*******FILE: print_HBO.c*******/
int print_binary(va_list ap, para_list *para);
int print_octal(va_list ap, para_list *para);
int print_hex(va_list ap, para_list *para);
int print_HEX(va_list ap, para_list *para);
/*DONE*/

/*******FILE: print_function.c******/
int print_int(va_list ap, para_list *para);
int print_char(va_list ap, para_list *para);
int print_percent(va_list ap, para_list *para);
int print_custom_S(va_list ap, para_list *para);
int print_string(va_list ap, para_list *para);
/*DONE*/

#endif
