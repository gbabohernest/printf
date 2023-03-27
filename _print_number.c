#include "main.h"

/**
* _print_number - a function that prints a given number
* @num_list: list of numbers to be printed
* Return: total count of printed numbers
*/

int _print_number(va_list num_list)
{
	int num, division, length;
	unsigned int number;

	num = va_arg(num_list, int);
	division = 1;
	length = 0;

	if (num < 0)
	{
		length += _write('-');
		number = num * -1;
	}
	else
	{
		number = num;
	}
	for (; number / division > 9;)
	{
		division *= 10;
	}
	for (; division != 0;)
	{
		length += _write('0' + number / division);
		number %= division;
		division /= 10;
	}
	return (length);
}



/**
* _print_unsigned_number - a function that prints unsigned number
* @n: unsigned int to be printed
* Return: Total numbers to be printed
*/

int _print_unsigned_number(unsigned int n)
{
	int division, length;
	unsigned int num;

	division = 1;
	length = 0;

	num = n;
	for (; num / division > 9;)
	{
		division *= 10;
	}
	for (; division != 0;)
	{
		length += _write('0' + num / division);
		num %= division;
		division /= 10;
	}
	return (length);
}
