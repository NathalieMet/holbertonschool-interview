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
    """Détermine le gagnant de chaque jeu."""
    if x <= 0 or not nums:
        return None

    maria = 0
    ben = 0

    for n in nums:
        if n < 2:
            ben += 1
            continue

        primes = generate_primes_up_to(n)
        turn = 0

        while primes:
            prime = primes[0]
            primes = [x for x in primes if x % prime != 0]
            turn = 1 - turn

        if turn == 1:
            maria += 1
        else:
            ben += 1

    if maria > ben:
        return "Maria"
    elif ben > maria:
        return "Ben"
    else:
        return None


def generate_primes_up_to(n):
    """
    Génère une liste des nombres premiers jusqu'à `n` (inclus) en utilisant
    le crible d'Ératosthène.
    """
    sieve = [True] * (n + 1)
    sieve[0] = sieve[1] = False
    for i in range(2, int(n**0.5) + 1):
        if sieve[i]:
            for j in range(i * i, n + 1, i):
                sieve[j] = False
    return [i for i in range(n + 1) if sieve[i]]
