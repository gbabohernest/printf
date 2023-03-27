#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

/**
* struct checker - defines a structure for format specifiers
*		and associated functions
*
* @fmt: The format specifier
* @fptr: Function pointer of
*	associated functions
*
*/
struct checker
{
	char *fmt;
	int (*fptr)(va_list);
};
typedef struct checker asoc_fun;

/*functions*/
int parser(const char *format, asoc_fun fun_list[], va_list arg_list);
int _printf(const char *format, ...);
int _write(char);
int _print_char(va_list);
int _print_string(va_list);
int _print_percent(va_list);
int _print_integer(va_list);
int _print_number(va_list);
int _print_binary(va_list args);
int _putchar(char c);


#endif
