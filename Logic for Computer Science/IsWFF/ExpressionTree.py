# Python program for expression tree 
  
# An expression tree node 
class ExpressionTreeNode: 
  
    # Constructor to create a node 
    def __init__(self , value): 
        self.value = value 
        self.left = None
        self.right = None
   
    def inorder(self):
        if self.left != None:
            self.left.inorder()

        print (self.value, end = "")
         
        if self.right != None:
            self.right.inorder()
  

  
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


def test():
    et = ExpressionTree("A¬CD∧∨A¬∨")
    et.inorder_traversal()

#test() 