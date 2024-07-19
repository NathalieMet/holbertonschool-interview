#include <stdlib.h>
#include <stdio.h>

#include "slide_line.h"

/**
 * slide_line - reproduce the 2048 game(NSFW !!) mechanics on a single
 horizontal line.
 *
 * @line: Pointer to the array
 * @size: Number of elements
 * @direction: indicate left or right
 * Return: 0 Fail, 1 Success
 */

int slide_line(int *line, size_t size, int direction)
{
    size_t i, j;

    if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
    {
        return 0;
    }

    if (direction == SLIDE_LEFT)
    {
        for (i = 0; i < size; i++)
        {
            if (line[i] == 0)
            {
                for (j = i + 1; j < size; j++)
                {
                    if (line[j] != 0)
                    {
                        line[i] = line[j];
                        line[j] = 0;
                        break;
                    }
                }
            }
        }
        for (i = 0; i < size - 1; i++)
        {
            if (line[i] == line[i + 1])
            {
                line[i] *= 2;
                line[i + 1] = 0;
                for (j = i + 1; j < size - 1; j++)
                {
                    line[j] = line[j + 1];
                }
                line[size - 1] = 0;
            }
        }
    }
    else if (direction == SLIDE_RIGHT)
    {
        for (i = size - 1; (int)i >= 0; i--)
        {
            if (line[i] == 0)
            {
                for (j = i - 1; (int)j >= 0; j--)
                {
                    if (line[j] != 0)
                    {
                        line[i] = line[j];
                        line[j] = 0;
                        break;
                    }
                }
            }
        }
        for (i = size - 1; i > 0; i--)
        {
            if (line[i] == line[i - 1])
            {
                line[i] *= 2;
                line[i - 1] = 0;
                for (j = i - 1; (int)j > 0; j--)
                {
                    line[j] = line[j - 1];
                }
                line[0] = 0;
            }
        }
    }

    return 1;
}
