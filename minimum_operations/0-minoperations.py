#!/usr/bin/python3
"""
In a text file, there is a single character H. Your text editor can execute
only two operations in this file: Copy All and Paste. Given a number n, write
a method that calculates the fewest number of operations needed to result in
exactly n H characters in the file. Be smart about how you utilize the memory!

Prototype: def minOperations(n)
Returns an integer
If n is impossible to achieve, return 0
"""

def minOperations(n):
    """method to find the fewest number of operations"""
    if n <= 1:
        return 0

    operations = 0
    factor = 2

    while n > 1:
        while n % factor == 0:
            operations += factor
            n //= factor
        factor += 1

    return operations
