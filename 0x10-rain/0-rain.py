#!/usr/bin/python3
""" Given a list of non-negative integers representing
    the heights of walls with unit width 1, as if viewing
    the cross-section of a relief map, calculate how many
    square units of water will be retained after it rains.
"""


def rain(walls):
    """ The concept here is that if there is a larger wall
        to the right then the water can be retained with
        a height equal to the smaller wall on the left.
        If there are no larger walls to the right then start
        from the left. There must be a larger wall to the left now
    """
    if not walls:
        return 0

    size = len(walls) - 1

    prev = walls[0]

    prev_index = 0
    water = 0

    temp = 0
    for i in range(1, size + 1):

        if (walls[i] >= prev):
            prev = walls[i]
            prev_index = i

            temp = 0
        else:

            water += prev - walls[i]

            temp += prev - walls[i]

    if (prev_index < size):

        water -= temp

        prev = walls[size]

        for i in range(size, prev_index - 1, -1):

            if (walls[i] >= prev):
                prev = walls[i]
            else:
                water += prev - walls[i]

    return water
