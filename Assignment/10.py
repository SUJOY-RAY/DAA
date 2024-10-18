def candy(ratings):
    n = len(ratings)
    if n == 0:
        return 0
    
    candies = [1] * n
    
    # Left to right
    for i in range(1, n):
        if ratings[i] > ratings[i - 1]:
            candies[i] = candies[i - 1] + 1
    
    # Right to left
    for i in range(n - 2, -1, -1):
        if ratings[i] > ratings[i + 1]:
            candies[i] = max(candies[i], candies[i + 1] + 1)
    
    return sum(candies)

# Test cases
print(candy([1, 0, 2]))  # Output: 5
print(candy([1, 2, 2]))  # Output: 4
