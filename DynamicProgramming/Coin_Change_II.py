import sys

def coin_change_min(coins, x):
    max_int_size = sys.maxsize - 1
    n = len(coins)
    t = [[max_int_size if i == 0 else 0 if i != 0 and j == 0 else 0 for j in range(x + 1)] for i in range(n + 1)]

    for k in range(1, n + 1):
        if (k % coins[0]) == 0:
            t[1][k] = k//coins[0]
        else:
            t[1][k] = max_int_size

    for i in range(1, n + 1):
        for j in range(1, x + 1):
            if coins[i - 1] <= j:
                t[i][j] = min(1 + t[i][j - coins[i - 1]], t[i - 1][j])
            else:
                t[i][j] = t[i - 1][j]
            print(t[i][j], end = ' ')
        print()

    return t[n][x]

coins = [1, 2, 5]
x = 5
print(f'Minimum number of coins for sum({x}) = {coin_change_min(coins, x)}')