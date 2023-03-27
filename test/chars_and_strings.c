#include "main.h"
#include <stdio.h>

/**
* main - Entry Point
* 
* Description: Test _printf function for
*	correct output
* 
* Return: 0 (success)
*/

int main(void)
{
	char a;
	char *b;
	
	a = 'H';
	b = "Hello";
	a = _printf("%c, %s\n", a, b);
	_printf("%s\n", "hello");
	_printf("%%\n");
	/*printf("%c, %s\n", a, b);*/
	return (0);
}
