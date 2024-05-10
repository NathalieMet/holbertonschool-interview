#!/usr/bin/python3
"""
You have n number of locked boxes in front of you. Each box is numbered
sequentially from 0 to n - 1 and each box may contain keys to the other boxes.

Write a method that determines if all the boxes can be opened.

Prototype: def canUnlockAll(boxes)
boxes is a list of lists
A key with the same number as a box opens that box
You can assume all keys will be positive integers
There can be keys that do not have boxes
The first box boxes[0] is unlocked
Return True if all boxes can be opened, else return False
"""


def canUnlockAll(boxes):
    """method to determine if all the boxes can be opened"""

    key = 0
    index = 0
    already_open = [0]

    while index < len(already_open):
        key = already_open[index]
        for i in boxes[key]:
            if i < len(boxes) and i not in already_open:
                already_open.append(i)
        index += 1

    return len(already_open) == len(boxes)
