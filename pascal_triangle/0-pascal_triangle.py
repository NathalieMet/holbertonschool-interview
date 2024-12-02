#!/usr/bin/python3

def pascal_triangle(n):
    """Returns a list of lists representing Pascal's triangle up to level n."""
    if n <= 0:
        return []

    triangle = [[1]]
    if n > 1:
        triangle.append([1, 1])

    for i in range(2, n):
        prev_row = triangle[i - 1]
        new_row = [1]
        for j in range(1, len(prev_row)):
            new_row.append(prev_row[j - 1] + prev_row[j])
        new_row.append(1)
        triangle.append(new_row)

    return triangle
