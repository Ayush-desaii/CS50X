# TODO
from cs50 import get_float
n = -1.0
while n < 0.0:
    n = get_float("change owed: ")

# change doller into cents
cents = n * 100

# count qurters
q = (cents - (cents % 25))/25
cents = cents - (q * 25)

d = (cents - (cents % 10))/10
cents = cents - (d * 10)

ni = (cents - (cents % 5))/5
cents = cents - (ni * 5)

p = cents

a = int(q + d + ni + p)

print(a)