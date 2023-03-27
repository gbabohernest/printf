#include "main.h"
#include <stdio.h>

/**
* main - Entry point
*
* Return: Always 0
*/

int main(void)
{
	int test;
	int number;

	number = 199125907;

	test = _printf("%i, %d\n", number, number);
	printf("%d\n", test);
	test = _printf("% ");
	printf("%d\n", test);
	return (0);
}
