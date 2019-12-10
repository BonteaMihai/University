# The Resolution Method in Propositional Logic

## Problem statement:

Decide the satisfiability of a given formula given in "clause form".

## Theory basis:

K is a *propositional clause set* iff K is a finite set of propositional clauses.
C is a *propositional clause* iff C is a finite set of propositional literals.
L is a *propositional literal* is an atom, or the negation of an atom.

From any formula, we can obtain, in a natural way, its clause set form, by transforming it into CNF, and reading
the clauses directly from the disjuncts.


**All of the above taken from DR. Adrian Craciun's lecture notes.**

http://staff.fmi.uvt.ro/~adrian.craciun/lectures/logic/pdf/logicNotes.pdf

## Method of solving:

Resolution works by the following algorithm:

while exists C such that
    C is a propositional resolvent of two clauses in K' and C does not belong to K' already
do
    if C = {} then answer: "Not satisfiable"
    else K' := K' U {C}

answer: "Satisfiable"

![Res1](https://user-images.githubusercontent.com/51800513/70396237-c3cc5000-1a0f-11ea-9c04-9b0fba17914a.png)

## Updates

-added extra functionality: Davis-Putnam method(DP)

![DP1](https://user-images.githubusercontent.com/51800513/70443462-de9ad500-1aa0-11ea-8f75-c4b9beb02857.png)

-added extra functionality: Davis-Putnam Logemann Loveland method(DPLL)
