#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * wildcmp - compares two strings and returns 1 if the strings can be
 * considered identical, otherwise return 0
 *
 * @s1: Pointer to the first string
 * @s2: Pointer to the second string
 *
 * Return: 0 or 1 if identical
 */
int wildcmp(char *s1, char *s2)
{
	size_t i, j;

	for (i = 0; i < strlen(s2); i++)
	{

		while (s2[i] == '*' && i < strlen(s2))
		{
			i++;
		}

		for (j = 0; j <= strlen(s1); j++)
		{
			if (s1[j] == s2[i])
			{

				break;
				}
		}
		if (s1[j] != s2[i])
		{
			return (0);
			}
		if (i == (strlen(s2) - 1) && j != (strlen(s1) - 1))
		{
			return (0);
		}
	}

	return (1);
}
