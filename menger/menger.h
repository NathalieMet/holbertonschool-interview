#ifndef MENGER_H
#define MENGER_H

#define MAX_SIZE 2187

void menger(int level);
void clearCenter(int level, char grid[MAX_SIZE][MAX_SIZE], int size, int x, int y);
void fillGrid(int level, char grid[MAX_SIZE][MAX_SIZE], int size);

#endif
