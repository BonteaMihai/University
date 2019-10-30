# Python program for expression tree 

# An expression tree node 
class ExpressionTreeNode: 

    # Constructor to create a node 
    def __init__(self , value):
        self.value = value 
        self.left = None
        self.right = None

        # Dictionary which associates to each symbol a function
        self.__funct = {'¬' : self.negation, '↔': self.equivalence, '→' : self.implication, '∨' : self.disjunction, '∧': self.conjunction}
   
    def inorder(self):
        if self.left != None:
            self.left.inorder()

        print (self.value, end = "")
         
        if self.right != None:
            self.right.inorder()
    
    def evaluate(self, value_dict, show_steps):
        # Leaf => operand, print its truth value
        if self.right == self.left == None:
            if show_steps == True:
                print("Atom " + self.value + ": " + str(value_dict[self.value]))
            
            return (value_dict[self.value], self.value)

        else:
            # Operator: negation
            if self.value == '¬':
                truth_val, string = self.left.evaluate(value_dict, show_steps)

                negated_truth_val = self.__funct[self.value](truth_val) 
                string = "(" + self.value + string + ")"
                if show_steps == True:
                    print(string + " is " + str(negated_truth_val))
                
                return (negated_truth_val, string)
            
            # Operator: other binary connective
            else:
                truth_val1, string1 = self.left.evaluate(value_dict, show_steps)

                truth_val2, string2 = self.right.evaluate(value_dict, show_steps)

                truth_val = self.__funct[self.value](truth_val1, truth_val2)
                string = "(" + string1 + self.value + string2 + ")"

                if show_steps == True:
                    print(string + " is " + str(truth_val))
                return (truth_val, string)

    @staticmethod
    def negation(truth_val):
        return not truth_val
    
    @staticmethod
    def conjunction(truth_val1, truth_val2):
        return truth_val1 and truth_val2
    
    @staticmethod
    def disjunction(truth_val1, truth_val2):
        return truth_val1 or truth_val2
    
    @staticmethod
    def implication(truth_val1, truth_val2):
        if truth_val1 == True and truth_val2 == False:
            return False
        return True
    
    @staticmethod
    def equivalence(truth_val1, truth_val2):
        return truth_val1 == truth_val2

  
class ExpressionTree:

    def __init__(self, postfix):

        self.postfix = postfix
        self.__connectives = ['↔', '→', '∨', '∧']
        self.__negation = '¬'

        self.root = self.__constructTree()
    
    # Returns the root of the constructed tree from the given postfix expression 
    def __constructTree(self): 
        stack = [] 
  
        # Traverse through every character of input expression 
        for char in self.postfix : 
  
            # Operand, simply push into stack 
            if char not in self.__connectives and char != self.__negation: 
                t = ExpressionTreeNode(char) 
                stack.append(t) 
  
            # Operator 
            else: 
                
                # Char is a connective different from negation(unary operator)
                if char in self.__connectives:
                    # Pop two top nodes 
                    t = ExpressionTreeNode(char) 
                    t1 = stack.pop() 
                    t2 = stack.pop() 
                
                    # make them children 
                    t.right = t1 
                    t.left = t2 
              
                    # Add this subexpression to stack 
                    stack.append(t)
                # Char is negation: will only pop 1 operand from the stack
                else:
                    t = ExpressionTreeNode(char)
                    t1 = stack.pop()

                    # Make the operand a child of negation
                    t.left = t1
                    # Add this subexpression to stack
                    stack.append(t)

        # Only element  will be the root of expression tree 
        t = stack.pop() 
     
        return t 

    def inorder_traversal(self):
        if self.root != None:
            self.root.inorder()

    def comp_truth_value(self, value_dict, show_steps):
        """
        Computes the truth value of the expression associated to the expression tree,
        based on 'value_dict', a dictionary which maps each propositional variable to
        a truth value. It also shows the steps
        """
        if self.root != None:
            return self.root.evaluate(value_dict, show_steps)[0]
        else:
            print("Empty expression!")


def test():
    et = ExpressionTree("A¬CD∧∨A¬∨")
    et.inorder_traversal()

#test() 