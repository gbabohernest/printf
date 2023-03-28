#include "main.h"
#include <stdio.h>

/**
* main - Entry point
*
* Return: 0 (success)
*/

int main(void)
{
	int a, b;

	a = 145;

	b = _printf("%o\n", a);
	printf("> %i\n", b);
	printf("%o\n", a);
	return (0);

