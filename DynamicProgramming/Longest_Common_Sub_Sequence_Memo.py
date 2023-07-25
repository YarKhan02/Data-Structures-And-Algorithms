t = [[-1 for _ in range(1)] for _ in range(1)]

def lcs(x, y, n, m):
    if n == 0 or m == 0:
        return 0

    if t[n][m] != -1:
        return t[n][m]
        
    if x[n - 1] == y[m - 1]:
        t[n][m] = 1 + lcs(x, y, n - 1, m - 1)
        return t[n][m]
    else:
        t[n][m] = max(lcs(x, y, n - 1, m), lcs(x, y, n, m - 1))
        return t[n][m]


x = 'ACABBBBDBAAB'
y = 'BBCCBEECDCDE'

t = [[-1 for _ in range(len(y) + 1)] for _ in range(len(x) + 1)]

print(lcs(x, y, len(x), len(y)))