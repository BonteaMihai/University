class Expression():

    def __init__(self, exp):
        
        # Removing all empty spaces from the string then storing it
        self.__exp = exp.replace(' ', '')

    def is_valid(self):
        """
            Description: wrapper function, returns true if the expression is valid, false otherwise

            Best Case = O(1)
            Average Case = O(n)
            Worst Case = O(n)
        """
        # this index will be used for going through the expression
        self.__index = 0
        
        # this variable  counts the number of parentheses opened but not closed yet
        self.__open_parentheses = 0

        return self.__validate_expression()

    def __validate_expression(self):
        """
            Description: utility function, returns true if the expression is valid, false otherwise
        """

        t_truth = self.__validate_term()

        # While the terms are valid and there are more terms
        while t_truth and self.__index < len(self.__exp) and self.__exp[self.__index] == '+':
            self.__index += 1
            t_truth = self.__validate_term()
        
        if t_truth and self.__index < len(self.__exp):
            if self.__exp[self.__index] != ')' or (self.__exp[self.__index] == ')' and self.__open_parentheses == 0):
                return False
        return t_truth

    def __validate_term(self):
        """
            Description: utility function, returns true if the term is valid, false otherwise
        """
        
        f_truth = self.__validate_factor()

        # While the factors are valid and there are more factors
        while f_truth and self.__index < len(self.__exp) and self.__exp[self.__index] == '*':
            self.__index += 1
            f_truth = self.__validate_factor()
        
        return f_truth

    def __validate_factor(self):
        """
            Description: utility function, returns true if the factor is valid, false otherwise
        """
        # If the factor is an expression between parentheses,
        if self.__exp[self.__index] == '(':
            self.__open_parentheses += 1
            self.__index += 1

            if self.__validate_expression() == False:
                return False
            
            # '(' was opened but not closed!
            if self.__index >= len(self.__exp) or self.__exp[self.__index] != ')':
                return False
            else:
                self.__index += 1
                self.__open_parentheses -= 1
        else:
            if self.__exp[self.__index].isdigit():
                while self.__index < len(self.__exp) and self.__exp[self.__index].isdigit():
                    self.__index += 1
            else:
                return False

        return True


def test_class():

    # Simple expression with 1 digit numbers and no parentheses
    assert(Expression("1 + 2 * 3 + 5 * 6").is_valid() == True)

    # Simple expression with larger numbers and no parentheses
    assert(Expression("11242 + 29999 * 153 + 510 * 63830").is_valid() == True)

    # Expression containing parentheses
    assert(Expression("1 + 12 * (3 * 2) + (5 + 2) + 12 * 34 + 12").is_valid() == True)

    # Expression containing parentheses inside other parentheses
    assert(Expression("1 + (((2 + 3) * 4) + (5 + 6 * 3))").is_valid() == True)

    # Expression with parentheses closed incorrectly
    assert(Expression("1 + (((2 + 3) * 4 + (5 + 6 * 3))").is_valid() == False)

    # Expression with operators in a row
    assert(Expression("1 ++ 3").is_valid() == False)

test_class()
