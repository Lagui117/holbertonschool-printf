#include "main.h"

/**
 * _printf - custom printf, prints according to a format string
 * @format: format string with directives
 *
 * Return: number of characters printed, or -1 on error
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int count = 0;
	int i;

	if (format == NULL)
		return (-1);

	va_start(ap, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			if (_putchar(format[i]) == -1)
			{
				va_end(ap);
				return (-1);
			}
			count++;
			continue;
		}

		/* format[i] == '%' */
		i++;
		if (format[i] == '\0') /* trailing '%' error */
		{
			va_end(ap);
			return (-1);
		}

		{
			int wrote = handle_specifier(format[i], ap);

			if (wrote == -1)
			{
				va_end(ap);
				return (-1);
			}
			count += wrote;
		}
	}

	va_end(ap);
	return (count);
}

/**
 * handle_specifier - dispatches a specifier to its printer
 * @spec: the specifier character
 * @ap: variadic arguments list
 *
 * Return: number of chars written, or -1 on error
 */
int handle_specifier(char spec, va_list ap)
{
	int j;
	fmt_spec_t table[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'d', print_int},
		{'i', print_int},
		{'\0', NULL}
	};

	for (j = 0; table[j].spec != '\0'; j++)
	{
		if (table[j].spec == spec)
			return (table[j].print(ap));
	}

	/* Unknown specifier: print '%' then the spec literally */
	if (_putchar('%') == -1)
		return (-1);
	if (_putchar(spec) == -1)
		return (-1);
	return (2);
}
