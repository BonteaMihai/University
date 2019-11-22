# An expression tree node
from COLORS import style 
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
    
    def inorder_parentheses(self):
        
        if self.value in ['↔', '→', '∨', '∧']:
            string = '(' + self.left.inorder_parentheses() + self.value + self.right.inorder_parentheses() + ')'
            return string
        elif self.value == '¬':
            string = '(¬' + self.left.inorder_parentheses() + ')'
            return string
        else:
            return self.value
    
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
        #print(self.postfix)
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

    def convert_to_NNF(self, show_steps):

        # Applying the idempocy laws
        self.__idempocy_laws(show_steps)

        # Applying the annihilation laws
        self.__annihilation_laws(show_steps)

        # Applying the laws of true and false
        self.__true_false_laws(show_steps)
        
        # Applying the reduction laws to eliminate equivalences and implications
        self.__reduction_laws(show_steps)

        # Applying the negation laws
        self.__negation_laws(show_steps)
        
    """ ###########################################################################
                                Reduction laws functions
    """

    def __reduction_laws(self, show_steps):
        # Initializing the modified flag with False
        self.__modified_flag = False
        self.__reduce_eq_wrapper()
        
        if show_steps == True and self.__modified_flag == True:
            print(style.GREEN("Reducing equivalences: (F↔G) ~ (F→G)∧(G→F)") + style.RESET(""))
            self.inorder_parentheses()

        # Initializing the modified flag with False
        self.__modified_flag = False
        self.__reduce_impl_wrapper()
        
        if show_steps == True and self.__modified_flag == True:
            print(style.GREEN("Reducing implications: (F→G) ~ (¬F∨G)") + style.RESET(""))
            self.inorder_parentheses()

    def __reduce_eq_wrapper(self):
        self.__reduce_eq(self.root)

    def __reduce_eq(self, node):
        
        if node.value == '↔':
            # Setting the modified flag to True
            self.__modified_flag = True

            #Changing the node value to '∧'
            node.value = '∧'

            # These will be the new children of the current node
            new_left = ExpressionTreeNode('→')
            new_right = ExpressionTreeNode('→')

            # Setting the children of the new left child of node
            new_left.left = node.left
            new_left.right = node.right

            # Setting the children of the new right child of node
            new_right.left = node.right
            new_right.right = node.left

            # Updating the children of node
            node.left = new_left
            node.right = new_right

            # Call the function for the new left child(will update for right sub-tree too since references)
            self.__reduce_eq(node.left)
        
        else:
            if node.left != None:
                self.__reduce_eq(node.left)
            if node.right != None:
                self.__reduce_eq(node.right)

    def __reduce_impl_wrapper(self):
        self.__reduce_impl(self.root)
    
    def __reduce_impl(self, node):
        if node.value == '→':
            # Setting the modified flag to True
            self.__modified_flag = True

            # Changing the node value to '∨'
            node.value = '∨'

            # Creating a new left child for the current node, containing '¬'
            new_left = ExpressionTreeNode('¬')
            new_left.left = node.left

            # Updating the children of node
            node.left = new_left

        # Call the function for its children
        if node.left != None:
            self.__reduce_impl(node.left)
        if node.right != None:
            self.__reduce_impl(node.right)

    """ ###########################################################################
                                Idempocy laws functions
    """

    def __idempocy_laws(self, show_steps):
        # Initializing the modified flag with False
        self.__modified_flag = False
        self.root, string = self.__apply_idempocy(self.root)

        if show_steps == True and self.__modified_flag == True:
            print(style.GREEN("Applying idempocy laws: F∧F ~ F, F∨F ~ F") + style.RESET(""))
            self.inorder_parentheses()

    def __apply_idempocy(self, node):
        str_left = ""
        str_right = ""

        # Binary connectives
        if node.value in self.__connectives:
            node.left, str_left = self.__apply_idempocy(node.left)
            node.right, str_right = self.__apply_idempocy(node.right)
        # Unary connective
        elif node.value == self.__negation:
            node.left, str_left = self.__apply_idempocy(node.left)
        # Atom
        else:
            return (node, node.value)

        # Or / And connective
        if (node.value == '∨' or node.value == '∧') and str_left == str_right:
            # Return the node containing the child(Apply idempocy)
            # Set the modified flag to True
            self.__modified_flag = True
            return (node.left, str_left)
        elif node.value in self.__connectives:
            return (node, '(' + str_left + node.value + str_right + ')')
        elif node.value == self.__negation:
            return (node, '(' + node.value + str_left + ')')
        else:
            return (node, node.value)

    """ ###########################################################################
                                Annihilation laws functions 
    """

    def __annihilation_laws(self, show_steps):
        # Initializing the modified flag with False
        self.__modified_flag = False
        self.__apply_annihilation(self.root)
        
        if show_steps == True and self.__modified_flag == True:
            print(style.GREEN("Applying annihilation laws: F∨¬F ~ ⊤, F∧¬F ~ ⊥") + style.RESET(""))
            self.inorder_parentheses()

    def __apply_annihilation(self, node):
        str_left = ""
        str_right = ""

        # Binary connectives
        if node.value in self.__connectives:
            str_left = self.__apply_annihilation(node.left)
            str_right = self.__apply_annihilation(node.right)
        # Unary connective
        elif node.value == self.__negation:
            str_left = self.__apply_annihilation(node.left)
        # Atom
        else:
            return node.value
        
        # Implication + Annihilation
        if node.value == '→' and str_left == str_right:
            # Setting the modified flag to True
            self.__modified_flag = True
            # Changing the value of the node to 'T'
            node.value = '⊤'
            
            # Deleting the children nodes
            node.left = None
            node.right = None

            return node.value
        
        # Disjunction + Annihilation
        elif node.value == '∨' and ('(¬' + str_left + ')' == str_right or str_left == '(¬' + str_right + ')'):
            # Setting the modified flag to True
            self.__modified_flag = True
            # Changing the value of the node to 'T'
            node.value = '⊤'

            # Deleting the children nodes
            node.left = None
            node.right = None

            return node.value
        
        # Conjunction + Annihilation
        elif node.value == '∧' and ('(¬' + str_left + ')' == str_right or str_left == '(¬' + str_right + ')'):
            # Setting the modified flag to True
            self.__modified_flag = True
            # Changing the value of the node to '⊥'
            node.value = '⊥'

            # Deleting the children nodes
            node.left = None
            node.right = None

            return node.value
        
        # Binary connective
        elif node.value in self.__connectives:
            return '(' + str_left + node.value + str_right + ')'
        # Unary connective(negation)
        elif node.value == self.__negation:
            return '(' + node.value + str_left + ')'
        # Atom
        else:
            return node.value
    
    """ ###########################################################################
                                Laws of True and False functions
    """

    def __true_false_laws(self, show_steps):
        # Initializing the modified flag with False
        self.__modified_flag = False
        self.root = self.__apply_true_false(self.root)

        if show_steps == True and self.__modified_flag == True:
            print(style.GREEN("Applying laws of 'True' and 'False': ") + style.RESET(""))
            self.inorder_parentheses()

    def __apply_true_false(self, node):
        
        # Binary connective
        if node.value in self.__connectives:
            node.left = self.__apply_true_false(node.left)
            node.right = self.__apply_true_false(node.right)
        
        # Unary connective
        elif node.value == self.__negation:
            node.left = self.__apply_true_false(node.left)
        # Atom
        else:
            return node

        # Negation
        if node.value == self.__negation:
            if node.left.value == '⊤':
                # Setting the modified flag to True
                self.__modified_flag = True
                node.value = '⊥'
                node.left = None
                return node
            elif node.left.value == '⊥':
                # Setting the modified flag to True
                self.__modified_flag = True
                node.value = '⊤'
                node.left = None
                return node
        # Disjunction
        elif node.value == '∨':
            if node.left.value == '⊥':
                # Setting the modified flag to True
                self.__modified_flag = True
                return node.right
            elif node.right.value == '⊥':
                # Setting the modified flag to True
                self.__modified_flag = True 
                return node.left
            elif node.left.value == '⊤':
                # Setting the modified flag to True
                self.__modified_flag = True
                return node.left
            elif node.right.value == '⊤':
                # Setting the modified flag to True
                self.__modified_flag = True
                return node.right
        # Conjunction
        elif node.value == '∧':
            if node.left.value == '⊤':
                # Setting the modified flag to True
                self.__modified_flag = True
                return node.right
            elif node.right.value == '⊤':
                # Setting the modified flag to True
                self.__modified_flag = True
                return node.left
            elif node.left.value == '⊥':
                # Setting the modified flag to True
                self.__modified_flag = True
                return node.left
            elif node.right.value == '⊥':
                # Setting the modified flag to True
                self.__modified_flag = True
                return node.right
        # Implication
        elif node.value == '→' and (node.left.value == '⊥' or node.right.value == '⊤'):
            if node.left.value == '⊥':
                # Setting the modified flag to True
                self.__modified_flag = True
                node.value = '⊤'
                node.left = None
                return node
        
        return node

    """ ###########################################################################
                                Negation functions
    """

    def __negation_laws(self, show_steps):
        # Initializing the modified flag with False
        self.__modified_flag = False
        self.root = self.__apply_double_negation(self.root)

        if show_steps == True and self.__modified_flag == True:
            print(style.GREEN("Removing double negations: ¬(¬F) ~ F") + style.RESET(""))
            self.inorder_parentheses()

        # Initializing the modified flag with False
        self.__modified_flag = False
        self.root = self.__apply_de_morgan(self.root)
        
        if show_steps == True and self.__modified_flag == True:
            print(style.GREEN("Applying De Morgan's laws: ¬(F∨G) ~ ¬F∧¬G, ¬(F∧G) ~ ¬G∨¬F") + style.RESET("")) 
            self.inorder_parentheses()

        # Initializing the modified flag with False
        self.__modified_flag = False
        self.root = self.__apply_other_negation(self.root)

        if show_steps == True and self.__modified_flag == True:
            print(style.GREEN("Applying other negations: ¬(F→G) ~ F∧(¬G), ¬(F↔G) ~ F↔(¬G)") + style.RESET(""))
            self.inorder_parentheses()

    def __apply_de_morgan(self, node):
        # Binary operator
        if node.value in self.__connectives:
            node.left = self.__apply_de_morgan(node.left)
            node.right = self.__apply_de_morgan(node.right)
        # Unary operator
        elif node.value == self.__negation:
            node.left = self.__apply_de_morgan(node.left)
        # Atom
        else:
            return node
        
        if node.value == self.__negation:
    
            if node.left.value == '∨' or node.left.value == '∧':
                # Set the modified flag to True
                self.__modified_flag = True

                # Flip the connective
                if node.left.value == '∨':
                    node.left.value = '∧'
                else:
                    node.left.value = '∨'

                # Creating nodes containing negation
                new_left = ExpressionTreeNode('¬')
                new_right = ExpressionTreeNode('¬')

                # Setting children of negations
                new_left.left = node.left.left
                new_right.left = node.left.right

                # Updating the children of the former disjunction
                node.left.left = new_left
                node.left.right = new_right

                return node.left
        
        return node

    def __apply_other_negation(self, node):
        # Binary operator
        if node.value in self.__connectives:
            node.left = self.__apply_other_negation(node.left)
            node.right = self.__apply_other_negation(node.right)
        # Unary operator
        elif node.value == self.__negation:
            node.left = self.__apply_other_negation(node.left)
        # Atom
        else:
            return node
        
        if node.value == self.__negation:
        
            if node.left.value == '→' or node.left.value == '↔':
                # Set the modified flag to True
                self.__modified_flag = True

                # Flip the connective in the case of implication
                if node.left.value == '→':
                    node.left.value = '∧'

                # Creating a new node containig negation
                new_right = ExpressionTreeNode('¬')

                # Setting child of negation
                new_right.left = node.left.right

                # Updating the child of the former implication/equivalence
                node.left.right = new_right

                return node.left
        
        return node
        
    def __apply_double_negation(self, node):
        
        # Negation
        if node.value == self.__negation:

            count = 1
            current_node = node

            # Reaching the last negation in the tree, and counting their amount
            while current_node.left.value == self.__negation:
                count += 1
                current_node = current_node.left
            
            if count > 1:
                # Set the modified flag to True
                self.__modified_flag = True

            # Recur down the tree first
            current_node.left = self.__apply_double_negation(current_node.left)

            # If there is an even amount of negations, return the child of the last negation
            if count % 2 == 0:
                return current_node.left
            # Else return the last negation in the subtree
            else:
                return current_node

        # Other binary connectives
        elif node.value in self.__connectives:
            node.left = self.__apply_double_negation(node.left)
            node.right = self.__apply_double_negation(node.right)
        # Atoms
        return node

    """ ########################################################################### """

    def inorder_traversal(self):
        if self.root != None:
            self.root.inorder()
    
    def inorder_parentheses(self):
        if self.root != None:
            print(style.CYAN(self.root.inorder_parentheses()) + style.RESET(""))

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