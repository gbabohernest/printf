#include "main.h"
#include <stdio.h>

/**
* main - Entry point
*
* Return: 0 (success)
*/

int main(void)
{
	unsigned int a;
	int b;

	a = -8;
	b = _printf("%u\n", a);
	_printf(">%i\n", b);
	b = printf("%u\n", a);
	printf(">%i\n", b);
	return (0);
}
