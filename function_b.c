#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - Prints an unsigned number
 * @args: List of arguments
 * @buf: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Get width
 * @precision: Precision specification
 * @length: Size specifier
 * Return: Number of characters printed.
 */
int print_unsigned(va_list args, char buf[],
		int flags, int width, int precision, int length)
{
	int idx = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);

	num = convert_size_unsgnd(num, length);

	if (num == 0)
		buf[idx--] = '0';

	buf[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buf[idx--] = (num % 10) + '0';
		num /= 10;
	}

	idx++;
	return (write_unsgnd(0, idx, buf, flags, width, precision));
}
/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - Prints an unsigned number in octal notation
 * @args: List of arguments
 * @buf: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Get width
 * @precision: Precision specification
 * @length: Size specifier
 * Return: Number of characters printed
 */
int print_octal(va_list args, char buf[],
		int flags, int width, int precision, int length)
{

	int idx = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, length);

	if (num == 0)
		buf[idx--] = '0';

	buf[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buf[idx--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buf[idx--] = '0';

	idx++;

	return (write_unsgnd(0, idx, buf, flags, width, precision, length));
}
/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @arg_list: List of arguments
 * @output_buffer: Buffer array to handle print
 * @format_flags: Calculates active flags
 * @field_width: Get width
 * @precision_value: Precision specification
 * @length_modifier: Size specifier
 * Return: Number of characters printed
 */
int print_hexadecimal(va_list arg_list, char output_buffer[],
		int format_flags, int field_width, int precision_value, int length_modifier)
{
	return (print_hexa(arg_list, "0123456789abcdef", output_buffer,
				format_flags, 'x', field_width, precision_value, length_modifier));
}
/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @arg_list: List of arguments
 * @output_buffer: Buffer array to handle print
 * @format_flags: Calculates active flags
 * @field_width: Get width
 * @precision_value: Precision specification
 * @length_modifier: Size specifier
 * Return: Number of characters printed
 */
int print_hexa_upper(va_list arg_list, char output_buffer[],
		int format_flags, int field_width, int precision_value, int length_modifier)
{
	return (print_hexa(arg_list, "0123456789ABCDEF", output_buffer,
				format_flags, 'X', field_width, precision_value, length_modifier));
}
/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @args: List of arguments
 * @map: Array of values to map the number to
 * @buf: Buffer array to handle print
 * @flags: Calculates active flags
 * @flag: Calculates active flags
 * @width: Get width
 * @precision: Precision specification
 * @len: Size specifier
 * Return: Number of chars printed
 */
int print_hexa(va_list args, char map[], char buf[],
		int flags, char flag, int width, int precision, int len)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, len);

	if (num == 0)
		buf[i--] = '0';

	buf[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buf[i--] = map[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buf[i--] = flag;
		buf[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buf, flags, width, precision, len));
}

