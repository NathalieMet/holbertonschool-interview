#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void print_number(int n)
{
    if (n / 10) {
        print_number(n / 10);
    }
    _putchar((n % 10) + '0');
}

int is_digit_str(char *str)
{
    while (*str) {
        if (!isdigit(*str)) {
            return (0);
        }
        str++;
    }
    return (1);
}

void mul(int argc, char *argv[])
{
	if (argc != 3) {
		printf("Error\n");
		exit(98);
	}

  if (!is_digit_str(argv[1]) || !is_digit_str(argv[2])) {
        printf("Error\n");
        exit(98);
    }

	int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);

	int result = num1 * num2;

	print_number(result);
    _putchar('\n');
}

int main(int argc, char *argv[])
{
	mul(argc, argv);
	return 0;
}
