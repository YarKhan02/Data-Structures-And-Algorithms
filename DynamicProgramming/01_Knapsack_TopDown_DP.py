import random

t = [[-1 for _ in range(1)] for _ in range(1)]

def knapsack_topdown(wt, val, w, n):
    global t

    for i in range(n + 1):
        for j in range(w + 1):
            if i == 0 or j == 0:
                t[i][j] = 0

    for i in range(1, n + 1):
        for j in range(1, w + 1):
            if wt[i - 1] <= j:
                t[i][j] = max((val[i - 1] + t[i - 1][j - wt[i - 1]]), t[i - 1][j])
            else:
                t[i][j] = t[i - 1][j]

    return t[n][w]

def main():
    wt = [random.randint(1, 10) for _ in range(random.randint(5, 15))]
    val = [random.randint(1, 10) for _ in range(len(wt))]
    w = random.randint(1, 20)

    global t

    t = [[1 for _ in range(w + 1)] for _ in range(len(wt) + 1)]

    print(f'wt -> {wt}')
    print(f'val -> {val}')
    print(f'w -> {w}')

    profit = knapsack_topdown(wt, val, w, len(wt))

    print(f'Profit - {profit}')

if __name__ == main():
    main()