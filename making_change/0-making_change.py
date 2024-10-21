#!/usr/bin/python3
"""
Function that determines the fewest number of coins needed to meet a given
amount total
"""


def makeChange(coins, total):
    """
Function that determines the fewest number of coins needed to meet a given
amount total
"""
    if total <= 0:
        return 0

    coins.sort(reverse=True)


    count = 1

    for first in coins:
        for second in coins:
            if first + second == total:
                count += 1

                return count
            if first == total:

                return count
            if first + second > total:
                continue
            while first + second <= total:
                first += second
                count += 1

        return -1
