import random

def knapsack_recursion(wt, val, w, n):
    if (w == 0) or (n == 0):
        return 0
    
    if wt[n - 1] <= w:
        return max((val[n - 1] + knapsack_recursion(wt, val, w - wt[n - 1], n - 1)), 
                knapsack_recursion(wt, val, w, n - 1))
    elif wt[n - 1] > w:
        return knapsack_recursion(wt, val, w, n - 1)

def main():
    wt = [random.randint(1, 10) for _ in range(random.randint(5, 10))]
    val = [random.randint(1, 10) for _ in range(len(wt))]
    w = random.randint(1, 20)

    print(wt)
    print(val)
    print(w)

    profit = knapsack_recursion(wt, val, w, len(wt))

    print(f'Maximum profit - {profit}')

if __name__ == main():
    main()