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
