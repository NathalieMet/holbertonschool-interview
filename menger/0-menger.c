#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "menger.h"

#define MAX_SIZE 2187 // 3^7, which is the maximum level considered

void fillGrid(int level, char grid[MAX_SIZE][MAX_SIZE], int size);
void clearCenter(int level, char grid[MAX_SIZE][MAX_SIZE], int size, int x, int y);

void menger(int level) {
    if (level < 0) {
        return;
    }

    int size = pow(3, level);
    char grid[MAX_SIZE][MAX_SIZE];

    // Initialize the grid with '#'
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            grid[i][j] = '#';
        }
    }

    // Clear the center
    fillGrid(level, grid, size);

    // Print the grid
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
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
    if (level == 0) {
        return;
    }

    int subSize = size / 3;
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
    if (level == 0) {
        return;
    }

    int subSize = size / 3;

    for (int i = x + subSize; i < x + 2 * subSize; i++) {
        for (int j = y + subSize; j < y + 2 * subSize; j++) {
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
