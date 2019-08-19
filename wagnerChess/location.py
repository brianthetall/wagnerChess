class Location(object):
                    
    def __init__(self,x,y):

        #this is probably useful for equals()
        self.letterMap={"A":[0],
                        "B":[-1,1],
                        "C":[-1,0,1],
                        "D":[-2,-1,1,2],
                        "E":[-2,-1,0,1,2],
                        "F":[-3,-2,-1,1,2,3],
                        "G":[-3,-2,-1,0,1,2,3],
                        "H":[-4,-3,-2,-1,1,2,3,4],
                        "I":[-3,-2,-1,0,1,2,3],
                        "J":[-3,-2,-1,1,2,3],
                        "K":[-2,-1,0,1,2],
                        "L":[-2,-1,1,2],
                        "M":[-1,0,1],
                        "N":[-1,1],
                        "O":[0]
        }
                
        try:
            if x not in range(0,7) or y not in range(0,7):
                raise Exception("invalid x or y range: %d,%d" % (x,y))
            self.x=x
            self.y=y

        except Exception:
            print "Did you send an int? Type=%s,%s"%(type(x),type(y))
            raise
        
        self.piece=None


    def get(self):
        return self.x,self.y

    #given the other player sees the board differently, this function resolves if two coordinates are equal
    def equals(self,location):
        if not isinstance(location,Location):
            raise Exception("not a Loation")

        xs,ys=location.get()
        if 
