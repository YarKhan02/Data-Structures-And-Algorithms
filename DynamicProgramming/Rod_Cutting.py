import random

def rod_cutting(price, n):
    t = [[0 for j in range(n + 1)] for i in range(n + 1)]
    
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            if i <= j:
                t[i][j] = max((price[i - 1] + t[i][j - i]), t[i - 1][j])
            else:
                t[i][j] = t[i - 1][j]
            print(t[i][j], end = ' ')
        print()

    return t[n][n]

def main():
    n = 8
    price = [1, 5, 8, 9, 10, 17, 17, 20]

    print(f'Price - {price}')

    profit = rod_cutting(price, n)

    print(f'Profit - {profit}')

if __name__ == '__main__':
    main()