#!/usr/bin/python3

def canUnlockAll(boxes):

    key = 0
    index = 0
    already_open = [0]

    while index < len(already_open):
        key = already_open[index]
        for i in boxes[key]:
            if i <= len(boxes) and i not in already_open:
                already_open.append(i)
                # print(already_open, len(already_open), len(boxes))
        index += 1
    return len(already_open) == len(boxes)


