class Solution:
  def minimumCost(self, nums: list[int], k: int) -> int:
    resources = k
    cost = 0
    costCost = 1

    s = sum(nums)

    if s < k:
      return 0

    for n in nums:
      print(n)
      if resources >= n:
        resources -= n
      else:
        while resources < n:
          cost += costCost
          costCost += 1
          resources += k
        resources -= n

    mod = 10**9 + 7
    print(cost)
    return cost % mod


x = Solution()
print(x.minimumCost([1, 2, 7, 14], 4))
