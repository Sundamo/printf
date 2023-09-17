#include "main.h"
#include <stdio.h>
void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - Printf custom  function.
 * @format: format.
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
<<<<<<< HEAD
int i, printed = 0;
printed_chars = 0;
int flags, width, precision, size, buff_ind = 0;
va_list list;
char buffer[BUFF_SIZE];
if (format == NULL)
return (-1);
va_start(list, format);
for (i = 0; format && format[i] != '\0'; i++)
{
if (format[i] != '%')
{
buffer[buff_ind++] = format[i];
if (buff_ind == BUFF_SIZE)
print_buffer(buffer, &buff_ind);
/* write(1, &format[i], 1);*/
printed_chars++;
}
else
{
print_buffer(buffer, &buff_ind);
flags = get_flags(format, &i);
width = get_width(format, &i, list);
precision = get_precision(format, &i, list);
size = get_size(format, &i);
++i;
printed = handle_print(format, &i, list, buffer,
flags, width, precision, size);
if (printed == -1)
return (-1);
printed_chars += printed;
}
}
print_buffer(buffer, &buff_ind);
va_end(list);
return (printed_chars);
}
/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
if (*buff_ind > 0)
write(1, &buffer[0], *buff_ind);
*buff_ind = 0;
int chara_print = 0;
va_list list_of_args;
if (format == NULL)
return (-1);
va_start (list_of_args, format);
while (*format) 
/* a loop that interates through characters of the format*/
{
if (*format != '%') /*if format is not the % sign*/
{
write (1, format, 1);
chara_print++;
}
else /* if format is the % sign */
{
format++;
if (*format == '\0')
break;
if (*format == '%')
{
/*handle '%%' (double '%')*/
write (1, format, 1);
chara_print++;
}
else if (*format == 'c')
{
/*handle '%c' (character)*/
char c = va_arg(list_of_args, int);
write (1, &c, 1);
chara_print++;
}
else if (*format == 's')
{
char *str = va_arg(list_of_args, chars*);
int str_len = 0;
/* calculate the lenght of the string*/
while (str[str_len] != '\0')
str_len++;
/*write this string to the standard output*/
write (1, str, str_len);
chara_print += str_len;
}
}
format++
}
va_end (list_of_args);
return (chara_print);
}
