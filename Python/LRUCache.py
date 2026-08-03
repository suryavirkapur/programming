# Doubly Linked List
class Node:
  def __init__(self, key: str, val: int) -> None:
    self.key: str = key
    self.val: int = val
    self.next: Node | None = None
    self.prev: Node | None = None


# LRU Cache
class LRUCache:
  def __init__(self, capacity: int) -> None:
    self.capacity = capacity
    self.cache: dict[str, Node] = {}
    self.right: Node = Node("dummy_right",0)
    self.left: Node = Node("dummy_left", 0)
    self.right.prev = self.left
    self.left.next = self.right

  def remove(self, node: Node) -> None:
    nodeAfter = node.next
    nodeBefore = node.prev
    if nodeAfter is None or nodeBefore is None:
      return
    nodeAfter.prev = nodeBefore
    nodeBefore.next = nodeAfter

  def insert(self, node: Node) -> None:
    curr = self.right.prev
    if curr is None:
      return
    self.right.prev = node
    curr.next = node
    node.prev = curr
    node.next = self.right

  def put(self, key: str, val: int) -> None:
    if key in self.cache:
      self.remove(self.cache[key])
      self.insert(self.cache[key])
      self.cache[key].val = val
    else:
      n = Node(key, val)
      self.cache[key] = n
      self.insert(n)
      if len(self.cache) > self.capacity and self.left.next is not None:
        nodeGone= self.left.next
        self.remove(nodeGone)
        del self.cache[nodeGone.key]

  def get(self, key: str) -> None | int:
    if key in self.cache:
      self.remove(self.cache[key])
      self.insert(self.cache[key])
      return self.cache[key].val
    else:
      return None


def main() -> None:
  cache = LRUCache(3)
  cache.put("Hello", 5)
  cache.put("World", 2)
  cache.put("Hello", 34345323)
  cache.put("X", 44)
  cache.put("Y", 55)
  print(cache.get("Hello"))
  print(cache.get("World"))
  print(cache.get("Y"))
  print(cache.get("X"))
  print(cache.get("Hello"))

if __name__ == "__main__":
  main()
