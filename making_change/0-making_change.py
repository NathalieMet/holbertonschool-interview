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
    remaining_total = total

    for coin in coins:
        if coin <= remaining_total:
            num_of_coins = remaining_total // coin
            count += num_of_coins
            remaining_total -= num_of_coins * coin

        if remaining_total == 0:
            return count

    return -1
