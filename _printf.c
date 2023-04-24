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
{char c;
char *str;/*, *valid_specifiers = "cs%";*/
switch (format[idx])  /* get format specifier then act*/
{
case 'c':  /* Character specifier */
c = va_arg(args, int);/* must save it to a variable to get address next*/
count += write(1, &c, 1); /*Write char to standard output*/
break;
case 's':  /* String specifier */
str = va_arg(args, char *);/* save it to a variable to write it next*/
if (!str)
	str = "(null)";
count += write(1, str, strlen(str)); /*Write string to standard output*/
break;
case '%':  /* '%' specifier */
va_arg(args, int);
count += write(1, "%", 1); /*Write char to standard output*/
break;
case 'd':
count += _printnum(args);
break;
case 'i':
count += _printnum(args);
break;
default:  /* Invalid specifier */
count += write(1, "%", 1);  /* Write '%' chara to standard output */
/* Write invalid char to stdout*/
count += write(1, &format[idx], 1);
va_end(args);
return (-1);
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
if (format[0] == '%' && format[1] == ' ' && !format[2])
	return (-1);
for (; format && format[idx]; idx++) /*loop format chars and print*/
{
if (format[idx] == '%')  /*if it's a format specifier */
{idx++;  /* increment to next character after '%' */
if (format[idx] == '\0')
{/*if % is last char and no other % before it or it just "% "*/
va_end(args);
return (-1);
}
count = _printwformat(format, idx, count, args);/*addation inside func*/
}
else  /*if it's a character that doesn't have % before it*/
{count += write(1, &format[idx], 1);  /* Write character to standard output*/
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
