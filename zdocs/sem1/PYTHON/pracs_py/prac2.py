#   Write a program to accept a number 'n' and
#   A: Check if 'n' is prime

def is_prime(n):    #   Define function to check if n is prime

    if n <= 1:  # 2 is the smallest prime number
        return False
    else:
        for i in range(2, int(n/2) + 1):   #    Run a for loop from 2 to square root of n + 1(as range does not include the last number)
            if n % i == 0:  #    Check if n is divisible by any number in the range
                return False   #   If n is divisible by any number in the range, return False
                break   #   Break the loop to prevent further checks which may lead to multiple outputs
        else:
            return True   #   If the loop completes then condition was not met and n was not divisible by any number in range. Then n is prime

#   B: Generate all prime numbers till 'n'


def gen_primes(n):  #  Define function to generate all prime numbers till n
    for a in range(2 , n + 1):    #    Run a for loop to iterate all numbers from 2 to n
        if is_prime(a) == True:    #    If number is prime, function returns True
            print(a, end=" ")    #    If the number is prime, print it
    print()    #    Print a new line after printing all primes

#   C: Generate first 'n' prime numbers


def first_n_primes(n):  #   Define function to generate first n prime numbers
    count = 0   #    Create a counter to count number of primes found
    i = 2   #    'i' is used to check prime number starting from 2 and is incremented until we find 'n' primes
    while count < n:
        if is_prime(i) == True:
            print(i, end=" ")
            count += 1
        i += 1
    print()

#    CALL THE FUNCTIONS
n = int(input("Enter a number 'n': "))  #   Accept user input for n
print()
if is_prime(n):  #   Call function to check if n is prime
    print(f"{n} is a prime number")
    print()
elif is_prime(n) == False:
    print(f"{n} is not a prime number")
    print()
print("All prime numbers till", n, "are: ")
gen_primes(n)  #   Call function to generate all prime numbers till n
print()
print("First", n, "prime numbers are: ")
first_n_primes(n)  #   Call function to generate first n prime numbers
print()