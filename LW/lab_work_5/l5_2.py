import random as rd

class Dice:
  def __init__(self, seed, edges = 6, number = 1) -> None:
    rd.seed(seed)
    self.state = rd.getstate()
    self.edges = edges
    self.number = number
  
  def getRandomEdge(self):
    for _ in range(self.number):
      rd.setstate(self.state)
      yield rd.randint(1, self.edges)
      self.state = rd.getstate()
    
  def roll(self) -> tuple:
    return tuple(self.getRandomEdge())

if( __name__ == '__main__' ):
  d1 = Dice(21, 6, 2)
  d2 = Dice(21, 6, 2)
  d3 = Dice(21, 6, 2)
  print('Dice 1\tDice 2\tDice 3')
  for _ in range(5):
    print(f"{d1.roll()}\t{d2.roll()}\t{d3.roll()}")