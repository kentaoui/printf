#include "main.h"

/****************** PRINT POINTER ******************/
int print_custom_pointer(va_list arg_list, char print_buffer[],
	int custom_flags, int custom_width, int custom_precision, int custom_size)
{
	char extra_char = 0, padding_char = ' ';
	int buffer_index = BUFF_SIZE - 2, length = 2, padding_start = 1; /* length=2, for '0x' */
	unsigned long num_addresses;
	char hex_map[] = "0123456789abcdef";
	void *addresses = va_arg(arg_list, void *);

	UNUSED(custom_width);
	UNUSED(custom_size);

	if (addresses == NULL)
		return (write(1, "(nil)", 5));

	print_buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(custom_precision);

	num_addresses = (unsigned long)addresses;

	while (num_addresses > 0)
	{
		print_buffer[buffer_index--] = hex_map[num_addresses % 16];
		num_addresses /= 16;
		length++;
	}

	if ((custom_flags & F_ZERO) && !(custom_flags & F_MINUS))
		padding_char = '0';
	if (custom_flags & F_PLUS)
		extra_char = '+', length++;
	else if (custom_flags & F_SPACE)
		extra_char = ' ', length++;

	buffer_index++;

	return (write_custom_pointer(print_buffer, buffer_index, length,
		custom_width, custom_flags, padding_char, extra_char, padding_start));
}

/************************* PRINT NON PRINTABLE *************************/
int print_custom_non_printable(va_list arg_list, char print_buffer[],
	int custom_flags, int custom_width, int custom_precision, int custom_size)
{
	int i = 0, offset = 0;
	char *input_str = va_arg(arg_list, char *);

	UNUSED(custom_flags);
	UNUSED(custom_width);
	UNUSED(custom_precision);
	UNUSED(custom_size);

	if (input_str == NULL)
		return (write(1, "(null)", 6));

	while (input_str[i] != '\0')
	{
		if (is_printable(input_str[i]))
			print_buffer[i + offset] = input_str[i];
		else
			offset += append_hex_code(input_str[i], print_buffer, i + offset);

		i++;
	}

	print_buffer[i + offset] = '\0';

	return (write(1, print_buffer, i + offset));
}

/************************* PRINT REVERSE *************************/
int print_custom_reverse(va_list arg_list, char print_buffer[],
	int custom_flags, int custom_width, int custom_precision, int custom_size)
{
	char *input_str;
	int i, char_count = 0;

	UNUSED(print_buffer);
	UNUSED(custom_flags);
	UNUSED(custom_width);
	UNUSED(custom_size);

	input_str = va_arg(arg_list, char *);

	if (input_str == NULL)
	{
		UNUSED(custom_precision);
		input_str = ")Null(";
	}
	for (i = 0; input_str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char reversed_char = input_str[i];
		write(1, &reversed_char, 1);
		char_count++;
	}
	return (char_count);
}

/************************* PRINT A STRING IN ROT13 *************************/
int print_custom_rot13string(va_list arg_list, char print_buffer[],
	int custom_flags, int custom_width, int custom_precision, int custom_size)
{
	char transformed_char;
	char *input_str;
	unsigned int i, j;
	int char_count = 0;
	char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot13_upper[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	input_str = va_arg(arg_list, char *);
	UNUSED(print_buffer);
	UNUSED(custom_flags);
	UNUSED(custom_width);
	UNUSED(custom_precision);
	UNUSED(custom_size);

	if (input_str == NULL)
		input_str = "(AHYY)";
	for (i = 0; input_str[i]; i++)
	{
		for (j = 0; uppercase[j]; j++)
		{
			if (uppercase[j] == input_str[i])
			{
				transformed_char = rot13_upper[j];
				write(1, &transformed_char, 1);
				char_count++;
				break;
			}
		}
		if (!uppercase[j])
		{
			transformed_char = input_str[i];
			write(1, &transformed_char, 1);
			char_count++;
		}
	}
	return (char_count);
}

