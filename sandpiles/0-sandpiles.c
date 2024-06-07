#include <stdio.h>
#include <stdbool.h>

void print_grid(int grid[3][3]);
void topple(int grid[3][3]);
bool is_stable(int grid[3][3]);

void sandpiles_sum(int grid1[3][3], int grid2[3][3]) {

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid1[i][j] += grid2[i][j];
        }
    }


    while (!is_stable(grid1)) {
        printf("=\n");
        print_grid(grid1);
        topple(grid1);
    }
}

void print_grid(int grid[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

bool is_stable(int grid[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] > 3)
                return false;
        }
    }
    return true;
}

void topple(int grid[3][3]) {
    int temp_grid[3][3] = {0};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] > 3) {
                temp_grid[i][j] -= 4;
                if (i > 0) temp_grid[i - 1][j] += 1;
                if (i < 2) temp_grid[i + 1][j] += 1;
                if (j > 0) temp_grid[i][j - 1] += 1;
                if (j < 2) temp_grid[i][j + 1] += 1;
            }
        }
    }


    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid[i][j] += temp_grid[i][j];
        }
    }
}
