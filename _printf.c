#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include "main.h"
/**
* _printwformat - rint with format
* @format: character string (zero or more directives)
* @idx: arg index
* @count: printed char counter
* @args: variable argument list
* Return: num. of printed characters
* (excluding null byte '\0' used at end of strings)
*/
int _printwformat(const char *format, int idx, int count, va_list args)
{/* char c;*/
char *str;/*, *valid_specifiers = "cs%";*/

if (format[idx] == '%')
{
int c = format[idx];
_putchar(c);
count++;
}
if (format[idx] == 'c')
{
int c = va_arg(args, int);
_putchar(c);
count++;
}
if (format[idx] == 's')
{
int z = 0;
str = va_arg(args, char *);
if (!str)
{str = "(null)";
}
for (z = 0; str[z]; z++)
{_putchar(str[z]);
}
count += z;
}
if (format[idx] == 'd' || format[idx] == 'i')
{
count += _printnum(args);
}
return (count);
}
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
{int c = va_arg(args, int);
_putchar(c);/* Write character to standard output*/
count++;
}
}
va_end(args);  /*End variable arguments*/
return (count);  /*Return number of characters printed*/
}
/**
*_printnum - print integers
* and count printed chars inside it only
*@args: variable arguments list
*Return: number of printed chars inside it only
*/
int _printnum(va_list args)
{int x = va_arg(args, int);
unsigned int num, rev_num;
int counter = 0;

if (x < 0)
{
counter += _putchar('-');
num = -x;
}
else
{num = x;
}
if (num == 0)
{return (_putchar('0'));
}
while (num > 0)
{
rev_num = rev_num * 10 + num % 10;
num = num / 10;
}
while (rev_num > 0)
{
_putchar(rev_num % 10 + '0');
counter++;
rev_num = rev_num / 10;
}
return (counter);
}
