import heapq
import sys


def kth_smallest(matrix: list[list[int]], k: int) -> int:
  ROWS = len(matrix)
  COLS = len(matrix[0])

  # Min-heap to store tuples of (value, row_index, col_index)
  heap = []

  # Initialize the heap with the first element of each row.
  # We only need at most k rows because the k-th element cannot be
  # lower than row k.
  for r in range(min(k, ROWS)):
    heapq.heappush(heap, (matrix[r][0], r, 0))

  ans = -1

  # Extract the minimum element k times
  for _ in range(k):
    ans, r, c = heapq.heappop(heap)

    # If there is another element in the same row, push it to the heap
    if c + 1 < COLS:
      heapq.heappush(heap, (matrix[r][c + 1], r, c + 1))

  return ans


if __name__ == "__main__":
  matrix = [[1, 5, 9], [10, 11, 13], [12, 13, 15]]
  k = 8
  res = kth_smallest(matrix, k)
  print(res)
`
