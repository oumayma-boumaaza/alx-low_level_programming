#include "main.h"

/**
 * more_numbers - function with no arguments
 *
 * Description: nested while loops to print from 0 to 14
 * Return: na
 */
void more_numbers(void)
{
	int i, j;

	i = 0;
	while (i <= 9)
	{
		j = 0;
		while (j <= 14)
		{
			if (j > 9)
			{
				_putchar(j / 10 + '0');
			}
			_putchar(j % 10 + '0');
			j++;
		}
		i++;
		_putchar('\n');
	}
}
