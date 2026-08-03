print("Hello, World")

arr = [1, 23, 4, 5, 68]
print([1, 2, 3, 4, 5])


print("before sorting:", arr)
arr.sort(reverse=True)
print("after sorting:", arr)


def twoSum(arr: list[int], target: int) -> tuple[int,int]:
  mp: dict[int,int] = {}
  for idx, val in enumerate(arr):
    comp = target - val
    if comp in mp:
      return idx, mp[comp]
    mp[val] = idx
  return -1, -1

def main() -> None:
  print("Something happens here")
  res = ""
  for i in range(1, 6, 1):
    res += str(i)
  print(res)
  # We can also enumerate
  for i, val in enumerate(arr, start = 1):
    # Using 1 based indexing we have
    print(f"{i} {val}")
  arr.reverse()
  for i, val in enumerate(arr):
    # Using 1 based indexing we have
    print(f"{i} {val}")

  # we can also solve two sum
  print(twoSum(arr, 27))


if __name__ == "__main__":
  main()
