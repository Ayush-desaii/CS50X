# TODO
from cs50 import get_string
n = get_string("text: ")

a = 0
for i in n:
    if (i <= "z" and i >= "a") or (i <= "Z" and i >= "A"):
        a += 1

w = 1
for i in n:
    if (i == " "):
        w += 1

s = 0
for i in n:
    if (i == ".") or (i == "!") or (i == "?"):
        s += 1

L = (100 * a)/w
S = (100 * s)/w
g = round((0.0588 * L) - (0.296 * S) - 15.8)

if (g < 1):
    print("Before Grade 1")

elif (g > 16):
    print("Grade 16+")

else:
    print("Grade ",g)