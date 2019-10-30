 
class Conversion: 
      
    def __init__(self): 
        self.st = [] 
        # Precedence setting 
        self.output = [] 
        self.precedence = {'¬':1, '∨':2, '∧':3, '→':4, '↔':5} 
      
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
        return ch.isalpha() 
  
    # Returns True if the precedence of operator is less than top of the stack, False otherwise
    def not_greater(self, i): 
        try: 
            prec1 = self.precedence[i] 
            prec2 = self.precedence[self.top()] 
            return prec1  <= prec2
        except KeyError:  
            return False
              
    def infix_to_postfix(self, exp): 
           
        for c in exp: 
            # Operand, add it to output 
            if self.isOperand(c): 
                self.output.append(c) 
              
            #'(', push it to stack 
            elif c  == '(': 
                self.push(c) 
  
            #')', pop and output from the stack until reaching '(' 
            elif c == ')': 
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
                while not self.isEmpty() and self.not_greater(c): 
                    self.output.append(self.pop()) 
                self.push(c) 
  
        # pop all the operators left from the stack 
        while not self.isEmpty(): 
            self.output.append(self.pop()) 
  
        return ("".join(self.output)) 

"""
exp = "(((¬A)∨(C∧D))∨(¬A))"
obj = Conversion() 

print(obj.infix_to_postfix(exp)) 
"""