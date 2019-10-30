from COLORS import style
from main import WFPropositionalFormula
from InfixToPostfix import Conversion
import os, sys

if sys.platform.lower() == "win32":
    os.system('color')

class UserInterface():

    def __init__(self):
        self.__filename = "example.txt"
        self.__options = {"1" : self.__truth_value_ui, "2" : self.__exp_tree, "3" : self.__proposition_type}

    def __convert_str(self, user_input):
        """
        Replaces [1, 2, 3, 4, 5] with the respective connectives for the given string
        Returns the list with the modifications
        """
        user_input = user_input.replace('1', '¬')
        user_input = user_input.replace('2', '∨')
        user_input = user_input.replace('3', '∧')
        user_input = user_input.replace('4', '→')
        user_input = user_input.replace('5', '↔')
        user_input = user_input.replace(' ', '')
        user_input = user_input.replace('\n', '')
        user_input = user_input.strip()


        return user_input

    def __truth_value_ui(self):
        try:
            with open(self.__filename, "r") as file:
                expr = file.readline()
                expr = self.__convert_str(expr)
                print(expr)

                form = WFPropositionalFormula(expr)
                if not form.is_valid():
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
        try:
            with open(self.__filename, "r") as file:
                expr = file.readline()
        
        except IOError:
            pass
        
        expr = self.__convert_str(expr)
        print(expr)

        form = WFPropositionalFormula(expr)
        if not form.is_valid():
            return

        form.store_as_exp_tree()

        atoms = []

        for ch in expr:
            if ch.isalpha() == True and ch not in atoms:
                atoms.append(ch)
                
        form.proposition_type(atoms)
    
    def __exp_tree(self):
        print(style.YELLOW("[ ¬ : 1 ][ ∨ : 2 ][ ∧ : 3 ][ → : 4 ][ ↔ : 5 ]") + style.RESET(""))
        expr = input(style.BLUE("Insert your expression(with the help of the table above: ") + style.RESET(""))
        expr = self.__convert_str(expr)
        print(expr)
        form = WFPropositionalFormula(expr)
        form.store_as_exp_tree()
        form.print_exp_tree()

    def __print_menu(self):
        print(style.BLUE("\n\nChoose one of the following options: ") + style.RESET(""))
        print(style.BLUE("1) Compute the truth value of the proposition from file.") + style.RESET(""))
        print(style.MAGENTA("2) Store a formula as an expression tree, prints inorder traversal (Has to be WFF!)") + style.RESET(""))
        print(style.CYAN("3) Tells whether formula from file is valid/satisfiable/inconsistent"))
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


