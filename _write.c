#include "main.h"

/**
* _write - Write character to the standard output
* @c: character arg to be printed
*
* Return: 1 on success, -1 on error
*/

int _write(char c)
{
	return (write(1, &c, 1));
}
