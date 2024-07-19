#!/usr/bin/python3
"""
Method that determines if a given data set represents a valid UTF-8 encoding.
"""


def validUTF8(data):
    """
    Prototype: def validUTF8(data)
    Return: True if data is a valid UTF-8 encoding, else return False
    """
    remaining_bytes = 0

    for byte in data:
        if remaining_bytes == 0:
            if (byte >> 5) == 0b110:
                remaining_bytes = 1
            elif (byte >> 4) == 0b1110:
                remaining_bytes = 2
            elif (byte >> 3) == 0b11110:
                remaining_bytes = 3
            elif (byte >> 7) == 0b0:
                continue
            else:
                return False
        else:
            if (byte >> 6) != 0b10:
                return False
            remaining_bytes -= 1

    return remaining_bytes == 0
