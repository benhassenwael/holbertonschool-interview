#!/usr/bin/python3
""" 0x19. Making Change
"""


def makeChange(coins, total):
    """ Given a pile of coins of different values,
        determine the fewest number of coins needed
        to meet a given amount total
    """
    if total < 1:
        return 0

    dp = [total + 1] * (total + 1)
    dp[0] = 0

    for a in range(1, total + 1):
        for c in coins:
            if a - c >= 0:
                dp[a] = min(dp[a], 1 + dp[a - c])

    return dp[total] if dp[total] != total + 1 else -1
