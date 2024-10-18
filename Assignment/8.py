def maxProfit(k, prices):
    if not prices:
        return 0
    
    n = len(prices)
    if k >= n // 2:  # If k is larger than n/2, we can make as many transactions as we want
        return sum(max(prices[i + 1] - prices[i], 0) for i in range(n - 1))

    dp = [[0] * n for _ in range(k + 1)]

    for i in range(1, k + 1):
        max_diff = -prices[0]
        for j in range(1, n):
            dp[i][j] = max(dp[i][j - 1], prices[j] + max_diff)
            max_diff = max(max_diff, dp[i - 1][j] - prices[j])

    return dp[k][n - 1]

# Test cases
print(maxProfit(2, [2, 4, 1]))  # Output: 2
print(maxProfit(2, [3, 2, 6, 5, 0, 3]))  # Output: 7
