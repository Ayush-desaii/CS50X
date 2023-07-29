# TODO
from cs50 import get_int
n = 0
while n > 8 or n < 1:
    n = get_int("Height: ")
for i in range(0, n):
    j = n-1
    while (j > i):
        print(" ", end="")
        j -= 1

    for k in range(0, i+1):
        print("#", end="")

    print("  ", end="")

    for l in range(0, i+1):
        print("#", end="")

    print()