#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * unsigned_integer - Formats and prints a character.
 * @args: The va_list containing the character.
 * Return: The number of characters printed.
 */

int unsigned_integer_formatter(va_list args)
{
    int count = 0;
    unsigned int n = va_arg(args, unsigned int);
    unsigned int rev = 0;

    if (n == 0)
    {
        write(1, "0", 1);
        return 1;
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

    return count;
}

/**
 * octal_formatter - Formats and prints a character.
 * @args: The va_list containing the character.
 * Return: The number of characters printed.
 */

int octal_formatter(va_list args)
{
    int count = 0;
    unsigned int n = va_arg(args, unsigned int);
    char octal[100];
    int i = 0;

    if (n == 0)
    {
        write(1, "0", 1);
        return 1;
    }

    while (n > 0)
    {
        octal[i++] = (n % 8) + '0';
        n /= 8;
    }

    for (i = i - 1; i >= 0; i--)
    {
        write(1, &octal[i], 1);
        count++;
    }

    return count;
}

/**
 * hex_formatter - Formats and prints a character.
 * @args: The va_list containing the character.
 * Return: The number of characters printed.
 */

int hex_formatter(va_list args, int uppercase)
{
    int count = 0;
    unsigned int n = va_arg(args, unsigned int);
    char hex[100];
    int i = 0;

    if (n == 0)
    {
        write(1, "0", 1);
        return 1;
    }

    while (n > 0)
    {
        int remainder = n % 16;
        hex[i++] = (remainder < 10) ? (remainder + '0') : (remainder - 10 + (uppercase ? 'A' : 'a'));
        n /= 16;
    }

    for (i = i - 1; i >= 0; i--)
    {
        write(1, &hex[i], 1);
        count++;
    }

    return count;
}

/* To handle 'x' */
int lowercase_hex_formatter(va_list args)
{
    return hex_formatter(args, 0);
}

/* To handle 'X'*/
int uppercase_hex_formatter(va_list args)
{
    return hex_formatter(args, 1);
}

case 'u':
    chars_printed += unsigned_integer_formatter(args);
    break;
case 'o':
    chars_printed += octal_formatter(args);
    break;
case 'x':
    chars_printed += lowercase_hex_formatter(args);
    break;
case 'X':
    chars_printed += uppercase_hex_formatter(args);
    break;

