def min_cost_tickets(days, costs):
    dp = {}

    for i in range(len(days) - 1, -1, -1):
        dp[i] = float('inf')    
        for d, c in zip([1, 7, 30], costs):
            j = i
            while j < len(days) and days[j] < days[i] + d:
                j += 1
            dp[i] = min(dp[i], c + dp.get(j, 0))

    return dp[0]


days = [1, 4, 6, 7, 8, 20]
costs = [2, 7, 15]

print(min_cost_tickets(days, costs))