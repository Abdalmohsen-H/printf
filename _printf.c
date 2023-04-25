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
{unsigned int dnum;
char *str;/*, *valid_specifiers = "cs%idb";*/
int c, z, x;

if (format[idx] == '%')
{c = format[idx];
_putchar(c);
count++;
}
else if (format[idx] == 'c')
{c = va_arg(args, int);
_putchar(c);
count++;
}
else if (format[idx] == 's')
{z = 0;
str = va_arg(args, char *);
if (!str)
{str = "(null)";
}
for (z = 0; str[z]; z++)
	_putchar(str[z]);
count += z;
}
else if (format[idx] == 'd' || format[idx] == 'i')
{x = va_arg(args, int);
count += print_integer(x);
}
else if (format[idx] == 'b')
{dnum = va_arg(args, int);
count += print_binary(dnum);
}
else
{count += 2;
_putchar('%');
_putchar(format[idx]);
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
{_putchar(format[idx]);/* Write character to standard output*/
count++;
}
}
va_end(args);  /*End variable arguments*/
return (count);  /*Return number of characters printed*/
}
/**
*print_integer - print integers
* and count printed chars inside it only
*@x: integer input from variable arguments list
*Return: number of printed chars inside it only
*/
int print_integer(int x)
{unsigned int num;
int counter = 0;

if (x < 0)
{
_putchar('-');
counter++;
num = -1 * x;
}
else
{num = x;
}
if (num == 0)
{counter++;
return (_putchar('0'));
}
if (num / 10)/*if more than 2 digits*/
{/*we will use recursion to print*/
/*the most left digit from input first*/
counter += print_integer(num / 10);
}
/*now we only have one digit let's handle it*/
counter += _putchar((num % 10) + '0');
return (counter);
}

/**
*print_binary - print binary of decimal input
* and count printed chars inside it only
*@x: integer input from variable arguments list
*Return: number of printed chars inside it only
*/
int print_binary(unsigned int dnum)
{unsigned int num = dnum;
int counter = 0;

if (num == 0)
{counter++;
return (_putchar('0'));
}
if (num / 2)/*binary use base of 2*/
{/*we will use recursion to print*/
/*the most left digit of coverted binary*/
counter += print_binary(num / 2);
}
/*now we only have one binary digit let's handle it*/
_putchar((num % 2) + '0');
counter++;
return (counter);
}
