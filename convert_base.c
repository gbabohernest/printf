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

/**
* _print_octal - Prints a number in octal base
* @args: List of all the arguments
* Return: total number printed
*/

int _print_octal(va_list args)
{
	unsigned int num;
	int length;
	char *octal_rep;
	char *rev_str;

	num = va_arg(args, unsigned int);

	if (num == 0)
		return (_write('0'));
	if (num < 1)
		return (-1);

	length = _base_len(num, 8);
	octal_rep = malloc(sizeof(char) * length + 1);

	if (octal_rep == NULL)
		return (-1);
	for (length = 0; num > 0; length++)
	{
		octal_rep[length] = (num % 8) + 48;
		num = num / 8;
	}

	octal_rep[length] = '\0';
	rev_str = _rev_string(octal_rep);

	if (rev_str == NULL)
		return (-1);

	_write_base(rev_str);
	free(octal_rep);
	free(rev_str);
	return (length);
}

/**
* _print_hex - Prints number in base16 lowercase
* @args: arguments list
* Return: total numbers printed
*/

int _print_hex(va_list args)
{
	unsigned int num;
	int length, rem_num;
	char *hex_rep;
	char *rev_hex;

	num = va_arg(args, unsigned int);

	if (num == 0)
		return (_write('0'));
	if (num < 1)
		return (-1);

	length = _base_len(num, 16);
	hex_rep = malloc(sizeof(char) * length + 1);

	if (hex_rep == NULL)
		return (-1);
	for (length = 0; num > 0; length++)
	{
		rem_num = num % 16;

		if (rem_num > 9)
		{
			rem_num = _hex_checker(rem_num, 'x');
			hex_rep[length] = rem_num;
		}
		else
			hex_rep[length] = rem_num + 48;

		num = num / 16;
	}
	hex_rep[length] = '\0';
	rev_hex = _rev_string(hex_rep);

	if (rev_hex == NULL)
		return (-1);
	_write_base(rev_hex);
	free(hex_rep);
	free(rev_hex);
	return (length);
}

/**
* _print_HEX - Prints a number in base16 Uppercase
* @args: list of arguments
* Return: total characters
*/
int _print_HEX(va_list args)
{
	unsigned int num;
	int length;
	int rem_num;
	char *hex_rep;
	char *rev_hex;

	num = va_arg(args, unsigned int);

	if (num == 0)
		return (_write('0'));
	if (num < 1)
		return (-1);

	length = _base_len(num, 16);
	hex_rep = malloc(sizeof(char) * length + 1);

	if (hex_rep == NULL)
		return (-1);
	for (length = 0; num > 0; length++)
	{
		rem_num = num % 16;

		if (rem_num > 9)
		{
			rem_num = _hex_checker(rem_num, 'X');
			hex_rep[length] = rem_num;
		}
		else
			hex_rep[length] = rem_num + 48;
		num = num / 16;
	}
	hex_rep[length] = '\0';
	rev_hex = _rev_string(hex_rep);

	if (rev_hex == NULL)
		return (-1);
	_write_base(rev_hex);
	free(hex_rep);
	free(rev_hex);
	return (length);
}

/**
* _hex_checker - checks which hex function to use
* @num: number to convert into letter
* @c: tell which hex function to use
* Return: ASCII value for a letter
*/

int _hex_checker(int num, char c)
{
	char *hex = "abcdef";
	char *HEX = "ABCDEF";

	num = num - 10;

	if (c == 'x')
		return (hex[num]);
	else
		return (HEX[num]);
	return (0);
}
