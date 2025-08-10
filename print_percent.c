#include "main.h"

/**
 * print_percent - prints a literal percent sign (for %%)
 * @ap: variadic list (unused)
 *
 * Return: number of chars written (1), or -1 on error
 */
int print_percent(va_list ap)
{
	(void)ap;

	if (_putchar('%') == -1)
		return (-1);
	return (1);
}
