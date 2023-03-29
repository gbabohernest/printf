#include "main.h"
#include <stdio.h>
#include <limits.h>

/**
* main - Entry point
*
* Return: 0 (success)
*/

int main(void)
{
	int x;

	x = _printf("%R\n", "hello");
	_printf("%d\n", x);
	x = printf("%s\n", "hello");
	printf("%d\n", x);
	x = _printf("%R\n", "ALX SE Program");
	printf("%d\n", x);
	return (0);
}
