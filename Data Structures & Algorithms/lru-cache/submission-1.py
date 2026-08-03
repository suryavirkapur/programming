class Node:
    def __init__(self, key: int, val: int):
        self.key = key
        self.val = val
        self.next = None
        self.prev = None

class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache = {}

        self.head = Node(float('inf'), -1)
        self.tail = Node(float('inf'), -2)

        self.head.next = self.tail
        self.tail.prev = self.head


    def add_to_head(self, node) -> None:
        nxt = self.head.next
        
        node.next = nxt
        node.prev = self.head
        
        self.head.next = node
        nxt.prev = node
    
    def remove(self, node) -> None:
        prv, nxt = node.prev, node.next

        prv.next = nxt
        nxt.prev = prv

        node.next = node.prev = None


    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1
        
        node = self.cache[key]
        
        self.remove(node)
        self.add_to_head(node)

        return node.val
        

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            node  = self.cache[key]
            node.val = value
            self.remove(node)
            self.add_to_head(node)
            return
        node = Node(key, value)
        if len(self.cache) >= self.capacity:
            to_remove = self.cache[self.tail.prev.key]
            del self.cache[to_remove.key]
            self.remove(to_remove)
        self.add_to_head(node)
        self.cache[key] = node
        
        
