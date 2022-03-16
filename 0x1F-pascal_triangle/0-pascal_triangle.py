#!/usr/bin/python3
""" Module implementing a single function pascal_triangle """


def pascal_triangle(n):
    """ Generates a list of lists of integers representing
        the Pascal’s triangle of n
        Args:
            n: height of the pascal's trinagle
        Returns:
            alist of lists of integers representing
            the Pascal’s triangle of n
    """
    if n <= 0:
        return []
    res = [[1]]
    prev = [1]
    for line in range(2, n + 1):
        current = []
        for index in range(line):
            if index == 0 or index == line - 1:
                current.append(1)
            else:
                current.append(prev[index] + prev[index - 1])
        prev = current
        res.append(current)
    return res
