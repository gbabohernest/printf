#include "main.h"
#include <stdio.h>

/**
* _print_binary - A function that converts a number
*		from base 10 to binary
* @args: Arguments list
* Return: Tota lenght of numbers printed
*/

int _print_binary(va_list args)
{
	unsigned int n;
	int count, len;
	char *str;
	char *reverse_str;

	n = va_arg(args, unsigned int);
	if (n == 0)
		return (_write('0'));
	if (n < 1)
		return (-1);
	len = _base_len(n, 2);
	str = malloc(sizeof(char) * len + 1);

	if (str == NULL)
		return (-1);
	for (count = 0; n > 0; count++)
	{
		if (n % 2 == 0)
		{
			str[count] = '0';
		}
		else
		{
			str[count] = '1';
		}
		n = n / 2;
	}
	str[count] = '\0';
	reverse_str = _rev_string(str);

	if (reverse_str == NULL)
		return (-1);

	_write_base(reverse_str);
	free(str);
	free(reverse_str);
	return (len);
}
