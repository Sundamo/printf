#include "main.h"

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
	int chara_print = 0;
	va_list list_of_args;

	if (format == NULL)
		return (-1);

	va_start (list_of_args, format);

	while (*format) // a loop that interates through characters of the format
	{
		if (*format != '%') //if format is not the % sign
		{
			write (1, format, 1);
			chara_print++;
		}

		else // if format is the % sign 
		{
			format++;
			if (*format == '\0')
				break;

			if (*format == '%') // this solves ('%')
			{
				//handle '%%' (double '%')
				write (1, format, 1);
				chara_print++;
			}

			else if (*format == 'c')
			{
				//handle '%c' (character)
				char c = va_arg(list_of_args, int);
				write (1, &c, 1);
				chara_print++;
			}

			else if (*format == 's')
			{
				char *str = va_arg(list_of_args, chars*);
				int str_len = 0;

				// calculate the lenght of the string
				while (str[str_len] != '\0')
					str_len++;

				//write this string to the standard output
				write (1, str, str_len);
				chara_print += str_len;
			}
		}

		format++
	}

	va_end (list_of_args);

	return chara_print;
}
