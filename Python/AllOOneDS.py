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


from sys import maxsize

class Node:
  def __init__(self, count: int):
    self.count = count
    self.keys: set[str] = set()
    self.next: Node | None = None
    self.prev: Node | None = None


class AllOne:

    def __init__(self):
      self.cache: dict[str, Node] = {}
      self.head = Node(0)
      self.tail = Node(maxsize)

      self.head.next = self.tail
      self.tail.prev = self.head

    def add_node_after(self, node: Node, prev_node: Node):
      """Add after last node"""
      currNode  = prev_node.next
      if not currNode:
        return
      prev_node.next = node
      node.prev = prev_node
      node.next = currNode
      currNode.prev = node

    def remove(self, node: Node):
      prev, next = node.prev, node.next

      if not prev or not next:
        return
      prev.next, next.prev = next, prev

    def inc(self, key: str) -> None:
      """This thing is wrong"""
      if key not in self.cache:
        """insert the key"""
        currNode = self.head.next
        if currNode and currNode.count != 1:
          node = Node(1)
          self.add_node_after(node, self.head)
          currNode = node
        if not currNode:
          return
        currNode.keys.add(key)
        self.cache[key] = currNode
      else:
        currNode = self.cache[key]
        if currNode.next and currNode.next.count != currNode.count + 1 :
          new_node = Node(currNode.count + 1)
          self.add_node_after(new_node, currNode)
        if not currNode.next:
          return
        currNode.next.keys.add(key)
        currNode.keys.remove(key)
        if not currNode.keys:
          self.remove(currNode)
        del self.cache[key]
        self.cache[key] = currNode.next


    def dec(self, key: str) -> None:
      """This thing is wrong!"""
      if self.cache[key].count == 1:
        node = self.cache[key]
        node.keys.remove(key)
        if not node.keys:
          self.remove(node)
        del self.cache[key]
      else:
        node = self.cache[key]
        prev = node.prev
        if not prev:
          return
        if prev == self.head or prev.count != node.count - 1:
          newNode = Node(node.count - 1)
          self.add_node_after(newNode, prev)
          prev = newNode

        node.keys.remove(key)
        if not node.keys:
          self.remove(node)

        self.cache[key] = prev
        prev.keys.add(key)


    def getMaxKey(self) -> str:
      if self.tail.prev == self.head or not self.tail.prev:
        return ""
      return next(iter(self.tail.prev.keys))

    def getMinKey(self) -> str:
      if self.head.next == self.tail or not self.head.next:
        return ""
      return next(iter(self.head.next.keys))
