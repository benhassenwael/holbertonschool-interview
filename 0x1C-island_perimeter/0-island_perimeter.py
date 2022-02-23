#!/usr/bin/python3
""" Module defining island_perimeter function """


def island_perimeter(grid):
    """ Counts the perimeter of the island
        described in grid
    """

    if not grid or (type(grid[0]) is not list):
        return 0

    perim = 0

    for row in range(len(grid)):
        for col in range(len(grid[row])):
            if grid[row][col] == 1:
                perim += 4
                if row > 0 and grid[row - 1][col]:
                    perim -= 1
                if row < (len(grid) - 1) and grid[row + 1][col]:
                    perim -= 1
                if col > 0 and grid[row][col - 1]:
                    perim -= 1
                if col < (len(grid[row]) - 1) and grid[row][col + 1]:
                    perim -= 1
    return perim
