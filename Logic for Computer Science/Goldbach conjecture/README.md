# Goldbach conjecture

This program tests whether the Goldbach conjecture holds for all even numbers in the interval {4, ... , nr} where nr is the number given as input.

## Method described

Firstly, all the prime numbers smaller than the number given are generated with the **sieve of Eratosthenes**, the most efficient method of generating all the primes
in a given range.

Then we go through all the even elements in {4, ... , nr}. For each such element, we go through the list of primes generated previously, and **binary search** the 
difference between the current number and the current prime.

![Untitled](https://user-images.githubusercontent.com/51800513/67110441-6f5cdf00-f1db-11e9-87fb-b9062952f5cd.png)
