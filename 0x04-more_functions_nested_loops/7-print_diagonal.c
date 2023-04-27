#include "main.h"
/**
 * print_diagonal - function with one integer argument
 * @n: 1st int type argument
 *
 * Description: draw a diagonal line on terminal with loops
 * Return: na
 */
void print_diagonal(int n)
{
	int i, j;

	i = 0;
	if (n > 0)
	{
		while (i < n)
		{
			j = 0;
			while (j <= i - 1)
			{
				_putchar(' ');
				j++;
			}
			_putchar('\\');
			_putchar('\n');
			i++;
		}
	} else
		_putchar('\n');
}

