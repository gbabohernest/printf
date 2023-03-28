#include "main.h"

/**
* _printf - Prints a formatted string to stdout
* @format: Character(s) string to be printed
*	may contain directives
* @..: variadic args (unknown)
*
* Return: Numbers of characters printed.
*/

int _printf(const char *format, ...)
{
	int chars_printed;

	/*list of function according to format specifier*/
	asoc_fun fun_list[] = {

		{"c", _print_char},
		{"s", _print_string},
		{"%", _print_percent},
		{"d", _print_integer},
		{"i", _print_integer},
		{"b", _print_binary},
		{"u", _unsigned_integer},
		{"o", _print_octal},
		{"x", _print_hex},
		{"X", _print_HEX},
		{NULL, NULL}
	};
	va_list arg_list;

	/*check for NULL pointer*/
	if (format == NULL)
	{
		return (-1);
	}
	va_start(arg_list, format);

	/*parse the string using parse function*/
	chars_printed = parser(format, fun_list, arg_list);
	va_end(arg_list);
	return (chars_printed);
}
