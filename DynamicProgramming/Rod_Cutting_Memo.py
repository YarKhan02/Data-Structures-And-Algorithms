import random

def rod_cutting_memo(price, n, memo = {}):
    length = list(range(1, n + 1))

    if n in memo:
        return memo[n]

    if n == 0:
        return 0

    max_profit = float('-inf')

    for i in range(1, n + 1):
        max_profit = max(max_profit, price[i - 1] + rod_cutting_memo(price, n - i, memo))

    memo[n] = max_profit

    return max_profit

n = 8
price = [1, 5, 8, 9, 10, 17, 17, 20]

print(rod_cutting_memo(price, n))