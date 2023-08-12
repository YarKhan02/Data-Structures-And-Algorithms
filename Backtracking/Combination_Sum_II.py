def combination_sum(candidates, target):
    candidates.sort()
    result = []

    def backtracking(position, current, target):
        if target == 0:
            result.append(current.copy())
        
        if target <= 0:
            return

        prev = -1

        for i in range(position, len(candidates)):
            if prev == candidates[i]:
                continue 
            current.append(candidates[i])
            backtracking(i + 1, current, target - candidates[i])
            current.pop()
            prev = candidates[i]

    backtracking(0, [], target)

    return result

candidates = [10, 1, 2, 7, 6, 1]
target = 8
print(combination_sum(candidates, target))