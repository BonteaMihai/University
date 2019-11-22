 
class Conversion: 
      
    def __init__(self): 
        self.st = [] 
        # Precedence setting 
        self.output = [] 
        self.precedence = {'¬':5, '∨':4, '∧':3, '→':2, '↔':1} 
      
    # Returns True if stack is empty, False otherwise
    def isEmpty(self): 
        return len(self.st) == 0
      
    # Returns the value at the top of the stack
    def top(self): 
        return self.st[-1] 
      
    # Pops the element from the stack 
    def pop(self): 
        if not self.isEmpty(): 
            return self.st.pop() 
      
    # Pushes the element to the stack 
    def push(self, op): 
        self.st.append(op)  
  
    # Returns True if character is an operand, False otherwise  
    def isOperand(self, ch): 
        return ch.isalpha() or ch == '⊥' or ch == '⊤'
  
    # Returns True if the precedence of operator is less than top of the stack, False otherwise
    def not_greater(self, i): 
        try: 
            prec1 = self.precedence[i] 
            prec2 = self.precedence[self.top()] 
            return prec1  < prec2
        except KeyError:  
            return False
              
    def infix_to_postfix_check(self, exp): 
        oprn_oprt = 0   # Grows with 1 when encountering an operand
                        # Decreases with 1 when encountering an operator
                        # String is not a WFF if the variable at any point goes below 0 or above 1

        negation = False # Gets set to True when encountering a negation
                         # String is not a WFF if a connective different from negation follows

        open_parentheses = 0    # Grows with 1 when encountering '('
                                # Decreases with 1 when encountering ')'
                                # String is not a WFF if the variable at any point goes below 0 or above 1


        for count, c in enumerate(exp): 
            # Operand, add it to output 
            if self.isOperand(c): 
                self.output.append(c)
                
                negation = False
                oprn_oprt += 1
                if oprn_oprt > 1:
                    print("String is not a WFF: expected connective at index " + str(count))
                    return False
              
            #'(', push it to stack
            elif c  == '(': 
                self.push(c)
                negation = False

                open_parentheses += 1
  
            #')', pop and output from the stack until reaching '(' 
            elif c == ')':

                open_parentheses -= 1
                if open_parentheses < 0:
                    print("String is not a WFF: ')' closed but not opened at index " + str(count))
                    return False
                
                if not self.isEmpty() and self.top() == '(':
                    print("String is not a WFF: redundant parentheses closing at index " + str(count))
                    return False
                    

                while not self.isEmpty() and self.top() != '(': 
                    a = self.pop() 
                    self.output.append(a) 

                if not self.isEmpty() and self.top() != '(': 
                    print("Error")
                    return False
                else: 
                    self.pop() 
  
            # Operator
            else:
                if count == len(exp) - 1:
                    print("String is not a WFF: expected WFF/Atom at index " + str(count))
                    return False
                
                if c != '¬':

                    oprn_oprt -= 1
                    if oprn_oprt < 0 or negation == True:
                        print("String is not a WFF: expected WFF/Atom at index " + str(count))
                        return False
                else:
                    negation = True

                while not self.isEmpty() and self.not_greater(c): 
                    self.output.append(self.pop()) 
                self.push(c) 
  
        # pop all the operators left from the stack 
        while not self.isEmpty(): 
            self.output.append(self.pop()) 
        
        if open_parentheses != 0:
            print("String is not a WFF: parentheses not closed properly!")

        if negation == True:
            print("String is not a WFF: no atom/WFF after negation!")
            return False

        return ("".join(self.output)) 

"""
exp = "P→Q∧⊤"
#exp = "PQ"
obj = Conversion() 

print(obj.infix_to_postfix_check(exp)) 
"""