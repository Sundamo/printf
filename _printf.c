#include "main.h"
#include <stdio.h>
#include <unistd.h>
/**
 * _printf - Printf custom function.
 * @format: format string.
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
va_list list;
int buff_ind = 0, chars_printed = 0;
char buffer[BUFF_SIZE];
if (format == NULL)
return (-1);
va_start(list, format);
while (*format)
{
if (*format != '%')
{
buffer[buff_ind++] = *format;
if (buff_ind == BUFF_SIZE)
{
write(1, buffer, buff_ind);
chars_printed += buff_ind;
buff_ind = 0;
}
else
{
chars_printed++;
}
}
else
{
buffer[buff_ind++] = *format;
if (buff_ind == BUFF_SIZE)
{
write(1, buffer, buff_ind);
chars_printed += buff_ind;
buff_ind = 0;
}
else
{
chars_printed++;
}
}
format++;
}
va_end(list);
if (buff_ind > 0)
{
write(1, buffer, buff_ind);
chars_printed += buff_ind;
}
return (chars_printed);
}
