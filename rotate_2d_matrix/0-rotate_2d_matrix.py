#!/usr/bin/python3
"""
rotate matrix 90 degrees clockwise.
"""


def rotate_2d_matrix(matrix):
    """
rotate matrix 90 degrees clockwise.
"""
    rotated_matrix = list(zip(*matrix[::-1]))

    for i in range(len(matrix)):
        matrix[i] = list(rotated_matrix[i])
