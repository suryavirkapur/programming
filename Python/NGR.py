nums = [5, 3, 2, 1]
n = len(nums)
nums.reverse()
stack: list[int] = []
res: list[int] = []
print(nums)
for i in range(n - 1, -1, -1):
  while stack and nums[stack[-1]] < nums[i]:
    stack.pop()

  if stack and nums[stack[-1]] > nums[i]:
    res.append(nums[stack[-1]])
  else:
    res.append(-1)

  stack.append(i)

res.reverse()
print(res)
