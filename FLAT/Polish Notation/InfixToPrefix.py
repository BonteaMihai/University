from Operator import Operator

class Converter:

    def __init__(self, operators, string):
        self.__operators = operators
        self.__string = string

    def __is_operator(self, symbol):
        for operator in self.__operators:
            if operator.symbol == symbol:
                return True
        return False

    def __get_priority(self, symbol):
        for operator in self.__operators:
            if operator.symbol == symbol:
                return operator.precedence
        return 0

    def __get_function(self, symbol):
        for operator in self.__operators:
            if operator.symbol == symbol:
                return operator.function
    
    def infix_to_prefix(self):
        operators_stack = []
        operands_stack = []

        for character in self.__string:

            if character == '(':
                operators_stack.append(character)
            
            elif character == ')':
                while len(operators_stack) != 0 and operators_stack[-1] != '(':
                    op1 = operands_stack[-1]
                    operands_stack.pop(-1)

                    op2 = operands_stack[-1]
                    operands_stack.pop(-1)

                    op = operators_stack[-1]
                    operators_stack.pop(-1)

                    comb = op + op2 + op1

                    operands_stack.append(comb)

                operators_stack.pop(-1)
            
            elif not self.__is_operator(character):
                operands_stack.append(character)
            
            else:
                while len(operators_stack) != 0 and self.__get_priority(character) <= self.__get_priority(operators_stack[-1]):

                    op1 = operands_stack[-1]
                    operands_stack.pop(-1)

                    op2 = operands_stack[-1]
                    operands_stack.pop(-1)

                    op = operators_stack[-1]
                    operators_stack.pop(-1)

                    comb = op + op2 + op1

                    operands_stack.append(comb)
                
                operators_stack.append(character)

        while len(operators_stack) != 0:
            op1 = operands_stack[-1]
            operands_stack.pop(-1)

            op2 = operands_stack[-1]
            operands_stack.pop(-1)

            op = operators_stack[-1]
            operators_stack.pop(-1)

            comb = op + op2 + op1
            operands_stack.append(comb)

        return operands_stack[-1]


    def evaluate_expression(self, variable_dict):
        prefix = self.infix_to_prefix()
        self.__string = prefix
        self.__index = 0
        return self.__evaluate_expression(variable_dict)
    
    def __evaluate_expression(self, variable_dict):
        if self.__is_operator(self.__string[self.__index]):
            funct = self.__get_function(self.__string[self.__index])
            self.__index += 1
            op1 = self.__evaluate_expression(variable_dict)
            self.__index += 1
            op2 = self.__evaluate_expression(variable_dict)

            temp = funct(op1, op2)
            
            return temp
        else:
            temp = variable_dict[self.__string[self.__index]]
            return temp