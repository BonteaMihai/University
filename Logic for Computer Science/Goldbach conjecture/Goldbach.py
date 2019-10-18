number = int(input("Insert the number until which to check if the Goldbach conjecture holds: "))

is_prime = [True] * number
is_prime[0] = False
is_prime[1] = False

primes_list = []

def sieve():
    """
    Generates all the prime numbers until the given number by using
    the sieve of Eratosthenes
    """

    for i in range(number + 1):
        if is_prime[i]:
            primes_list.append(i)
            for j in range(i + i, number + 1, i):
                is_prime[j] = False

sieve()

def binary_search(x):
    """
    Searches the element x in the primes list
    """

    Left = 0
    Right = len(primes_list)

    while Left <= Right:
        Mid = (Left + Right) // 2

        if primes_list[Mid] == x:
            return True

        elif primes_list[Mid] < x:
            Left = Mid + 1
        else:
            Right = Mid - 1
    
    return False


# For each number in the given range, check if it can be written as the sum of two primes
for num in range(4, number + 1, 2):
    respects_property = False

    # Check for every prime if (num - range) exists in the prime numbers list
    for prime in primes_list:
        # If the current prime is greater than the difference between the current number and itself
        # break, as we only need to check this property for half the list
        if prime > (num - prime):
            break
        
        # Found the result, prind and exit
        if binary_search(num - prime) == True:
            respects_property = True
            print("{(" + str(prime) + " + " + str(num - prime) + ") == " + str(num) + "}", end = " " )
            break
    
    if respects_property == False:
        print("\n\tThe goldbach conjecture does not hold for the number " + str(num))
        break



