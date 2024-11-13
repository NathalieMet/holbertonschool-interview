#!/usr/bin/python3

def island_perimeter(grid):

    surface = 0
    rows = len(grid)
    cols = len(grid[0])

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                if grid[i][j - 1] == 0:
                    surface += 1
                if grid[i][j + 1] == 0:
                    surface += 1
                if grid[i + 1][j] == 0:
                    surface += 1
                if grid[i - 1][j] == 0:
                    surface += 1
    return surface
