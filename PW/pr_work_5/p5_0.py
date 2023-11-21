class Glass:
    def __init__(self, volume):
        self.volume_ = volume
        self.liquid_ = {
            'name': None,
            'volume': 0
        }
    
    def fill(self, liquid_name, liquid_volume):
        if( self.liquid_['name'] != None 
            and self.liquid_['name'] != liquid_name ):
            raise ValueError
        
        if( (self.volume_ - self.liquid_['volume']) < liquid_volume ):
            raise OverflowError

        self.liquid_['name'] = liquid_name
        self.liquid_['volume'] += liquid_volume
    
    def look(self):
        return self.liquid_['name']
    
    def drink(self, liquid_volume):
        delta = self.liquid_['volume'] - liquid_volume
        is_done = False

        if( delta >= 0 ):
            is_done = True
        
        if( delta <= 0 ):
            self.liquid_['name'] = None
            self.liquid_['volume'] = 0
        else:
            self.liquid_['volume'] = delta
        
        return is_done
        
