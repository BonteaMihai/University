from COLORS import style
import copy

class ClauseSet:

    def __init__(self):
        self.__index = 1
        self.__clauses = []
        self.__literal_count = {}

    def add_clause(self, literal_list):
        
        # Updating the literal count
        for literal in literal_list:
            if literal in self.__literal_count:
                self.__literal_count[literal] += 1
            else:
                self.__literal_count[literal] = 1
        
        # Creating a new clause out of the literals
        clause = Clause(literal_list, self.__index)
        self.__index += 1

        self.__clauses.append(clause)

    def apply_resolution(self):
        
        modified = True

        while modified == True:
            modified = False
            for literal in self.__literal_count.keys():
                if -literal in self.__literal_count.keys():
                    for index_i in range(0, len(self.__clauses) - 1):
                        for index_j in range(index_i + 1, len(self.__clauses)):
                            if self.__clauses[index_i].contains_literal(literal) and self.__clauses[index_j].contains_literal(-literal):
                                new_literal_list = copy.deepcopy(self.__clauses[index_i].literals)
                                new_literal_list.remove(literal)

                                aux_literal_list = copy.deepcopy(self.__clauses[index_j].literals)
                                aux_literal_list.remove(-literal)

                                for lit in aux_literal_list:
                                    if lit not in new_literal_list:
                                        new_literal_list.append(lit)
                            
                                new_literal_list = sorted(new_literal_list)
                                clause = Clause(new_literal_list, self.__index)
                                if clause not in self.__clauses:
                                    self.add_clause(new_literal_list)

                                    modified = True
                                    print(style.GREEN("from (" + str(self.__clauses[index_i].index) + ')(' +  str(self.__clauses[index_j].index) + ')') + style.RESET(""), end=" ")
                                    print(style.CYAN("we have " + str(clause)) + style.RESET(""))

                                    # We obtained the empty clause!
                                    if len(clause) == 0:
                                        print(style.RED("We obtained {}, therefore Not Satisfiable") + style.RESET(""))
                                        return False
        
        print(style.GREEN("Nothing else to be done, therefore it is Satisfiable"))
        return True        
                    
    def apply_DP(self):
        pass

    def apply_DPLL(self):
        pass


class Clause:

    def __init__(self, literal_list, index):
        self.index = index
        self.literals = copy.deepcopy(literal_list)
        self.times_modified = 0

    def complemented(self):
        pass
    
    def copy(self):
        pass
    
    def contains_literal(self, literal):
        return literal in self.literals
    
    def remove_literal(self, literal):
        self.times_modified += 1
        self.literals.remove(literal)

    def __len__(self):
        return len(self.literals)
    
    def __eq__(self, rhs):
        return sorted(self.literals) == sorted(rhs.literals)

    def __str__(self):
        string = '(' + str(self.index) + ')'
        string += '{'
        if len(self) != 0:
            for i in range(0, len(self.literals) - 1):
                string += str(self.literals[i]) + ', '
            string += str(self.literals[-1])
        string += '}'

        return string