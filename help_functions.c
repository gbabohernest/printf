#include "main.h"
#include <stdio.h>

/**
* _rev_string - Reverses a string
* @str: string to reverse
* Return: a pointer to a character
*/
char *_rev_string(char *str)
{
	int str_len, head;
	char tmp, *dest;

	for (str_len = 0; str[str_len] != '\0'; str_len++)
	{}
	dest = malloc(sizeof(char) * str_len + 1);
	if (dest == NULL)
		return (NULL);
	_memory_cpy(dest, str, str_len);
	for (head = 0; head < str_len; head++, str_len--)
	{
		tmp = dest[str_len - 1];
		dest[str_len - 1] = dest[head];
		dest[head] = tmp;
	}
	return (dest);
}

/**
* _base_len - Calculates the length for a number
* @num: number for which length is to be calculated
* @base: base to be use in calculation
* Return: an integer representing length of a number
*/
unsigned int _base_len(unsigned int num, int base)
{
	unsigned int i;

	for (i = 0; num > 0; i++)
	{
		num = num / base;
	}
	return (i);
}

/**
* _write_base - write characters to the stdout
* @str: parse string
* Return: nothing(void)
*/
void _write_base(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_write(str[i]);
	}
}

/**
* _memory_cpy - copy memory area
* @dest: destination for copied memory
* @src: source to copy form
* @n: number of bytes to copy
* Return: a pointer to destination
*/
char *_memory_cpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
