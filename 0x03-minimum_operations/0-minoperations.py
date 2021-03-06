#!/usr/bin/python3
""" In a text file, there is a single character H.
    Your text editor can execute only two operations in this file:
    Copy All and Paste.
    Given a number n, calculate the fewest number of operations needed
    to result in exactly n H characters in the file
"""


def minOperations(n):
    """ solution """
    if (n < 2 or type(n) is not int):
        return (0)

    ops = 0
    for i in range(2, n):
        while(n % i == 0):
            ops += i
            n = n / i
    return ops
