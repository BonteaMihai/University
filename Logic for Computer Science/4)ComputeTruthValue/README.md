# Return value of proposition under given interpretation

## Problem statement:

Write a program that parses a string of symbols and builds the corresponding abstract syntax (tree and/or list). The program will return the
complete abstract tree/list if the string is a proposition.

Write a program that takes the representation of a formula in abstract syntax, an interpretation 
and returns the value under that interpretation of the corresponding proposition.

## Theory basis:

**Definition** (True proposition). A propositional formula B is said to be *true under an interpretation* if it is evaluated to T
in the interpretation. Otherwise B is said to be *false*.

*REMARK* (Number of possible interpretations). If there are n distinct atoms in a formula, then there will be 2^n distinct
interpretations for the formula.

**Validity, Satisfiability, Inconsistency** 

**Definition** (Propositional Tautologies). The formula B is *valid* in propositional logic(or B is a propositional tautology)
iff the proposition is true under all possible interpretations. The formula is *invalid* iff it is not valid.

**Definition** (Satisfiability). A propositional formula B is said to be *satisfiable* in propositional logic iff there exists some
interpretation for which the formula is evaluated to true.

A propositional formula is said *unsatisfiable* (*inconsistent*) iff it is false under all truth valuations(all interpretations).

**All of the above taken from DR. Adrian Craciun's lecture notes.**

http://staff.fmi.uvt.ro/~adrian.craciun/lectures/logic/pdf/logicNotes.pdf

## Method of solving:

In order to build the **abstract syntax tree**, the given string is converted into postfix form, then the tree is built using a stack. The string is iterated, 
and if the current element in the string is an operand, it is pushed onto the stack. If it is an operator, operands are popped from the stack, set as children,
and then the root of the new formed tree is pushed onto the stack. A distinction has to be made between unary operators and binary operators, as in the case of
negation, only one operator should be popped from the stack.

**Evaluating the truth value** of a propositional formula is done in a (recursive) divide and conquer way, where the truth value of a WFF is decided by
applying the function associated to the operator(connective) on the truth values of its children(or child in the case of negation). When the leaf nodes
are reached, the value of the respective atoms are returned from a dictionary given by the user.

- program shows all steps in the evaluating process:

![Untitled](https://user-images.githubusercontent.com/51800513/67838186-646a4e80-faf9-11e9-9e55-06b3e3ee6ecb.png)

## Update

- Now can check whether a given propositional formula is tautology/satisfiable/inconsistent

![a](https://user-images.githubusercontent.com/51800513/67840901-9383be80-faff-11e9-8c21-209851fccbd5.png)
