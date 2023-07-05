def subset_sum(arr, target):
    y = len(arr)
    
    def backtrack(n, total):
        if total == target:
            return True

        if n == -1:
            return False

        if total <= target:
            return backtrack(n - 1, total + arr[n])
        elif total > target:
            total -= arr[n]
            return backtrack(n - 1, total)

    return backtrack(y - 1, 0)

print(subset_sum([2, 3, 7, 8, 10], 30))