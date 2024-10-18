def largestRectangleArea(heights):
    stack = []
    max_area = 0
    heights.append(0)  # Append a height of 0 to flush out remaining bars in the stack

    for i in range(len(heights)):
        while stack and heights[i] < heights[stack[-1]]:
            h = heights[stack.pop()]  # Get the height of the top bar
            width = i if not stack else i - stack[-1] - 1  # Calculate the width
            max_area = max(max_area, h * width)  # Update the max area
        stack.append(i)  # Push the current index to the stack

    return max_area

# Example usage
heights1 = [2, 1, 5, 6, 2, 3]
result1 = largestRectangleArea(heights1)  # Output: 10
print(result1)

heights2 = [2, 4]
result2 = largestRectangleArea(heights2)  # Output: 4
print(result2)
