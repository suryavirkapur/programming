from collections import deque

q: deque[int] = deque()

q.append(5)
q.append(3)
q.append(7)
q.appendleft(5)

while q:
  print(q.popleft())


# we are gonna have to learn more about Qs
