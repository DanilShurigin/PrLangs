import random as rd

class Dice:
    def __init__(self, edges = 6, number = 1) -> None:
        self.edges = edges
        self.number = number
    
    def roll(self) -> tuple:
        roll_gen = (rd.randint(0, self.edges) for i in range(self.number))
        return tuple(roll_gen)

if( __name__ == '__main__' ):
    d1 = Dice()
    d2 = Dice(12, 3)
    print(f"Dice No1: {d1.roll()} | {d1.roll()}")
    print(f"Dice No2: {d2.roll()} | {d2.roll()}")