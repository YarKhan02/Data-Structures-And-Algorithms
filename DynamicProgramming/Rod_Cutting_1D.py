def cutRod(price, n):
    t = [0] * (n + 1)

    for i in range(1, n + 1):
        for j in range(i, n + 1):
            t[j] = max(t[j], price[i - 1] + t[j - i])
        
    return t[n]

n = 8
price = [1, 5, 8, 9, 10, 17, 17, 20]

print(cutRod(price, n))