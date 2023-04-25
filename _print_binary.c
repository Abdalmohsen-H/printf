#include "main.h"
/**
*print_binary - print binary of decimal input
* and count printed chars inside it only
*@dnum: integer input from variable arguments list
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
