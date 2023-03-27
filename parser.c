#include "main.h"

/**
* parser - Parse the given string and print a formatted string
* @format: String to be parsed
* @fun_list: List of all the possible functions that will
*	be use to parse the given string
* @arg_list: List of all arguments passed
* Return: Total count of characters printed
*/
int parser(const char *format, asoc_fun fun_list[], va_list arg_list)
{
	int chars_printed, i, j, val;

	chars_printed = 0;

	/*Iterate through the given string*/
	for (i = 0; format[i] != '\0'; i++)
	{
		/*check for format specifiers*/
		if (format[i] == '%')
		{
			/*Iterate through struct checker to find the right function*/
			for (j = 0; fun_list[j].fmt != NULL; j++)
			{
				if (format[i + 1] == fun_list[j].fmt[0])
				{
					val = fun_list[j].fptr(arg_list);
					if (val == -1)
						return (-1);
					chars_printed += val;
					break;
				}
			}
			if (fun_list[j].fmt == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_write(format[i]);
					_write(format[i + 1]);
					chars_printed = chars_printed + 2;
				}
				else
				{
					return (-1);
				}
			}
			/*update i to skip format specifier*/
			i = i + 1;
		}
		else
		{
			/*call the _write function */
			_write(format[i]);
			chars_printed++;
		}
	}
	return (chars_printed);
}
