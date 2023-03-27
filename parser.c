#include "main.h"
/**
* parser - Parse the given string and print a formatted string
* @format: String to be parsed
* @fun_list: List of all the possible parse functions
* @arg_list: List of all arguments passed
* Return: Total count of characters printed
*/
int parser(const char *format, asoc_fun fun_list[], va_list arg_list)
{
	int chars_printed, i, j, val;

	chars_printed = 0;
	for (i = 0; format[i] != '\0'; i++)/*Iterate through the given string*/
	{
		if (format[i] == '%')/*check for format specifiers*/
		{
			for (j = 0; fun_list[j].fmt != NULL; j++)/*iterate to find the right fun*/
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
				{	_write(format[i]);
					_write(format[i + 1]);
					chars_printed = chars_printed + 2;
				}
				else
					return (-1);
			}
			i = i + 1;/*update i to skip format specifier*/
		}
		else
			_write(format[i]);/*call the write function*/
			chars_printed++;
	}
	return (chars_printed);
}
