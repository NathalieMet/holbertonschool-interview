#include "substring.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * check_word_match - Checks if a substring matches any word in the array
 * @substring: The substring to check
 * @words: Array of words
 * @nb_words: Number of words in the array
 * @found_counts: Array to track word usage counts
 *
 * Return: Index of the matched word, or -1 if no match
 */
int check_word_match(char *substring, char const **words, int nb_words,
int *found_counts)
{
	for (int j = 0; j < nb_words; j++)
	{
		if (strcmp(substring, words[j]) == 0 && found_counts[j] == 0)
		{
			found_counts[j]++;
			return (j);
		}
	}
	return (-1);
}

/**
 * validate_substring - Validates a substring starting at a given index
 * @s: The input string
 * @start: Starting index of the substring
 * @words: Array of words
 * @nb_words: Number of words in the array
 * @word_len: Length of each word
 *
 * Return: 1 if the substring is valid, 0 otherwise
 */
int validate_substring(char const *s, int start, char const **words,
int nb_words, int word_len)
{
	char substring[word_len + 1];
	int *found_counts = calloc(nb_words, sizeof(int));
	int total_found = 0;

	if (!found_counts)
		return (0);

	for (int i = 0; i < nb_words; i++)
	{
		int pos = start + i * word_len;

		strncpy(substring, s + pos, word_len);
		substring[word_len] = '\0';

		if (check_word_match(substring, words, nb_words, found_counts) == -1)
		{
			free(found_counts);
			return (0);
		}
		total_found++;
	}

	free(found_counts);
	return (total_found == nb_words);
}

/**
 * find_substring - Finds all starting indices of valid substrings
 * @s: The input string
 * @words: Array of words
 * @nb_words: Number of words in the array
 * @n: Pointer to store the count of indices found
 *
 * Return: Array of starting indices, or NULL if no solution is found
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int word_len, s_len, substring_len, *indices;

	*n = 0;
	if (!s || !words || nb_words == 0)
		return (NULL);

	word_len = strlen(words[0]);
	s_len = strlen(s);
	substring_len = word_len * nb_words;

	if (s_len < substring_len)
		return (NULL);

	indices = malloc(s_len * sizeof(int));
	if (!indices)
		return (NULL);

	for (int start = 0; start <= s_len - substring_len; start++)
	{
		if (validate_substring(s, start, words, nb_words, word_len))
			indices[(*n)++] = start;
	}

	if (*n == 0)
	{
		free(indices);
		return (NULL);
	}

	return (indices);
}
