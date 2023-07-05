def subset_sum(arr, target):
    y = len(arr) - 1
    i = 0

    def backtrack(n, total):
        print(total)
        if total == target:
            return True

        if n == 0:
            nonlocal i
            i += 1
            if i > y:
                return False
            return backtrack(len(arr) - i, 0)

        if total <= target:
            return backtrack(n - 1, total + arr[n])
        elif total > target:
            if n == y and i == 0:
                total -= arr[n]
            else:
                total -= arr[n + 1]
            return backtrack(n, total)

    return backtrack(y, 0)

print(subset_sum([2, 3, 7, 8, 10], 13))