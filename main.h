#ifndef _PRINTF_H
#define _PRINTF_H
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int _printf(const char *format, ...);
int _putchar(char c);
int _printwformat(const char *format, int idx, int count, va_list args);
int print_integer(int x);
int print_binary(unsigned int dnum);
#endif
