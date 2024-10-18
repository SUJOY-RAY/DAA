def largestRectangleArea(heights):
    stack = []
    max_area = 0
    heights.append(0)  # Append a zero height to pop all elements

    for i in range(len(heights)):
        while stack and heights[i] < heights[stack[-1]]:
            h = heights[stack.pop()]  
            width = i if not stack else i - stack[-1] - 1  
            max_area = max(max_area, h * width)  
        stack.append(i) 
    return max_area

# Test cases
heights1 = [2, 1, 5, 6, 2, 3]
result1 = largestRectangleArea(heights1)  # Output: 10
print(result1)

heights2 = [2, 4]
result2 = largestRectangleArea(heights2)  # Output: 4
print(result2)
