#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void get_factors(unsigned long int num);
/**
 * main - main function
 * @argc: integer
 * @argv: string
 * Return: Always(0)
 */
int main(int argc, char **argv)
{
	(void) argc;
	unsigned long int num;
	FILE *file;
	size_t size;
	char *line = NULL;

	file = fopen(argv[1], "r");
	while (getline(&line, &size, file) != -1)
	{
		num = atol(line);
		get_factors(num);
	}
	return (0);
}
int prime_number(unsigned long int num);
/**
 * get_factors - Factorize as many numbers as possible into a product
 * @num: unsigned long int
 * Return: void
 */
void get_factors(unsigned long int num)
{
	unsigned long int i = 2, div, x, y;

	while (1)
	{
		if (num % i == 0)
		{
			div = num / i;
			if (prime_number(i) == 1 && prime_number(div) == 1)
			{
				x = i;
				y = div;
			}
			break;
		}
		else
		{
			i++;
		}
	}
	printf("%lu=%lu*%lu \n", num, y, x);
}
/**
 * prime_number - check is the number is priùme or not
 * A prime number (or a prime) is a natural number greater than 1
 * that is not a product of two smaller natural numbers.
 * @num: unsigned long int
 * Return: 1 on succeess -1 on failure
 */
int prime_number(unsigned long int num)
{
	unsigned long int i = 2;
	/* check for factors */
	while (i < num)
	{
		if ((num % i) == 0)
			return (-1);
		i++;
	}
	return (1);
}
