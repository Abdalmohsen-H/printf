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
