#include "main.h"

/**
 * calculate_argument_size - Calculates the size to cast the argument
 * @format: Formatted string containing the conversion specifier
 * @index: Index of the current character being checked in the format string
 *
 * Return: Calculated argument size.
 */
int calculate_argument_size(const char *format, int *index)
{
	int current_index = *index + 1;
	int argument_size = 0;

	if (format[current_index] == 'l')
		argument_size = ARG_LONG;
	else if (format[current_index] == 'h')
		argument_size = ARG_SHORT;

	if (argument_size == 0)
		*index = current_index - 1;
	else
		*index = current_index;

	return argument_size;
}
