from COLORS import style
from main import Controller

import os, sys

if sys.platform.lower() == "win32":
    os.system('color')

class UserInterface():
    
    def __init__(self, controller):
        self.__filename = "example.txt"
        self.__controller = controller
        self.__options = {"1" : self.__infix_to_prefix, "2" : self.__evaluate_expression}

    
    def __infix_to_prefix(self):
        with open(self.__filename, "r") as file:
            first_line = file.readline()
            first_line = first_line.strip()
            first_line = first_line.replace(" ", "")
            print(self.__controller.infix_to_prefix(first_line))
    
    def __evaluate_expression(self):
        with open(self.__filename, "r") as file:
            first_line = file.readline()
            first_line = first_line.strip()
            first_line = first_line.replace(" ", "")
            
            variable_dict = {}

            second_line = file.readline()
            second_line = second_line.strip()
            second_line = int(second_line)

            for i in range(second_line):
                i_th_line = file.readline()
                var, val = i_th_line.strip().split()
                variable_dict[var] = int(val)

            print(variable_dict)
            print(self.__controller.evaluate_expression(first_line, variable_dict))

    def __print_menu(self):
        print(style.BLUE("\n\nChoose one of the following options: ") + style.RESET(""))
        print(style.CYAN("1) Convert an infix expression to its prefix equivalent.") + style.RESET(""))
        print(style.CYAN("2) Evaluate an expression using polish notation.") + style.RESET(""))
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
            
cont = Controller()
ui = UserInterface(cont)
ui.start()