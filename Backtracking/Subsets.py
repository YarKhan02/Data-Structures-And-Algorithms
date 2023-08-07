def subset(nums):
    result = []
    subset = []

    def dfs(i):
        if i >= len(nums):
            result.append(subset.copy())
            return
        
        subset.append(nums[i])

        dfs(i + 1)

        subset.pop()

        dfs(i + 1)

    dfs(0)

    return result

nums = [1, 2, 3]
print(subset(nums))