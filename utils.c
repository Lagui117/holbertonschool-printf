#include "main.h"

/**
 * _putchar - writes a single character to stdout
 * @c: character to write
 *
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
	ssize_t w = write(1, &c, 1);

	if (w == 1)
		return (1);
	return (-1);
}

/**
 * _strlen - returns the length of a string
 * @s: string
 *
 * Return: length, 0 if s is NULL
 */
size_t _strlen(const char *s)
{
	size_t len = 0;

	if (s == NULL)
		return (0);

	while (s[len] != '\0')
		len++;
	return (len);
}

/**
 * _putstr - writes a C-string to stdout
 * @s: string to write; if NULL prints "(null)"
 *
 * Return: number of chars written, or -1 on error
 */
int _putstr(const char *s)
{
	size_t i;
	const char *nulls = "(null)";

	if (s == NULL)
		s = nulls;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (_putchar(s[i]) == -1)
			return (-1);
	}
	return ((int)i);
}

/**
 * _putnumber - prints a signed long number in base 10
 * @n: number
 *
 * Return: number of chars written, or -1 on error
 */
int _putnumber(long n)
{
	int count = 0;
	unsigned long u;

	if (n < 0)
	{
		if (_putchar('-') == -1)
			return (-1);
		count++;
		u = (unsigned long)(-n);
	}
	else
	{
		u = (unsigned long)n;
	}

	/* print digits recursively */
	if (u >= 10)
	{
		int high = _putnumber((long)(u / 10));

		if (high == -1)
			return (-1);
		count += high;
	}

	if (_putchar((char)('0' + (u % 10))) == -1)
		return (-1);

	return (count + 1);
}
