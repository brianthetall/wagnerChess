class NotYourPieceException(Exception):
    
    def __init__(self, message="Not your piece to move!"):
        self.message = message
        super().__init__(self.message)
