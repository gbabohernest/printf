#include "main.h"

/**
 * _print_binary - Prints the binary representation of an unsigned integer.
 * @args: A va_list containing a single unsigned int argument.
 *
 * Return: The number of characters printed.
 */
int _print_binary(va_list args)
{
unsigned int num = va_arg(args, unsigned int);
int bits = 0, i, chars_printed = 0;
char *str;

/* Count the number of bits in the binary representation */
for (i = 0; i < 32; i++)
{
if ((num >> i) & 1)
bits = i + 1;
}

/* Allocate memory for the binary string */
str = malloc(bits *sizeof(char));

if (str == NULL)
return (-1);

/* Convert the number to binary and store it in the string */
for (i = bits - 1; i >= 0; i--)
{
str[i] = (num & 1) ? '1' : '0';
num >>= 1;
}

/* Print the binary string */
for (i = 0; i < bits; i++)
{
chars_printed += _putchar(str[i]);
}

free(str);
return (chars_printed);
}
