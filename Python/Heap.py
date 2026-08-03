import heapq

minHeap: list[int] = [5,4,5,3,35,3,423,4324,324,234]
maxHeap: list[int] = [7,8,5,3,5,567,34]

heapq.heapify(minHeap)

heapq.heapify_max(maxHeap)


print(minHeap)
print(maxHeap)
