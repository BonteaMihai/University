# Return value of proposition under given interpretation(Relaxed Syntax)

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

In practice, we allow a relaxed syntax, in that some of the parentheses are dropped. However, formulae should be nonambiguous, even
in this relaxed syntax. The way to avoid ambiguity is to define *priorities* for *propositional connectives*:

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

Since there are no parentheses in postfix form, in order to allow the user to input propositions in relaxed syntax too, all that should be changed is the
infix to postfix converting, in particular to define priorities for the operators. However, compared to the last project where the WFF check was done by an
additional recursive function, now the validating is done while converting to postfix(which may let some errors pass through)

![Untitled](https://user-images.githubusercontent.com/51800513/67931175-08bbc600-fbca-11e9-9e5e-eed0832b9d86.png)
