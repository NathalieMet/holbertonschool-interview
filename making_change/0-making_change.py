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

    for coin in coins:
        if total >= coin:
            num_coins = total // coin
            total -= num_coins * coin
            count += num_coins

        if total == 0:
            return count

    return -1
