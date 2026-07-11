from collections import defaultdict
from typing import List
import heapq
class FoodRatings:

    def __init__(self, foods: List[str], cuisines: List[str], ratings: List[int]):
        self.cuisine: dict[str, list[tuple[int,str]]] = defaultdict(list)
        self.rating: dict[str, int] = {}
        self.food: dict[str, str] = {}

        for food, rating in zip(foods, ratings):
          self.rating[food] = rating


        for food, cuisine in zip(foods, cuisines):
          self.food[food] = cuisine
          heapq.heappush(self.cuisine[cuisine], (-self.rating[food], food))



    def changeRating(self, food: str, newRating: int) -> None:
      self.rating[food] = newRating
      heapq.heappush(self.cuisine[self.food[food]], (-self.rating[food], food))



    def highestRated(self, cuisine: str) -> str:
      while len(self.cuisine[cuisine]) and self.cuisine[cuisine][0][0] != self.rating[self.cuisine[cuisine][0][1]]:
        heapq.heappop(self.cuisine[cuisine])

      return self.cuisine[cuisine][0][1]
