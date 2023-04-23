#include <stdarg.h>
#include <unistd.h>
#include <string.h>
/**
* _printf - simulate printf task 0
* @format: character string (zero or more directives)
*
* Return: num. of printed characters
* (excluding null byte '\0' used at end of strings)
*/
int _printf(const char *format, ...)
{
int idx = 0, count = 0;
va_list args;  /* Declare variable arguments list */
char c;
char *str;
va_start(args, format); /*Initialize variable arguments*/
while (format && format[idx])  /* Loop via each character in format*/
{
if (format[idx] == '%')  /*if it's a format specifier */
{
idx++;  /* increment to next character after '%' */
switch (format[idx])  /* get format specifier then act*/
{
case 'c':  /* Character specifier */
c = va_arg(args, int);/* must save it to a variable to get address next*/
count += write(1, &c, 1); /*Write char to standard output*/
break;
case 's':  /* String specifier */
str = va_arg(args, char *);/* save it to a variable to write it next*/
count += write(1, str, strlen(str)); /*Write string to standard output*/
break;
case '%':  /* '%' specifier */
va_arg(args, int);
count += write(1, "%", 1); /*Write char to standard output*/
break;
default:  /* Invalid specifier */
write(1, "%", 1);  /* Write '%' chara to standard output */
return (-1);
}
}
else  /*if it's a character that doesn't have % before it*/
{count += write(1, &format[idx], 1);  /* Write character to standard output*/
}
idx++;  /*Move to next character in format*/
}
va_end(args);  /*End variable arguments*/
return (count);  /*Return number of characters printed*/
}
