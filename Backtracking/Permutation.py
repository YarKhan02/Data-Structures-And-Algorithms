def permutation(nums):
    result = []

    if len(nums) == 1:
        return [nums[:]]

    for i in range(len(nums)):
        n = nums.pop(0)
        perms = permutation(nums)
        for perm in perms:
            perm.append(n)
            # print(perm)
        result.extend(perms)
        nums.append(n)
        # print(result)

    return result

nums = [0, 0, 1]
print(permutation(nums))