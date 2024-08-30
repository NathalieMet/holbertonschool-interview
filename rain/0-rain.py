#!/usr/bin/python3

def rain(walls):
    if not walls:
        return 0

    n = len(walls)
    water_retained = 0

    max_left = [0] * n
    max_right = [0] * n

    max_left[0] = walls[0]
    for i in range(1, n):
        max_left[i] = max(max_left[i - 1], walls[i])

    max_right[-1] = walls[-1]
    for i in range(n - 2, -1, -1):
        max_right[i] = max(max_right[i + 1], walls[i])

    for i in range(n):
        water_retained += min(max_left[i], max_right[i]) - walls[i]

    return water_retained
