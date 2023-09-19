#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
 * _printf - A custom implementation of printf.
 * @format: The format string.
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
va_list args;
int chars_printed = 0;
int idx = 0;
va_start(args, format);
while (format[idx] != '\0')
{
if (format[idx] == '%')
{
idx++;
if (format[idx] == '\0')
{
break;
}
if (format[idx] == 'd' || format[idx] == 'i')
{
chars_printed += integer_formatter(args);
}
else
{
format++;
switch (*format)
{
case 'c':
chars_printed += format_character(args);
break;
case 's':
chars_printed += string_printer(args);
break;
case '%':
chars_printed += percent_formatter(args);
break;
default:
write(1, format - 1, 1);
write(1, format, 1);
chars_printed += 2;
break;
}
}
format++;
}
}
else
{
write(1, &format[idx], 1);
chars_printed++;
idx++;
}
}
va_end(args);
return (chars_printed);
}
/**
 * format_character - Formats and prints a character.
 * @args: The va_list containing the character.
 * Return: The number of characters printed.
 */
int format_character(va_list args)
{
int len = 0;
char c = va_arg(args, int);
write(1, &c, 1);
len++;
return (len);
}
/**
 * string_printer - Prints a string.
 * @args: The va_list containing the string.
 * Return: The number of characters printed.
 */
int string_printer(va_list args)
{
int len = 0;
char *str = va_arg(args, char *);
if (str == NULL)
str = "(null)";
while (str[len] != '\0')
{
write(1, &str[len], 1);
len++;
}
return (len);
}
/**
 * percent_formatter - Prints a percent sign.
 * @args: Unused va_list.
 * Return: Always returns 1.
 */
int percent_formatter(va_list args)
{
(void)args;
write(1, "%", 1);
return (1);
}
/**
 * integer_formatter - Formats and prints an integer.
 * @args: The va_list containing the integer.
 * Return: The number of characters printed.
 */
int integer_formatter(va_list args)
{
int count = 0;
int n = va_arg(args, int);
int rev = 0;
if (n < 0)
{
n = -n;
write(1, "-", 1);
count++;
}
if (n == 0)
{
write(1, "0", 1);
return (1);
}
while (n > 0)
{
rev = rev * 10 + n % 10;
n /= 10;
}
while (rev > 0)
{
char digit = (rev % 10) + '0';
write(1, &digit, 1);
rev /= 10;
count++;
}
return (count);
}
