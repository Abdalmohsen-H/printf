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
char c;
char *str;/*, *valid_specifiers = "cs%";*/

va_start(args, format); /*Initialize variable arguments*/
if (!format || (format[0] == '%' && format[1] == '\0'))
	return (-1);
/**
*for (; format && format[idx] && format[idx] == '%'; idx++)
*{/-*check if there invalid specifier *-/
*if (strchr(valid_specifiers, format[idx + 1]) == NULL)
*{va_end(args);
*return (-1);/-* Invalid specifier *-/
*}
*}
*/
for (; format && format[idx]; idx++) /*loop format chars and print*/
{
if (format[idx] == '%')  /*if it's a format specifier */
{idx++;  /* increment to next character after '%' */
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
default:  /* Invalid specifier */
count += write(1, "%", 1);  /* Write '%' chara to standard output */
va_end(args);
return (-1);
}
}
else  /*if it's a character that doesn't have % before it*/
{count += write(1, &format[idx], 1);  /* Write character to standard output*/
}
}
va_end(args);  /*End variable arguments*/
return (count);  /*Return number of characters printed*/
}
