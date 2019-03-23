#!/usr/bin/env python3

import sys
from math import sqrt

def isPrime( num ):
    if (num >2 and num % 2 == 0):
        print(num, "is divisible by two.")
        sys.exit()
    if (num > 3 and num % 3 ==0):
        print(num, "is divisible by three.")
        sys.exit()
    root = int(sqrt(num))
    for i in range(5, root, 6):
        if num % i == 0:
            print(number,"is divisible by", i)
            sys.exit()
        if num % (i+2) == 0:
            print(number,"is divisible by", i+2)
            sys.exit()
    print(num, "is prime")

try:
    number = int(sys.argv[1])
except IndexError:
    number = int(input("Please enter a number: "))
except ValueError:
    number = int(input("Please enter a number: "))

isPrime(number)
sys.exit()
