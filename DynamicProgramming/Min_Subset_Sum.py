def min_subset_sum(arr):
    n = len(arr) + 1
    w = sum(arr) + 1
    t = [[0 for i in range(w)] for j in range(n)]
    vector = []
    mn = 9999999999
    
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

    for y in range(sum(arr)//2 + 1):
        if t[n - 1][y]:
            vector.append(y)

    print(vector)

    for k in vector:
        mn = min(mn, sum(arr) - 2*k)

    return mn

arr = [1, 2, 7]
arr = [5, 6, 6, 5, 7, 4, 7, 6]
print(min_subset_sum(arr))