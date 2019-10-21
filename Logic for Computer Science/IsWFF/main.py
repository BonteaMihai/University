

class WFPropositionalFormula:

    def __init__(self, from_str):
        
        self.__connectives = ['↔', '→', '∨', '∧',]
        self.__negation = '¬'
        # This class variable will store the string of the expression
        # Removing all empty spaces from the string then storing it
        self.__expression = from_str.replace(' ', '')    
    
    def is_valid(self):
        """
        Wrapper function: returns True if the string given is a well formed propositional formula
                                  False otherwise
        """
        
        # this index will be used for going through the expression
        self.__index = 0

        # this variable  counts the number of parentheses opened but not closed yet
        # If it is non-zero at the end, or becomes less than zero at any moment, the expression is
        # invalid due to incorrect placing of the parentheses
        self.__open_parentheses = 0

        exp_validity =  self.__validate_expression()
        if exp_validity == False:
            return False

        if self.__open_parentheses < 0:
            print("Expression invalid: more closed parentheses than open parentheses!")
            return False
        elif self.__open_parentheses > 0:
            print("Expression invalid: there exist parentheses opened but not closed!")
            return False

        if self.__index < len(self.__expression):
            print("Expression is invalid: expression not fully enclosed in parentheses!")
            return False
        else:
            print("Expression is valid!")
            return True

    def __validate_expression(self):
        """
            Description: utility recursive function, returns true if the expression is valid, false otherwise
        """
        # Expression starts with '(', count it and increment the index 
        if self.__expression[self.__index] == '(':
            self.__open_parentheses += 1
            self.__index += 1

            # We have a negation inside parentheses
            if self.__expression[self.__index] == self.__negation:
                # Getting over the negation
                self.__index += 1
                # Validating the negated expression
                negated_exp = self.__validate_expression()

                if negated_exp == False:
                    return False

            # We should have 2 operands with a connective between them
            else:
                operand1 = self.__validate_expression()
                if operand1 == False:
                    return False

                if (self.__expression[self.__index] not in self.__connectives):
                    print("Expression is invalid: expected connective at index " + str(self.__index))
                    return False
                else:
                    self.__index += 1
                
                operand2 = self.__validate_expression()
                if operand2 == False:
                    return False
            
            # Either way, if the expression started with ')', it should end with ')'
            if self.__expression[self.__index] != ')':
                print("Expression is invalid: expected ) at index " + str(self.__index))
                return False
            else:
                self.__index += 1
                self.__open_parentheses -= 1
                return True

        # Expression does not start with '(' => it should be a propositional variable(uppercase letter)
        else:
            # If it is an uppercase letter, all is good
            if self.__expression[self.__index].isalpha() and self.__expression[self.__index].isupper():
                self.__index += 1
                return True
            else:
                print("Expression is invalid: expected uppercase letter at index" + str(self.__index) + " not " + self.__expression[self.__index])
                return False


"""
form1 = WFPropositionalFormula("(A ∨ B)")
form1.is_valid()

form2 = WFPropositionalFormula("((A ∨ B)↔(A ∨ B))")
form2.is_valid()


form3 = WFPropositionalFormula("(A ∨ B)↔(A ∨ B)")
form3.is_valid()

form4 = WFPropositionalFormula("((A B)↔(A ∨ B))")
form4.is_valid()

form5 = WFPropositionalFormula("(((P Q) ∨ S) ↔ T)")
form5.is_valid()

form6 = WFPropositionalFormula("(((↔ Q) ∨ S) ↔ T)")
form6.is_valid()
"""