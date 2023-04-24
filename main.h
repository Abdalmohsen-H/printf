#ifndef printf_header
#define printf_header
#include <stdarg.h>
int _printf(const char *format, ...);
int _putchar(char c);
int _printwformat(const char *format, int idx, int count, va_list args);
int _printnum(va_list args);
#endif
