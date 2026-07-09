from collections import defaultdict

typeKey = int
typeVal = int

class Node:
  def __init__(self, key: typeKey, val: typeVal) -> None:
    self.key: typeKey = key
    self.val: typeVal = val
    self.up: Node | None = None
    self.down: Node | None = None
    self.freq: int = 0

class LinkedList:
  def __init__(self) -> None:
    self.head = Node(0, 0)
    self.tail = Node(0, 0)

    self.head.down = self.tail
    self.tail.up = self.head

    self.size = 0

  def isEmpty(self) -> bool:
    if self.size == 0:
      return True
    return False

  def popLRU(self) -> Node | None:
    n = self.tail.up
    if n is self.head:
      return None
    if not n:
      return None
    self.remove(n)
    return n

  def insertRight(self, node: Node) -> None:
    self.size += 1
    curr = self.head.down
    if not curr:
      return
    self.head.down = node
    node.down, node.up = curr, self.head
    curr.up = node

  def remove(self, node: Node) -> None:
    before, after = node.up, node.down
    if not before or not after:
      return
    before.down = after
    after.up = before
    self.size -= 1


class LFUCache:
  def __init__(self, capacity: int):
    self.capacity = capacity
    self.cache: dict[typeKey, Node] = {}
    self.freq: defaultdict[typeKey, LinkedList] = defaultdict(LinkedList)
    self.minFreq: int = 0

  def updateFreq(self, node: Node) -> None:
    currFreq = node.freq

    self.freq[currFreq].remove(node)

    if currFreq == self.minFreq and self.freq[currFreq].isEmpty():
      del self.freq[currFreq]
      self.minFreq += 1

    node.freq += 1
    self.freq[node.freq].insertRight(node)

  def evictIfFull(self) -> None:
    if len(self.cache) == self.capacity:
      n = self.freq[self.minFreq].popLRU()
      if  n:
        del self.cache[n.key]

  def get(self, key: typeKey) -> typeVal:
    if key in self.cache:
      node = self.cache[key]
      self.updateFreq(node)
      return node.val

    return -1

  def put(self, key: typeKey, value: typeVal) -> None:
    if self.capacity == 0:
      return

    if key in self.cache:
      node = self.cache[key]
      node.val = value
      self.updateFreq(node)
      return

    self.evictIfFull()

    n = Node(key, value)
    n.freq = 1
    self.cache[key] = n
    self.freq[1].insertRight(n)
    self.minFreq = 1


def main() -> None:
  cache = LFUCache(3)

  cache.put(5,5)
  cache.put(5,6)
  cache.put(4,5)
  cache.put(3,5)
  cache.put(7,5)
  cache.get(5)
  print(cache.get(5))
  print(cache.get(3))


if __name__ == "__main__":
  main()
