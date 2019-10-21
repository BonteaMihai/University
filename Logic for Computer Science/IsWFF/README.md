# Checking whether a string is a well formed propositional formula

## Problem statement:

Write a program that takes as argument a string and decides whether the string represents a well formed propositional formula.

## Theory basis:

**Well-formed Formulae**

*REMARK:* Propositional variables can be used to denote **atoms**, i.e simple propositions, not involving propositional connectives, but
also to stand in or rename propositional formulae. The particular use for propositional variables will be specified each time.

**Definition** (Well-formed formulae of propositional logic). The *well-formed formulae* (formulae, WFF's) of propositional logic are
defined recursively as follows: 

1. If A is an **atom**, then A is a formula.

2. If P is a formula, then the negation of P is also a formula.

3. If P and Q are formulae, then the conjuction, disjunction, implication and equivalence of P and Q are also formulae.

4. All formulae are generated following the above rules.

**All of the above taken from DR. Adrian Craciun's course slides.**

http://staff.fmi.uvt.ro/~adrian.craciun/lectures/logic/pdf/logicNotes.pdf

## Method of solving:

The program can be solved in **O(n)**, and more specifically, in just one traversal of the given string.
From the recursive nature of the definition we can observe that a WFF is either two other WFFs with a propositional connective inbetween,
or the negation of another WFF. The most basic example of a WFF is an atom.

Thus, for simplicity(without sacrificing efficiency) the program will be built around a recursive function which decides the validity of
an expression by checking the validity of the expressions which comprise it. This stops when we reach the base case of atom, or when we
spot violations of the syntax, such as parentheses opened but not closed, formulas with no connective between them, or two connectives one
after the other.

In addition to simply deciding whether the string represents a well formed propositional formula, when that is not the case, the program is
capable of also stating what the problem is(see the picture below).

![Logica1](https://user-images.githubusercontent.com/51800513/67225175-69653900-f43b-11e9-937f-04f351204405.png)

## Update

-added User Interface

![Logica2](https://user-images.githubusercontent.com/51800513/67230702-6c195b80-f446-11e9-865c-e38cd066ade5.png)
