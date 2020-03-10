from InfixToPrefix import Converter
from Operator import Operator

class Controller:

    def __init__(self):
        # Hardcoding the common operators
        add = Operator('+', 2, 1, lambda a, b : a + b)
        sub = Operator('-', 2, 1, lambda a, b : a - b)
        mul = Operator('*', 2, 2, lambda a, b : a * b)
        div = Operator('/', 2, 2, lambda a, b : a // b)
        pw = Operator('^', 2, 3, lambda a, b : a ** b)

        self.operators = [add, sub, mul, div, pw]

    def infix_to_prefix(self, string):
        conv = Converter(self.operators, string)
        return conv.infix_to_prefix()

    def evaluate_expression(self, string, variable_dict):
        conv = Converter(self.operators, string)
        return conv.evaluate_expression(variable_dict)