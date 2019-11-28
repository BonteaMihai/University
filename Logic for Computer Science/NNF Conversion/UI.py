from COLORS import style
from main import WFPropositionalFormula
from InfixToPostfix import Conversion
import os, sys

if sys.platform.lower() == "win32":
    os.system('color')

class UserInterface():

    def __init__(self):
        self.__filename = "example.txt"
        self.__options = {"1" : self.__convert_to_NNF, "2" : self.__convert_to_DNF, "3" : self.__convert_to_CNF}

    def __convert_str(self, user_input):
        """
        Replaces [1, 2, 3, 4, 5] with the respective connectives for the given string
        Removes whitespaces and newline characters that are left from reading from file
        Returns the list with the modifications
        """
        user_input = user_input.replace('!', '¬')
        user_input = user_input.replace('|', '∨')
        user_input = user_input.replace('&', '∧')
        user_input = user_input.replace('>', '→')
        user_input = user_input.replace('~', '↔')
        user_input = user_input.replace('1', '⊤')
        user_input = user_input.replace('0', '⊥')

        user_input = user_input.replace(' ', '')
        user_input = user_input.replace('\n', '')
        user_input = user_input.strip()

        return user_input

    def __truth_value_ui(self):
        """
        Reads a string from file. If it is a WFF it also reads an interpretation, and then
        computes the truth value of the proposition with respect to the given interpretation
        """
        try:
            with open(self.__filename, "r") as file:
                expr = file.readline()
                expr = self.__convert_str(expr)
                print(expr)

                form = WFPropositionalFormula(expr)
                if not form.is_WFF():
                    return

                form.store_as_exp_tree()

                second_line = file.readline()
                nr_atoms = int(second_line)
                value_dict = {}

                for i in range(nr_atoms):
                    line = file.readline()
                    line = line.split()

                    value = line[0]
                    truth_val = int(line[1])

                    if truth_val == 1:
                        value_dict[value] = True
                    else:
                        value_dict[value] = False

                form.compute_truth_value(value_dict)

        except IOError:
            pass
    
    def __proposition_type(self):
        """
        Reads a string from file. If it is a WFF, it tests whether it is a tautology, satisfiable,
        or inconsistent.
        """
        try:
            with open(self.__filename, "r") as file:
                expr = file.readline()
        
        except IOError:
            pass
        
        expr = self.__convert_str(expr)
        print(expr)

        form = WFPropositionalFormula(expr)
        if not form.is_WFF():
            return

        form.store_as_exp_tree()

        atoms = []

        for ch in expr:
            if ch.isalpha() == True and ch not in atoms:
                atoms.append(ch)
                
        form.proposition_type(atoms)
    
    def __exp_tree(self):
        """
        Prompts the user to enter a string representing a WFF, then stores the proposition as an
        expression tree
        """
        print(style.YELLOW("[ ¬ : 1 ][ ∨ : 2 ][ ∧ : 3 ][ → : 4 ][ ↔ : 5 ][ ⊤ : 6 ][ ⊥ : 7 ]") + style.RESET(""))
        expr = input(style.BLUE("Insert your expression(with the help of the table above: ") + style.RESET(""))
        expr = self.__convert_str(expr)
        print(expr)
        form = WFPropositionalFormula(expr)
        form.is_WFF()
        form.store_as_exp_tree()
        form.print_exp_tree()
    
    def __convert_to_NNF(self):
        print(style.YELLOW("[ ¬ : ! ][ ∨ : | ][ ∧ : & ][ → : > ][ ↔ : ~ ][ ⊤ : 1 ][ ⊥ : 0 ]") + style.RESET(""))
        expr = input(style.BLUE("Insert your expression(with the help of the table above: ") + style.RESET(""))
        expr = self.__convert_str(expr)
        print(expr)
        form = WFPropositionalFormula(expr)
        if form.is_WFF() == True:
            form.store_as_exp_tree()
            form.convert_to_NNF()
            form.print_exp_tree()
    
    def __convert_to_DNF(self):
        print(style.YELLOW("[ ¬ : ! ][ ∨ : | ][ ∧ : & ][ → : > ][ ↔ : ~ ][ ⊤ : 1 ][ ⊥ : 0 ]") + style.RESET(""))
        expr = input(style.BLUE("Insert your expression(with the help of the table above: ") + style.RESET(""))
        expr = self.__convert_str(expr)
        print(expr)
        form = WFPropositionalFormula(expr)
        if form.is_WFF() == True:
            form.store_as_exp_tree()
            form.convert_to_NNF()
            form.convert_to_DNF()
            form.print_exp_tree()

    def __convert_to_CNF(self):
        print(style.YELLOW("[ ¬ : ! ][ ∨ : | ][ ∧ : & ][ → : > ][ ↔ : ~ ][ ⊤ : 1 ][ ⊥ : 0 ]") + style.RESET(""))
        expr = input(style.BLUE("Insert your expression(with the help of the table above: ") + style.RESET(""))
        expr = self.__convert_str(expr)
        print(expr)
        form = WFPropositionalFormula(expr)
        if form.is_WFF() == True:
            form.store_as_exp_tree()
            form.convert_to_NNF()
            form.convert_to_CNF()
            form.print_exp_tree()

    def __print_menu(self):
        print(style.BLUE("\n\nChoose one of the following options: ") + style.RESET(""))
        print(style.MAGENTA("1) Convert propositional formula to Negation Normal Form(NNF)") + style.RESET(""))
        print(style.MAGENTA("2) Convert propositional formula to Disjunctive Normal Form(DNF)") + style.RESET(""))
        print(style.MAGENTA("3) Convert propositional formula to Conjuctive Normal Form(CNF)") + style.RESET(""))
        print(style.RED("Or insert 'exit' to quit") + style.RESET(""))

    def start(self):

        while True:
            self.__print_menu()

            # Get user input    
            cmd = input((style.GREEN(">>> ") + style.RESET(" ")))
            
            if cmd == "exit":
                return 

            elif cmd in self.__options:
                self.__options[cmd]()
            

ui = UserInterface()
ui.start()


