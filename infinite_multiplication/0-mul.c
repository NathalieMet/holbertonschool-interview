#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* Vérifie si une chaîne est composée uniquement de chiffres */
int is_digit_str(char *str) {
    while (*str) {
        if (!isdigit(*str)) {
            return (0);
        }
        str++;
    }
    return (1);
}

/* Fonction pour imprimer une chaîne de caractères représentant un grand nombre */
void print_number(char *str) {
    while (*str) {
        _putchar(*str);
        str++;
    }
    _putchar('\n');
}

/* Multiplie deux grands nombres représentés sous forme de chaînes */
char *mul(char *num1, char *num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int len_result = len1 + len2;

    /* Tableau pour stocker le résultat intermédiaire */
    int *result = calloc(len_result, sizeof(int));
    if (!result) {
        return NULL;
    }

    /* Multiplication des chiffres de droite à gauche */
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int p1 = i + j;
            int p2 = i + j + 1;
            int sum = mul + result[p2];
            result[p1] += sum / 10;
            result[p2] = sum % 10;
        }
    }

    /* Convertir le tableau en chaîne de caractères */
    char *result_str = malloc(len_result + 1);
    if (!result_str) {
        free(result);
        return NULL;
    }

    int k = 0;
    int i = 0;

    /* Ignore les zéros en tête */
    while (i < len_result && result[i] == 0) i++;

    /* Conversion en chaîne de caractères */
    while (i < len_result) {
        result_str[k++] = result[i++] + '0';
    }

    /* Si le résultat est 0 */
    if (k == 0) {
        result_str[k++] = '0';
    }

    result_str[k] = '\0';

    free(result);
    return result_str;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Error\n");
        return (98);
    }

    if (!is_digit_str(argv[1]) || !is_digit_str(argv[2])) {
        printf("Error\n");
        return (98);
    }

    /* Appel à la fonction de multiplication */
    char *result = mul(argv[1], argv[2]);

    if (result) {
        print_number(result);
        free(result);
    } else {
        printf("Error\n");
        return (98);
    }

    return (0);
}
