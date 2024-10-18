def count_fixed_bound_subarrays(nums, minK, maxK):
    count = 0
    last_min = -1
    last_max = -1
    last_invalid = -1

    for i in range(len(nums)):
        if nums[i] < minK or nums[i] > maxK:
            last_invalid = i
        if nums[i] == minK:
            last_min = i
        if nums[i] == maxK:
            last_max = i
        
        if last_min != -1 and last_max != -1:
            count += max(0, min(last_min, last_max) - last_invalid)

    return count

nums = [1, 3, 5, 2, 7, 5]
minK = 1
maxK = 5
result = count_fixed_bound_subarrays(nums, minK, maxK)
print(result)  