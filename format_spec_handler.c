#include "main.h"

/**
* _print_char - Prints character to the standard output
* @c: Character to be printed
* Return: Amount of characters printed
*/

int _print_char(va_list c)
{
	_write(va_arg(c, int));
	return (1);
}

/**
* _print_string - Prints a string to standard output
* @str: String to be printed
* Return: Amount of characters printed
*/

int _print_string(va_list str)
{
	int count = 0;
	char *string;

	string = va_arg(str, char *);
	if (string == NULL)
		string = "(null)";
	while (string[count] != '\0')
	{
		_write(string[count]);
		count++;
	}
	return (count);
}

/**
* _print_percent - Prints a percent ' % ' symbol
* @list: Arguments list of numbers
* Return: The printed character
*/
int _print_percent(__attribute__((unused))va_list list)
{
	_write('%');
	return (1);
}


/**
 * _print_integer - Prints an integer
 * @args: list of arguments
 * Return: Will return the amount of characters printed.
 */

int _print_integer(va_list args)
{
	int number_length;

	number_length = _print_number(args);
	return (number_length);
}


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
	str = malloc(bits * sizeof(char));

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
