import random

t = [[-1 for _ in range(1)] for _ in range(1)]

def knapsack_memo(wt, val, w, n):
    global t

    if (w == 0) or (n == 0):
        return 0

    if t[n][w] != -1:
        return t[n][w]

    if wt[n - 1] <= w:
        t[n][w] = max(val[n - 1] + knapsack_memo(wt, val, w - wt[n - 1], n - 1), knapsack_memo(wt, val, w, n - 1))
        return max(val[n - 1] + knapsack_memo(wt, val, w - wt[n - 1], n - 1), knapsack_memo(wt, val, w, n - 1))
    elif wt[n - 1] > w:
        t[n][w] = knapsack_memo(wt, val, w, n - 1)
        return knapsack_memo(wt, val, w, n - 1)


def main():
    global t

    wt = [random.randint(1, 10) for _ in range(random.randint(5, 10))]
    val = [random.randint(1, 10) for _ in range(len(wt))]
    w = random.randint(1, 20)

    print(f'weight - {wt}')
    print(f'value - {val}')
    print(f'bag - {w}')

    t = [[-1 for _ in range(w + 2)] for _ in range(len(wt) + 2)]

    profit = knapsack_memo(wt, val, w, len(wt))

    print(f'Maximum profit - {profit}')

if __name__ == main():
    main()