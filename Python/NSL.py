nums = [1, 2, 3, 5]


n = len(nums)
stack: list[int] = []
res: list[int] = []


print(nums)


for i in range(n):
  while stack and nums[stack[-1]] > nums[i]:
    stack.pop()

  if stack and nums[stack[-1]] < nums[i]:
    res.append(nums[stack[-1]])
  else:
    res.append(-1)

  stack.append(i)


print(res)
