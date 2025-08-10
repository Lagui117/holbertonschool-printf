#ifndef _PRINTF_MAIN_H_
#define _PRINTF_MAIN_H_

/*
 * File: main.h
 * Auth: Your Names
 * Desc: Prototypes and types for the holbertonschool-printf project.
 */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

/**
 * struct fmt_spec - mapping between a specifier and its printer function
 * @spec: the conversion specifier character (e.g. 'c', 's', '%', 'd', 'i')
 * @print: function that prints the corresponding argument
 *
 * Each print function must consume its argument from va_list and
 * return the number of characters written, or -1 on error.
 */
typedef struct fmt_spec
{
	char spec;
	int (*print)(va_list ap);
} fmt_spec_t;

/* ========= Public API ========= */
int _printf(const char *format, ...);

/* ========= Printers (one per specifier) ========= */
int print_char(va_list ap);     /* %c */
int print_string(va_list ap);   /* %s */
int print_percent(va_list ap);  /* %% */
int print_int(va_list ap);      /* %d and %i */

/* ========= Dispatcher ========= */
int handle_specifier(char spec, va_list ap);

/* ========= Low-level output helpers ========= */
int _putchar(char c);                 /* writes a single character */
int _putstr(const char *s);           /* writes a C-string (NULL -> "(null)") */
int _putnumber(long n);               /* writes a signed number in base 10 */

/* ========= Small utils ========= */
size_t _strlen(const char *s);

#endif /* _PRINTF_MAIN_H_ */
