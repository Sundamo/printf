This printf project is a collaboration between Oluwadamilare Omosanya and Memunat Elegushi. Who are students of the ALX Software Engineering School. This project involves writing a function named "_printf" which would imitate the actual "printf" command located in the stdio.h library. This function contains some of the basic features and functions found in the man 3 of "printf".

What you would learn from this project:

How to use git in a team setting Applying variadic functions to big projects The complexities of printf Managing a lot of files and finding a good workflow Prototype int _printf(const char *format, ...); Usage Prints a string to the standard output, according to a given format All files were created and compiled on Ubuntu 14.04.4 LTS using GCC 4.8.4 with the command gcc -Wall -Werror -Wextra pedantic *.c Returns the number of characters in the output string on success, -1 otherwise Call it this way: _printf("format string", arguments...) where format string can contain conversion specifiers and flags, along with regular characters. The format contains the string that is printed. As _printf() is variadic function, it can receives n arguments that replace by n tags written inside the string.

The format tags prototype is the following:

%[flags][length]specifier If the program runs successfully, the return value is the amount of chars printed.

Specifier Output c Character d or i Decimal integer s String b Binary % Percentage charater o Signed Octal u Unsigned Integer x Unsigned Hexadecimal X Unsigned Hexadecimal (uppercase) p Pointer address r Reversr string of characters R ROT13 translaton of string S String with special chars replaced by their ASCII value Examples Printing the string of chars "Hello ALX School": Input: _printf("Hello %s.", "ALX School"); Output: Hello ALX School

Printing an integer number: Input: _printf("2 + 2 is equal to %d.", 4); Output: 2 + 2 is equal to 4.

Printing a binary: Input: _printf("98 in binary is [%b]", 98); Output: 98 in binary is [1100010]

Authors Oluwadamilare Omosanya @Sundamo and Memunat Elegushi @Auspicious
