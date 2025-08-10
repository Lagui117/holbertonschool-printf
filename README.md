# _printf - Holberton School Project

## Description
This project is a custom implementation of the standard C library function `printf`.  
It is part of the Holberton School curriculum to practice handling variadic functions,  
understanding format specifiers, and working collaboratively in a group project.

In this version, `_printf` supports the following format specifiers:
- `%c` : print a single character
- `%s` : print a string of characters
- `%%` : print a percent sign
- `%d` : print a signed decimal integer
- `%i` : print a signed decimal integer (same as `%d`)

The function writes output to `stdout` using the `write` system call.

---

## Prototype
```c
int _printf(const char *format, ...);

