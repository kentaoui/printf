#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_char - Prints a char
 * @arg_list: List of arguments
 * @output_buffer: Buffer array to handle print
 * @format_flags: Calculates active flags
 * @field_width: Width
 * @precision_value: Precision specification
 * @length_modifier: Size specifier
 * Return: Number of chars printed
 */
int print_char(va_list arg_list, char output_buffer[],
		int format_flags, int field_width, int precision_value, int length_modifier)
{
	char character = va_arg(arg_list, int);

	int printed_chars = 0;

	if (!(format_flags & FLAG_MINUS))
	{
		while (field_width > 1)
		{
			buffer_append(output_buffer, ' ');
			field_width--;
			printed_chars++;
		}
	}

	buffer_append(output_buffer, character);
	printed_chars++;

	if (format_flags & FLAG_MINUS)
	{
		while (field_width > 1)
		{
			buffer_append(output_buffer, ' ');
			field_width--;
			printed_chars++;
		}
	}

	return (printed_chars);
}
/************************* PRINT A STRING *************************/
/**
 * print_string - Prints a string
 * @arg_list: List of arguments
 * @output_buffer: Buffer array to handle print
 * @format_flags: Calculates active flags
 * @field_width: Get width.
 * @precision_value: Precision specification
 * @length_modifier: Size specifier
 * Return: Number of chars printed
 */
int print_string(va_list arg_list, char output_buffer[],
		int format_flags, int field_width, int precision_value, int length_modifier)
{
	int str_length = 0, i;
	char *str = va_arg(arg_list, char *);

	UNUSED(output_buffer);
	UNUSED(format_flags);
	UNUSED(field_width);
	UNUSED(precision_value);
	UNUSED(length_modifier);
	if (str == NULL)
	{
		str = "(null)";
		if (precision_value >= 6)
			str = "      ";
	}

	while (str[str_length] != '\0')
		str_length++;

	if (precision_value >= 0 && precision_value < str_length)
		str_length = precision_value;

	if (field_width > str_length)
	{
		if (format_flags & F_MINUS)
		{
			write(1, &str[0], str_length);
			for (i = field_width - str_length; i > 0; i--)
				write(1, " ", 1);
			return (field_width);
		}
		else
		{
			for (i = field_width - str_length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], str_length);
			return (field_width);
		}
	}

	return (write(1, str, str_length));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - Prints a percent sign
 * @arg_list: List of arguments
 * @output_buffer: Buffer array to handle print
 * @format_flags: Calculates active flags
 * @field_width: Get width.
 * @precision_value: Precision specification
 * @length_modifier: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list arg_list, char output_buffer[],
		int format_flags, int field_width, int precision_value, int length_modifier)
{
	UNUSED(arg_list);
	UNUSED(output_buffer);
	UNUSED(format_flags);
	UNUSED(field_width);
	UNUSED(precision_value);
	UNUSED(length_modifier);
	return (write(1, "%%", 1));
}
/************************* PRINT INTEGER *************************/
/**
 * print_integer - Print an integer
 * @arg_list: List of arguments
 * @output_buffer: Buffer array to handle print
 * @format_flags: Calculates active flags
 * @field_width: Get width.
 * @precision_value: Precision specification
 * @length_modifier: Size specifier
 * Return: Number of characters printed
 */
int print_integer(va_list arg_list, char output_buffer[],
		int format_flags, int field_width, int precision_value, int length_modifier)
{
	int buffer_index = BUFF_SIZE - 2;
	int is_negative = 0;
	long int number = va_arg(arg_list, long int);
	unsigned long int num;

	number = convert_size_number(number, length_modifier);

	if (number == 0)
		output_buffer[buffer_index--] = '0';

	output_buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)number;

	if (number < 0)
	{
		num = (unsigned long int)((-1) * number);
		is_negative = 1;
	}

	while (num > 0)
	{
		output_buffer[buffer_index--] = (num % 10) + '0';
		num /= 10;
	}

	buffer_index++;

	return (write_number(is_negative, buffer_index, output_buffer,
				format_flags, field_width, precision_value, length_modifier));
}
/************************* PRINT BINARY *************************/
/**
 * print_binary - Prints an unsigned number in binary format
 * @arg_list: List of arguments
 * @output_buffer: Buffer array to handle print
 * @format_flags: Calculates active flags
 * @field_width: Get width.
 * @precision_value: Precision specification
 * @length_modifier: Size specifier
 * Return: Number of characters printed.
 */
int print_binary(va_list arg_list, char output_buffer[],
		int format_flags, int field_width, int precision_value, int length_modifier)
{
	unsigned int number, mask, i, sum;
	unsigned int binary_digits[32];
	int character_count;

	UNUSED(output_buffer);
	UNUSED(format_flags);
	UNUSED(field_width);
	UNUSED(precision_value);
	UNUSED(length_modifier);

	number = va_arg(arg_list, unsigned int);
	mask = 2147483648; /* 2^31 */

	binary_digits[0] = number / mask;

	for (i = 1; i < 32; i++)
	{
		mask /= 2;
		binary_digits[i] = (number / mask) % 2;
	}

	for (i = 0, sum = 0, character_count = 0; i < 32; i++)
	{
		sum += binary_digits[i];

		if (sum || i == 31)
		{
			char binary_char = '0' + binary_digits[i];

			write(1, &binary_char, 1);
			character_count++;
		}
	}
	return (character_count);
}

