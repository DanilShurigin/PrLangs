import argparse
import random as rd
from string import ascii_lowercase, ascii_uppercase, digits
from sys import argv

class Interface:
  def __init__(self) -> None:
    self.parser = argparse.ArgumentParser(
      prog = 'Password generator',
      description = 'Generating passwords'
    )

    self.parser.add_argument('-n', '--number',
                        type=int,
                        help='Number of passwords to generate'
                        )
    self.parser.add_argument('-s', '--size',
                        type=int,
                        help='Size of passwords to generate'
                        )
    self.parser.add_argument('-a', '--alphabet',
                        type=int,
                        choices=range(1, 4),
                        help='Characters that the password may contains (1 - 0..9 | 2 - 0..9a..z | 3 - 0..9Aa..Zz)')
    
    self.defNumber = 1

    self.args = self.parser.parse_args()
  
  def VerifyInput(self) -> None:
    if( len(argv) == 1 ):
      self.parser.print_help()
      exit(0)
    if( self.args.number == None ):
      self.args.number = 1
    elif( self.args.number < 1 ):
      print('Forbidden NUMBER value')
      raise ValueError
    
    if( self.args.size == None or self.args.size < 5 ):
      print('Forbidden SIZE value')
      raise ValueError
    
    if( self.args.alphabet == None ):
      self.args.alphabet = 1
  
  def get_number(self) -> int:
    return self.args.number
  def get_size(self) -> int:
    return self.args.size
  def get_alphabet(self) -> int:
    return self.args.alphabet

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


alphabets = [digits, ascii_lowercase, ascii_uppercase]
interface = Interface()
interface.VerifyInput()
pwg = Password(alphabets[:interface.get_alphabet()])

for _ in range(interface.get_number()):
  print(pwg.generate(interface.get_size()))