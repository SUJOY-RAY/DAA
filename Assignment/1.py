def trap(height):
    n = len(height)
    if n == 0:
        return 0
    left, right = 0, n - 1
    left_max, right_max = 0, 0
    water = 0
    while left <= right:
        if height[left] <= height[right]:
            if height[left] >= left_max:
                left_max = height[left]
            else:
                water += left_max - height[left]
            left += 1
        else:
            if height[right] >= right_max:
                right_max = height[right]
            else:
                water += right_max - height[right]
            right -= 1
    return water

# Test case
heights = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
result = trap(heights)  # Output: 6
print("Max Water: ", result)
