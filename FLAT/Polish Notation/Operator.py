
class Operator:

    def __init__(self, symbol, arity, precedence, function):
        self.__symbol = symbol
        self.__arity = arity
        self.__precedence = precedence 
        self.__function = function
    
    @property
    def symbol(self):
        return self.__symbol
    
    @property
    def arity(self):
        return self.__arity

    @property
    def precedence(self):
        return self.__precedence

    @property
    def function(self, *args):
        #assert(len(args) == self.__arity)
        return self.__function