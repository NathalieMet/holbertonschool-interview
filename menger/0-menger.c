#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "menger.h"

#define MAX_SIZE 2187

void fillGrid(int level, char grid[MAX_SIZE][MAX_SIZE], int size);
void clearCenter(int level, char grid[MAX_SIZE][MAX_SIZE], int size, int x, int y);

void menger(int level) {
	int size = pow(3, level);
    char grid[MAX_SIZE][MAX_SIZE];
	int i, j;

    if (level < 0) {
        return;
    }

    /** Initialize the grid with '#'
	*/
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            grid[i][j] = '#';
        }
    }

    /** Clear the center
	*/
    fillGrid(level, grid, size);

    /** Print the grid
	*/
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            putchar(grid[i][j]);
        }
        putchar('\n');
    }
}

/**
 * fillGrid - Fill the Menger Sponge grid
 * @level: The level of the Menger Sponge
 * @grid: The grid to be filled
 * @size: The current size of the grid
 */
void fillGrid(int level, char grid[MAX_SIZE][MAX_SIZE], int size) {
    int subSize = size / 3;

    if (level == 0) {
        return;
    }
    clearCenter(level, grid, size, 0, 0);
    fillGrid(level - 1, grid, subSize);
}

/**
 * clearCenter - Clear the center part of the Menger Sponge
 * @level: The current level
 * @grid: The grid to be cleared
 * @size: The size of the current grid
 * @x: The x-coordinate of the top-left corner
 * @y: The y-coordinate of the top-left corner
 */
void clearCenter(int level, char grid[MAX_SIZE][MAX_SIZE], int size, int x, int y) {
    int subSize = size / 3;
	int i, j;

	if (level == 0) {
        return;
    }

    for (i = x + subSize; i < x + 2 * subSize; i++) {
        for (j = y + subSize; j < y + 2 * subSize; j++) {
            grid[i][j] = ' ';
        }
    }

    clearCenter(level - 1, grid, subSize, x, y);
    clearCenter(level - 1, grid, subSize, x + subSize, y);
    clearCenter(level - 1, grid, subSize, x + 2 * subSize, y);
    clearCenter(level - 1, grid, subSize, x, y + subSize);
    clearCenter(level - 1, grid, subSize, x + 2 * subSize, y + subSize);
    clearCenter(level - 1, grid, subSize, x, y + 2 * subSize);
    clearCenter(level - 1, grid, subSize, x + subSize, y + 2 * subSize);
    clearCenter(level - 1, grid, subSize, x + 2 * subSize, y + 2 * subSize);
}
