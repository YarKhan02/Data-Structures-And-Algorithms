# SOLUTION - 1

def combinations(n, k):
    result = []

    def backtrack(i, current):
        if k == len(current):
            result.append(current.copy())
            return
        
        if i == n: return

        current.append(i + 1)
        backtrack(i + 1, current)
        current.pop()
        backtrack(i + 1, current)

    backtrack(0, [])

    return result
        
print(combinations(4, 2))

# SOLUTION - 2

def combinations(n, k):
    result = []

    def backtrack(start, current):
        if k == len(current):
            result.append(current.copy())
            return

        for i in range(start, n + 1):
            current.append(i)
            backtrack(i + 1, current)
            current.pop()

    backtrack(1, [])

    return result
        
print(combinations(4, 2))