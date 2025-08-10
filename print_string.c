#include "main.h"

/**
 * print_string - prints a C string (for %s)
 * @ap: variadic list
 *
 * Return: number of chars written, or -1 on error
 */
int print_string(va_list ap)
{
	char *s = va_arg(ap, char *);

	return (_putstr(s));
}
