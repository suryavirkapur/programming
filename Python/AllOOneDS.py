# # Leetcode Problem No. 432


# from collections import defaultdict
# from heapq import heappop_max, heappush_max, heappush


# class AllOne:

#     def __init__(self):
#       self.cache: dict[str, int] = defaultdict(int)
#       self.minHeap: list[tuple[int, str]] = []
#       self.maxHeap: list[tuple[int, str]] = []


#     def inc(self, key: str) -> None:
#       self.cache[key] += 1
#       heappush_max(self.maxHeap, (self.cache[key], key))
#       heappush(self.minHeap, (self.cache[key], key))

#     def dec(self, key: str) -> None:
#       self.cache[key] -= 1
#       if self.cache[key] == 0:
#         del self.cache[key]
#       heappush_max(self.maxHeap, (self.cache[key], key))
#       heappush(self.minHeap, (self.cache[key], key))


#     def getMaxKey(self) -> str:
#       if len(self.cache) == 0:
#        return ""
#       while self.maxHeap and self.maxHeap[0][0] != self.cache[self.maxHeap[0][1]]:
#         heappop_max(self.maxHeap)
#       return self.maxHeap[0][1]


#     def getMinKey(self) -> str:
#       if len(self.cache) == 0:
#        return ""
#       while self.minHeap and self.minHeap[0][0] != self.cache[self.minHeap[0][1]]:
#         heappop_max(self.minHeap)
#       return self.minHeap[0][1]


### Above Approach will not be O(1)


from collections import defaultdict


class Node:
  def __init__(self, level: int):
    self.level: int = 1
    self.values: set[str] = set()
    self.head: Node | None = None
    self.tail: Node | None = None


class AllOne:

    def __init__(self):
      self.cache: defaultdict[str, Node]
      self.head = Node(-1)
      self.tail = Node(-1)

      self.head.tail = self.tail
      self.tail.head = self.head

    def add_node_after(self, node: Node):

      curr = node
      if not node.tail:
        return
      node = node.tail
      self.node = node



    def inc(self, key: str) -> None:


    def dec(self, key: str) -> None:


    def getMaxKey(self) -> str:


    def getMinKey(self) -> str:
