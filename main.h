#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct custom_format - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct custom_format
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct custom_format custom_fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct custom_format custom_fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
	va_list list, char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Functions to print chars and strings */
int print_custom_char(va_list arg_list, char print_buffer[],
	int custom_flags, int custom_width, int custom_precision, int custom_size);
int print_custom_string(va_list arg_list, char print_buffer[],
	int custom_flags, int custom_width, int custom_precision, int custom_size);
int print_custom_percent(va_list arg_list, char print_buffer[],
	int custom_flags, int custom_width, int custom_precision, int custom_size);

/* Functions to print numbers */
int print_custom_int(va_list arg_list, char print_buffer[],
	int custom_flags, int custom_width, int custom_precision, int custom_size);
int print_custom_binary(va_list arg_list, char print_buffer[],
	int custom_flags, int custom_width, int custom_precision, int custom_size);
int print_custom_unsigned(va_list arg_list, char print_buffer[],
	int custom_flags, int custom_width, int custom_precision, int custom_size);
int print_custom_octal(va_list arg_list, char print_buffer[],
	int custom_flags, int custom_width, int custom_precision, int custom_size);
int print_custom_hexadecimal(va_list arg_list, char print_buffer[],
	int custom_flags, int custom_width, int custom_precision, int custom_size);
int print_custom_hexa_upper(va_list arg_list, char print_buffer[],
	int custom_flags, int custom_width, int custom_precision, int custom_size);

int print_custom_hexa(va_list arg_list, char map_to[],
	char print_buffer[], int custom_flags, char flag_ch, int custom_width, int custom_precision, int custom_size);

/* Function to print non-printable characters */
int print_custom_non_printable(va_list arg_list, char print_buffer[],
	int custom_flags, int custom_width, int custom_precision, int custom_size);

/* Function to print memory address */
int print_custom_pointer(va_list arg_list, char print_buffer[],
	int custom_flags, int custom_width, int custom_precision, int custom_size);

/* Functions to handle other specifiers */
int get_custom_flags(const char *format, int *i);
int get_custom_width(const char *format, int *i, va_list list);
int get_custom_precision(const char *format, int *i, va_list list);
int get_custom_size(const char *format, int *i);

/* Function to print string in reverse */
int print_custom_reverse(va_list arg_list, char print_buffer[],
	int custom_flags, int custom_width, int custom_precision, int custom_size);

/* Function to print a string in rot13 */
int print_custom_rot13string(va_list arg_list, char print_buffer[],
	int custom_flags, int custom_width, int custom_precision, int custom_size);

/* Width handler */
int handle_write_char(char c, char buffer[],
	int custom_flags, int custom_width, int custom_precision, int custom_size);
int write_number(int is_positive, int ind, char buffer[],
	int custom_flags, int custom_width, int custom_precision, int custom_size);
int write_num(int ind, char bff[], int custom_flags, int custom_width, int custom_precision,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int width, int custom_flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
	char buffer[],
	int custom_flags, int custom_width, int custom_precision, int custom_size);

/****************** UTILS ******************/
int is_printable(char);
int append_custom_hexa_code(char, char[], int);
int is_digit(char);

long int convert_custom_size_number(long int num, int size);
long int convert_custom_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */

