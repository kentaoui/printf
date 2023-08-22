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
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int print_char(va_list arg_list, char output_buffer[],
                int format_flags, int field_width, int precision_value, int length_modifier);
int print_string(va_list arg_list, char output_buffer[],
                int format_flags, int field_width, int precision_value, int length_modifier);
int print_percent(va_list arg_list, char output_buffer[],
                int format_flags, int field_width, int precision_value, int length_modifier);

/* Functions to print numbers */
int print_integer(va_list arg_list, char output_buffer[],
                int format_flags, int field_width, int precision_value, int length_modifier);
int print_binary(va_list arg_list, char output_buffer[],
                int format_flags, int field_width, int precision_value, int length_modifier);
int print_unsigned(va_list args, char buf[],
                int flags, int width, int precision, int length);
int print_octal(va_list args, char buf[],
                int flags, int width, int precision, int length);
int print_hexadecimal(va_list arg_list, char output_buffer[],
                int format_flags, int field_width, int precision_value, int length_modifier);
print_hexa_upper(va_list arg_list, char output_buffer[],
                int format_flags, int field_width, int precision_value, int length_modifier);

int print_hexa(va_list args, char map[], char buf[],
                int flags, char flag, int width, int precision, int len);

/* Function to print non printable characters */
int print_custom_pointer(va_list arg_list, char print_buffer[],
        int custom_flags, int custom_width, int custom_precision, int custom_size);
/* Funcion to print memory address */
int print_custom_non_printable(va_list arg_list, char print_buffer[],
        int custom_flags, int custom_width, int custom_precision, int custom_size);
/* Funciotns to handle other specifiers */
int get_flags(const char *format, int *index);
int get_width(const char *format, int *index, va_list args);
int calculate_precision(const char *format, int *index, va_list args_list);
int calculate_argument_size(const char *format, int *index);

/*Function to print string in reverse*/
int print_custom_reverse(va_list arg_list, char print_buffer[],
        int custom_flags, int custom_width, int custom_precision, int custom_size);
/*Function to print a string in rot 13*/
int print_custom_rot13string(va_list arg_list, char print_buffer[],
        int custom_flags, int custom_width, int custom_precision, int custom_size);
/* width handler */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

/****************** UTILS ******************/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */

