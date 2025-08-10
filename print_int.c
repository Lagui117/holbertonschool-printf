#include "main.h"

/**
 * print_int - prints a signed integer in base 10 (for %d and %i)
 * @ap: variadic list
 *
 * Return: number of chars written, or -1 on error
 */
int print_int(va_list ap)
{
	long n = (long)va_arg(ap, int);

	return (_putnumber(n));
}
