#!/usr/bin/python3

def rotate_2d_matrix(matrix):
    rotated_matrix = list(zip(*matrix[::-1]))

    for i in range(len(matrix)):
        matrix[i] = list(rotated_matrix[i])
