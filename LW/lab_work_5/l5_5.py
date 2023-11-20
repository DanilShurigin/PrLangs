import random as rd
from string import ascii_letters, digits, punctuation

class Password:
  def __init__(self, pass_sets:list) -> None:
    self.alphabets = tuple(pass_sets)
    self.unitedAlphabet = ''.join(pass_sets)
  
  def generate(self, size:int) -> str:
    required__part = list(rd.choice(s) for s in self.alphabets)
    last_part = list(rd.choice(self.unitedAlphabet) for _ in range(size-len(self.alphabets)))
    password = required__part+last_part
    rd.shuffle(password)
    return ''.join(password)

if( __name__ == '__main__' ):
  def countInList(arr, alphabet):
    return len(list(x for x in arr if x in alphabet))
  
  p1 = Password([ascii_letters])
  p2 = Password([ascii_letters, digits])
  p3 = Password([ascii_letters, digits, punctuation])
  passGenList = (p1, p2, p3)
  print('{:<5}{:<5}{:^30}{:<5}{:<5}{:<5}\n'
        .format(
          'Size',
          'N',
          'Password',
          'L',
          'D',
          'P'
        ))
  for size in (7, 10, 15, 23):
    for ind, obj in enumerate(passGenList):
      new_pass = obj.generate(size)
      print('{:<5}{:<5}{:^30}{:<5}{:<5}{:<5}'
            .format(
              size,
              ind+1,
              new_pass,
              countInList(new_pass, ascii_letters),
              countInList(new_pass, digits),
              countInList(new_pass, punctuation)
            ))
    print()
