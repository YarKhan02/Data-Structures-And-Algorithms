def target_sum(nums, target):
    dp = {}

    def backtrack(i, total):
        print(dp)
        
        if i == len(nums):
            return 1 if total == target else 0
        
        if (i, total) in dp:
            return dp[(i, total)]

        dp[(i, total)] = (backtrack(i + 1, total + nums[i]) + 
                        backtrack(i + 1, total - nums[i]))

        return dp[(i, total)]

    return backtrack(0, 0)

nums = [1, 1, 1, 1, 1]
target = 3

print(target_sum(nums, target))