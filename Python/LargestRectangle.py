def largestRectangleArea(heights):
  stack = []
  max_area = 0
  heights.append(0)

  for i, h in enumerate(heights):
    while stack and heights[stack[-1]] > h:
      height = heights[stack.pop()]

    stack.append(i)
  return max_area
