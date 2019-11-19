# Convert proposition to NNF

## Problem statement:

[...]

## Theory basis:

We extend the language with two symbols, ⊥, ⊤:

* ⊥ denote formulae that are always false (unsatisfiable, inconsistent)

* ⊤ denote formulae that are always true (valid), i.e. for all truth valuations

**Negation Normal Form**

**Definition** (Literal). 
A *literal* is an atom or the negation of an atom. Atoms are called positive literals, negations of atoms are called negative literals.

**Definition** (Negation Normal Form).
A formula F is is in *negation normal form* (NNF) iff:

* F is ⊤ or F is ⊥

* F is constructed from literals, using only the binary connectives '∨' and '∧'

**Transformation to NNF**

*REMARK.* Any propositional logic formula can be transformed into an equivalent formula in NNF

* use the reduction laws(given in the catalog of equivalent formulae) to eliminate '↔' and '→'

* repeatedly use the double negation and De Morgan's laws to eliminate '¬¬'s and '¬(...)'s

* at each of the steps above it is useful to perform simplifications of ⊤ and ⊥(using the laws of true and false, annihilation, idempocy )

**All of the above taken from DR. Adrian Craciun's lecture notes.**

http://staff.fmi.uvt.ro/~adrian.craciun/lectures/logic/pdf/logicNotes.pdf

## Method of solving:

In order to build the **abstract syntax tree**, the given string is converted into postfix form, then the tree is built using a stack. The string is iterated, 
and if the current element in the string is an operand, it is pushed onto the stack. If it is an operator, operands are popped from the stack, set as children,
and then the root of the new formed tree is pushed onto the stack. A distinction has to be made between unary operators and binary operators, as in the case of
negation, only one operator should be popped from the stack.

