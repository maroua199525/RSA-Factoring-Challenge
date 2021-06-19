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
		num = atoi(line);
		get_factors(num);
	}
	return (0);
}
/**
 * get_factors - Factorize as many numbers as possible into a product
 * @num: unsigned long int
 * Return: void
 */
void get_factors(unsigned long int num)
{
	int i = 2, div;

	while (1)
	{
		if (num % i == 0)
		{
			div = num / i;
			break;
		}
		else
		{
			i++;
		}
	}
	printf("%lu=%d*%d \n", num, div, i);
}
