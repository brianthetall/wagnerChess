class InCheckException(Exception):
    
    def __init__(self, message="That would place you in Check!"):
        self.message = message
        super().__init__(self.message)
