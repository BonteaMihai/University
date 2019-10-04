from COLORS import style

class UserInterface():

    def __init__(self, controller):

        self.__controller = controller

    def __print_menu(self):
        print(style.BLUE("\n\nInsert a propositional logic formula") + style.RESET(""))
        print(style.BLUE("For the propositional connectives and other symbols use the following table:") + style.RESET(""))
        print(style.YELLOW("[ ¬ : 1 ][ ∨ : 2 ][ ∧ : 3 ][ → : 4 ][ ↔ : 5 ][ ⊤ : 6 ][ ⊥ : 7 ]") + style.RESET(""))

    def start(self):

        while True:
    
            self.__print_menu()
            
            #get user input
            user_input = input(style.GREEN(">>> ") + style.RESET(" "))
            



