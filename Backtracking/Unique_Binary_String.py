def unique_binary_string(nums):
    strSet = {s for s in nums}

    def backtrack(i, current):
        if i == len(nums):
            result = ''.join(current)
            return None if result in strSet else result

        result = backtrack(i + 1, current)
        if result: return result

        current[i] = '1'
        result = backtrack(i + 1, current)
        if result: return result

    return backtrack(0, ['0' for s in nums])

nums = ['10', '01']
print(unique_binary_string(nums))
