import argparse
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
    self.defAlphabet = 1

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
      self.args.alphabet = self.defAlphabet
    print('Verify complited successfully')


interface = Interface()
interface.VerifyInput()

