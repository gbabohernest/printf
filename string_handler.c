#include "main.h"

/**
* _rot13 - convert a string to rot13
* @arg: string to convert
* Return: converted string
*/

int _rot13(va_list arg)
{
	int count, index;
	char *str;
	char s[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char u[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(arg, char *);

	if (str == NULL)
		return (-1);
	for (count = 0; str[count] != '\0'; count++)
	{
		for (index = 0; index <= 52; index++)
		{
			if (str[count] == s[index])
			{
				_write(u[index]);
				break;
			}
		}
		if (index == 53)
			_write(str[count]);
	}
	return (count);
}

/**
* _print_reversed_string - reverse and print a string
* @arg: string to reverse and print
* Return: amount of characters printed
*/

int _print_reversed_string(va_list arg)
{
	int length;
	char *str, *ptr;

	str = va_arg(arg, char *);

	if (str == NULL)
		return (-1);
	ptr = _rev_string(str);

	if (ptr == NULL)
		return (-1);

	for (length = 0; ptr[length] != '\0'; length++)
	{
		_write(ptr[length]);
	}
	free(ptr);
	return (length);
}
