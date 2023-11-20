import random as rd
from string import ascii_letters

def createRandomName(size:int, suffix:str) -> str:
  return ''.join(rd.choice(ascii_letters) for _ in range(size)) + suffix

for _ in range(5):
  print(createRandomName(rd.randint(5,15), '.test'))