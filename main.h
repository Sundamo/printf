#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
int _putchar(char c);
int _printf(const char *format, ...);
int integer_formatter(va_list args);
int percent_formatter(va_list args);
int string_printer(va_list args);
int format_character(va_list args);

int unsigned_integer_formatter(va_list args);
int octal_formatter(va_list args);
int hex_formatter(va_list args, int uppercase);
int lowercase_hex_formatter(va_list args);
int uppercase_hex_formatter(va_list args);
#endif
