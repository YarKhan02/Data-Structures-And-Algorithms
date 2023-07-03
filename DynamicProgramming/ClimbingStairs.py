# Solution 1

def climbing_stairs(n):
    dp = {}

    def backtrack(i):
        if i in dp:
            return dp[i]

        if i == 0 or i == 1:
            dp[i] = 1
        else:
            dp[i] = backtrack(i - 1) + backtrack(i - 2)

        return dp[i]

    return backtrack(n)

print(climbing_stairs(38))

# Solution 2

def climbing_stairs(n):
    one, two = 1, 1

    for i in range(n):
        temp = one
        one = one + two
        two = temp

    return two

print(climbing_stairs(38))