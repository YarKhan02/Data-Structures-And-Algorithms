def subset_sum(arr, target):
    n = len(arr) + 1
    w = target + 1
    t = [[0 for i in range(w)] for j in range(n)]

    for i in range(n):
        for j in range(w):
            if i == 0 and j != 0:
                t[i][j] = False
            elif j == 0:
                t[i][j] = True

    for i in range(1, n):
        for j in range(1, w):
            if arr[i - 1] <= j:
                t[i][j] = max(t[i - 1][j - arr[i - 1]], t[i - 1][j])
            else:
                t[i][j] = t[i - 1][j]

    return t[n - 1][w - 1]

def equal_sum_prtition(arr, target):
    if (sum(arr) % 2) != 0:
        return False
    else:
        return subset_sum(arr, sum(arr)//2)

print(equal_sum_prtition([10, 5, 0, 5], 10))