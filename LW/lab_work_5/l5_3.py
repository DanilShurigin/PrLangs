import random as rd
from l5_2 import Dice

def getStatistics(experiments_number:int, object:Dice) -> dict:
  statistics = dict.fromkeys(range(2, 13), 0)
  rolls = tuple(sum(object.roll()) for _ in range(experiments_number))
  for key in statistics.keys():
    statistics[key] = rolls.count(key)
  return statistics

d1 = Dice(rd.random(), 6, 2)
for key, value in getStatistics(100000, d1).items():
  print(f"{key:2} : {value}")