#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "palindrome.h"

/**
 * is_palindrome - function that checks whether or not a given unsigned integer
 * is a palindrome.
 *
 * @n: the number to be checked
 *
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	char str[20];

	if (n < 10)
		return (1);

	snprintf(str, sizeof(str), "%lu", n);

	char *ptr_begin = str;
	char *ptr_end = str + strlen(str) - 1;

	while (ptr_begin <= ptr_end)
	{
		if (*ptr_begin != *ptr_end)
			return (0);

		ptr_begin++;
		ptr_end--;
	}
	return (1);
}
