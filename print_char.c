#include "main.h"

/**
 * print_char - prints a single character (for %c)
 * @ap: variadic list
 *
 * Return: number of chars written (1), or -1 on error
 */
int print_char(va_list ap)
{
	int c = va_arg(ap, int);

	if (_putchar((char)c) == -1)
		return (-1);
	return (1);
}
