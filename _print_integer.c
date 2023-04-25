#include "main.h"
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
