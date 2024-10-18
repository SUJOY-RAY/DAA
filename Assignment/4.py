def handleQueries(nums1, nums2, queries):
    results = []
    
    for query in queries:
        if query[0] == 1:
            l, r = query[1], query[2]
            for i in range(l, r + 1):
                nums1[i] ^= 1
        elif query[0] == 2:
            p = query[1]
            for i in range(len(nums2)):
                nums2[i] += nums1[i] * p
        elif query[0] == 3:
            results.append(sum(nums2))
    
    return results

# Test cases
print(handleQueries([1, 0, 1], [0, 0, 0], [[1, 1, 1], [2, 1, 0], [3, 0, 0]]))  # Output: [3]
print(handleQueries([1], [5], [[2, 0, 0], [3, 0, 0]]))                          # Output: [5]
