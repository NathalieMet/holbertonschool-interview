#!/usr/bin/python3
"""
Maria and Ben are playing a game. Given a set of consecutive integers starting
frm 1 up to and including n, they take turns choosing a prime number frm the
set and removing that number and its multiples frm the set. The player that
cannot make a move loses the game.

They play x rounds of the game, where n may be different for each round.
Assuming Maria always goes first and both players play optimally, determine
who the winner of each game is.
"""


def isWinner(x, nums):
    """Détermine le gagnant des x jeux."""
    if x <= 0 or not nums:
        return None

    maria = 0
    ben = 0

    for i in range(x):
        n = nums[i]
        if n < 2:
            ben += 1
            continue

        numberlist = list(range(1, n + 1))

        flag = 0

        for element in numberlist:
            if is_prime(element):
                numberlist = [x for x in numberlist if x % element != 0]
                flag += 1

        if flag % 2 == 0:
            ben += 1
        else:
            maria += 1

    if maria > ben:
        return "Maria"
    elif ben > maria:
        return "Ben"
    else:
        return None


def is_prime(nombre):
    """Vérifie si un nombre est premier."""
    if nombre <= 1:
        return False
    for i in range(2, int(nombre**0.5) + 1):
        if nombre % i == 0:
            return False
    return True
