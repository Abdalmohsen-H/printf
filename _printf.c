#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include "main.h"
/**
* _printf - simulate printf task 0
* @format: character string (zero or more directives)
*
* Return: num. of printed characters
* (excluding null byte '\0' used at end of strings)
*/
int _printf(const char *format, ...)
{int idx = 0, count = 0;
va_list args;  /* Declare variable arguments list */

va_start(args, format); /*Initialize variable arguments*/
if (!format || (format[0] == '%' && format[1] == '\0'))
return (-1);
for (; format && format[idx]; idx++) /*loop format chars and print*/
{
if (format[idx] == '%')  /*if it's a format specifier */
{idx++;  /* increment to next character after '%' */
if (format[idx] == '\0' || (format[idx] == ' ' && !format[idx + 1]))
{/*if % is last char and no other % before it or it just "% "*/
va_end(args);
return (-1);
}
count = _printwformat(format, idx, count, args);/*addation inside func*/
}
else  /*if it's a character that doesn't have % before it*/
{_putchar(format[idx]);/* Write character to standard output*/
count++;
}
}
va_end(args);  /*End variable arguments*/
return (count);  /*Return number of characters printed*/
}
