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
    count = 0

    for first in coins:
        if first == total:
            count += 1
            return count

        for second in coins:
            if first + second == total:
                count += 2
                return count

            if first + second > total:
                continue

            current_sum = first
            count = 1

            while current_sum + second <= total:
                current_sum += second
                count += 1

            if current_sum == total:
                return count

    return -1
