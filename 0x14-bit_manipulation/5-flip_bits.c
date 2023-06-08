#include "main.h"

/**
 * flip_bits - counts the number of bits to change
 * to get from one number to another
 * @f: first number
 * @s: second number
 *
 * Return: number of bits to change
 */
unsigned int flip_bits(unsigned long int f, unsigned long int s)
{
	int i, j = 0;
	unsigned long int current;
	unsigned long int exclusive = f ^ s;

	for (i = 63; i >= 0; i--)
	{
		current = exclusive >> i;
		if (current & 1)
			j++;
	}

	return (j);
}
