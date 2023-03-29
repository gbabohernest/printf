#include "main.h"

/**
 * print_buffered - Prints a formatted string to a buffer
 * @buffer: Pointer to the buffer to store the formatted string
 * @format: Character(s) string to be printed
 *          may contain directives
 * @...: Variadic args (unknown)
 *
 * Return: Numbers of characters printed.
 */

int print_buffered(char *buffer, const char *format, ...)
{
	int chars_printed = 0;
	asoc_fun fun_list[] = {
		{"c", _print_char},
		{"s", _print_string},
		{"%", _print_percent},
		{"d", _print_integer},
		{"i", _print_integer},
		{NULL, NULL}
	};
	va_list arg_list;
	size_t buffer_index = 0;

	va_start(arg_list, format);

	while (*format != '\0')
	{
		if (*format != '%')
		{
			buffer[buffer_index++] = *format;
			chars_printed++;
		}
		else
		{
			format++;
			chars_printed += parser(format, fun_list, arg_list);
			format++;
		}

		if (buffer_index >= 1023)
		{
			write(1, buffer, buffer_index);
			buffer_index = 0;
		}
	}
	write(1, buffer, buffer_index);
	va_end(arg_list);
	return (chars_printed);
}
