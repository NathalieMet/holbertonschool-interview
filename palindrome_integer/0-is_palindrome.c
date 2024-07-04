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
	unsigned long reversed = 0;
	unsigned long original = n;

	if (n < 10)
		return (1);

	while (original > 0)
	{
		reversed = reversed * 10 + original % 10;
		original /= 10;
	}

	return (reversed == n);
}
