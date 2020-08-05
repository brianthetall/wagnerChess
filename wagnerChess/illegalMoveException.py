class IllegalMoveException(Exception):
    
    def __init__(self, message="Illegal move!"):
        self.message = message
        super().__init__(self.message)
