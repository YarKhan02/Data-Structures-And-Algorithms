import random

def coin_change(coins, amount):
    r = len(coins)
    t = [[0 if i == 0 and j != 0 else 1 if i != 0 and j == 0 else -1 for j in range(amount + 1)] for i in range(r + 1)]

    for i in range(1, r + 1):
        for j in range(1, amount + 1):
            if coins[i - 1] <= j:
                t[i][j] = t[i][j - coins[i - 1]] + t[i - 1][j]
            else:
                t[i][j] = t[i - 1][j]

    return t[r][amount]


coins = [1, 2, 5]
n = 3

print(coin_change(coins, n))


def coin_change(coins, amount):
    num_coins = len(coins)
    dp = [float('inf')] * (amount + 1)
    dp[0] = 0

    for coin in coins:
        for i in range(coin, amount + 1):
            dp[i] = min(dp[i], dp[i - coin] + 1)

    if dp[amount] == float('inf'):
        return -1  # If it's not possible to make the amount with given coins

    return dp[amount]


coins = [1, 2, 5]
n = 11

print(coin_change(coins, n))