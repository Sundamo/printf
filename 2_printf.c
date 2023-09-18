#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
/**
 * _printf - Custom printf function
 * @format: The format string containing zero or more directives.
 * This function handles the '%d' or '%i' format specifier.
 *
 * Return: The number of characters printed (excluding the null byte,
 * used to end output to strings), or returns -1 on error.
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
int error_code = 0;
int idx = 0;
va_start(args, format);
while (format[idx] != '\0')
{
if (format[idx] == '%')
{
idx++;
if (format[idx] == 'd' || format[idx] == 'i')
{
int n = va_arg(args, int);
putchar(n);
count++;
}
else
{
putchar('%');
putchar(format[idx]);
count ++;
}
}
else
{
putchar(format[idx]);
count++;
}
idx++;
}
va_end(args);
if (error_code != 0)
return (-1);
else
return (count);
}
