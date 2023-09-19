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
/**
 * _printf - A custom implementation of printf.
 * @format: The format string.
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
va_list args;
int chars_printed = 0;
va_start(args, format);
while (*format)
{
if (*format == '%')
{
format++;
if (*format == '\0')
break;
switch (*format)
if (*format == 'd' || *format == 'i')
{
chars_printed += integer_formatter(args);
}
else
{
write(1, format - 1, 1);
write(1, format, 1);
chars_printed += 2;
}
}
else
{
write(1, format, 1);
chars_printed++;
}
format++;
}
va_end(args);
return (chars_printed);
}
