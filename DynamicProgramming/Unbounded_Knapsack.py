import random

def unbounded_knapsack(wt, val, w, n):
    t = [[1 for _ in range(w + 1)] for _ in range(n + 1)]

    for i in range(n + 1):
        for j in range(w + 1):
            if i == 0 and j != 0:
                t[i][j] = False
            elif j == 0:
                t[i][j] = True

    for i in range(1, n + 1):
        for j in range(1, w + 1):
            if wt[i - 1] <= j:
                t[i][j] = max((val[i - 1] + t[i][j - wt[i - 1]]), t[i - 1][j])
            else:
                t[i][j] = t[i - 1][j]

    return t[n][w]

def main():
    wt = [random.randint(1, 10) for _ in range(random.randint(5, 15))]
    val = [random.randint(1, 10) for _ in range(len(wt))]
    w = random.randint(1, 20)

    print(f'wt -> {wt}')
    print(f'val -> {val}')
    print(f'w -> {w}')

    profit = unbounded_knapsack(wt, val, w, len(wt))

    print(f'Profit - {profit}')

if __name__ == main():
    main()