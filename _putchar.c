#include <unistd.h>
/**
 * _putchar - Write a char to stdout
 * @c: Character to be printed
 *
 * Return: 1 on success, else -1
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}
