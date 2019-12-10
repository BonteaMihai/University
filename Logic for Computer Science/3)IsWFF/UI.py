from COLORS import style
from main import WFPropositionalFormula
from InfixToPostfix import Conversion
import os, sys

if sys.platform.lower() == "win32":
    os.system('color')

class UserInterface():

    def __init__(self):
        self.__filename = "example.txt"
        self.__options = {"1":self.__load_file, "2": self.__test_string, "3": self.__exp_tree}

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

    def __load_file(self):
        try:
            with open(self.__filename, "r") as file:
                first_line = file.readline()
                nr_formulas = int(first_line)

                for i in range(nr_formulas):
                    line = file.readline()
                    line = self.__convert_str(line)
                    print(style.GREEN("For line " + str(i + 1)) + style.RESET(""))
                    print(line)
                    form = WFPropositionalFormula(line)
                    form.is_valid()
                
        except IOError:
            pass
    
    def __test_string(self):
        print(style.YELLOW("[ ¬ : 1 ][ ∨ : 2 ][ ∧ : 3 ][ → : 4 ][ ↔ : 5 ]") + style.RESET(""))
        expr = input(style.BLUE("Insert your expression(with the help of the table above: ") + style.RESET(""))
        expr = self.__convert_str(expr)
        print(expr)
        form = WFPropositionalFormula(expr)
        form.is_valid()

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
        print(style.BLUE("1) Test for the strings in file.") + style.RESET(""))
        print(style.BLUE("2) Insert a string from keyboard and test whether it is a WFF.") + style.RESET(""))
        print(style.MAGENTA("4) Store a formula as an expression tree, prints inorder traversal (Has to be WFF!)") + style.RESET(""))
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


