from InfixToPostfix import Conversion
from ExpressionTree import *
import copy

class WFPropositionalFormula:

    def __init__(self, from_str):
        
        self.__connectives = ['↔', '→', '∨', '∧']
        self.__negation = '¬'
        # This class variable will store the string of the expression
        # Removing all empty spaces from the string then storing it
        self.__expression = from_str.replace(' ', '')    
        self.__expression_tree = None
    
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
            print("String is not a formula : more closed parentheses than open parentheses!")
            return False
        elif self.__open_parentheses > 0:
            print("String is not a formula: there exist parentheses opened but not closed!")
            return False

        if self.__index < len(self.__expression):
            print("String is not a formula: expression not fully enclosed in parentheses!")
            return False
        else:
            print("String is a well formed propositional formula!")
            return True

    def store_as_exp_tree(self):
        # If it is a well formed propositional formula, convert it to postfix and 
        # Store it a an expression tree, before returning True
        obj = Conversion()
        postfix = obj.infix_to_postfix(self.__expression)
        self.__expression_tree = ExpressionTree(postfix)
        #self.__expression_tree.inorder_traversal()
        return True
    
    def compute_truth_value(self, value_dict):
        """
        Computes the truth value of the proposition under the interpretation given by the
        dictionary value_dict
        """
        self.__expression_tree.comp_truth_value(value_dict, True)
    
    def proposition_type(self, atoms):
        """
        Uses the utility function __back generate all possible interpretations for a
        proposition, then computes the truth value of the proposition with respect to those
        interpretations, in order to determine whether it's a tautology/satisfiable/inconsistent
        """   

        self.__interpretations = []
        self.__atoms = atoms

        self.__back({}, 0)

        #print(self.__interpretations)

        all_true = True
        one_true = False


        for intr in self.__interpretations:
            if self.__expression_tree.comp_truth_value(intr, True) == False:
                print()
                all_true = False
            else:
                one_true = True
        
        if all_true == True:
            print("The propositional formula given is valid(tautology)!")
        elif one_true == True:
            print("The propositional formula given is satisfiable!")
        else:
            print("The propositional formula given is inconsistent!")

    def __back(self, value_dict, pos):
        """
        Utility function, creates all possible interpretations and stores them into the class variable
        self.__interpretations
        """
        
        if pos == len(self.__atoms):
            obj = copy.deepcopy(value_dict)
            self.__interpretations.append(obj)
        else:

            value_dict[self.__atoms[pos]] = True
            self.__back(value_dict, pos + 1)

            value_dict[self.__atoms[pos]] = False
            self.__back(value_dict, pos + 1)


    def print_exp_tree(self):
        """
        Prints the expression tree associated to the proposition
        """
        if self.__expression_tree != None:
            self.__expression_tree.inorder_traversal()

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
                if (self.__index < len(self.__expression)):
                    operand1 = self.__validate_expression()
                    if operand1 == False:
                        return False
                else:
                    print("String is not a formula: expected operand at index " + str(self.__index) + " but string ended")
                    return False

                if (self.__index < len(self.__expression)):
                    if (self.__expression[self.__index] not in self.__connectives):
                        print("String is not a formula: expected connective at index " + str(self.__index))
                        return False
                    else:
                        self.__index += 1
                else:
                    print("String is not a formula: expected connective at index " + str(self.__index) + " but string ended")
                
                if (self.__index < len(self.__expression)):
                    operand2 = self.__validate_expression()
                    if operand2 == False:
                        return False
                else:
                    print("String is not a formula: expected operand at index " + str(self.__index) + " but string ended")
                    return False

            
            # Either way, if the expression started with ')', it should end with ')'
            if self.__index >= len(self.__expression):
                print("String is not a formula: expected ) at index " + str(self.__index) + " but string ended.")
                return False

            elif self.__expression[self.__index] != ')':
                print("String is not a formula: expected ) at index " + str(self.__index))
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
                print("String is not a formula: expected uppercase letter/WFF at index " + str(self.__index) + " not " + self.__expression[self.__index])
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