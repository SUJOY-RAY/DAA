def minScore(s, t):
    n, m = len(s), len(t)
    
    prefix_len = 0
    for i in range(n):
        if prefix_len < m and s[i] == t[prefix_len]:
            prefix_len += 1
    
    suffix_len = 0
    for i in range(n - 1, -1, -1):
        if suffix_len < m and s[i] == t[m - 1 - suffix_len]:
            suffix_len += 1
    
    total_matched = prefix_len + suffix_len
    if total_matched > m:
        total_matched = m
    
    min_score = m - total_matched
    return min_score

# Test cases
print(minScore("abacaba", "bzaa"))  # Output: 1
print(minScore("cde", "xyz"))       # Output: 3
