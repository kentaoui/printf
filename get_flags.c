#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @index: Current index in the format string
 * Return: Flags:
 */
int get_flags(const char *format, int *index)
{
	int i, curr_index;
	int flags = 0;
	const char FLAG_CHARS[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAG_VALUES[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_index = *index + 1; format[curr_index] != '\0'; curr_index++)
	{
		for (i = 0; FLAG_CHARS[i] != '\0'; i++)
		{
			if (format[curr_index] == FLAG_CHARS[i])
			{
				flags |= FLAG_VALUES[i];
				break;
			}
		}

		if (FLAG_CHARS[i] == '\0')
			break;
	}

	*index = curr_index - 1;

	return (flags);
}
