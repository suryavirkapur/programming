import heapq

# Heap is Priority Queue
# Elements Insertion: O(log n)
# Elements Deletion:  O(log n)
# Top Element: Min/Max -> MinHeap or MaxHeap [LookUp: O(1)]

typeTimestamp = int

class StockPrice:

    def __init__(self):
        self.maxHeap: list[tuple[int, typeTimestamp]] = []
        self.minHeap: list[tuple[int, typeTimestamp]] = []
        self.latestTimestamp: int = 0
        self.cache: dict[int,int] = {}

    def update(self, timestamp: typeTimestamp, price: int) -> None:
      heapq.heappush_max(self.maxHeap, (price, timestamp))
      heapq.heappush(self.minHeap, (price, timestamp))
      self.cache[timestamp] = price
      self.latestTimestamp = max(self.latestTimestamp, timestamp)

    def current(self) -> int:
      return self.cache[self.latestTimestamp]

    def maximum(self) -> int:
      while self.maxHeap[0] and self.maxHeap[0][0] != self.cache[self.maxHeap[0][1]]:
        heapq.heappop_max(self.maxHeap)
      return self.maxHeap[0][0]

    def minimum(self) -> int:
      while self.minHeap[0] and self.minHeap[0][0] != self.cache[self.minHeap[0][1]]:
        heapq.heappop(self.maxHeap)
      return self.minHeap[0][0]
