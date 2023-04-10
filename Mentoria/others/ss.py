import numpy
#
# n = int(input("Hola Mundo"))
#
# print(n)

#------------------------------

entero = -10
decimal = 10.5
decimal2 = 3.14159
caracter = 'a'
cadena = "Hola mundo"
boleano = True
entero_largo = 300000
ent_larg_pos = 1000000

#------------------------------

# m = int(input())
#
# if 3 <= m <= 10:
#     m += 1
# elif m <= 20:
#     m -= 1
# else:
#     print("xd", end=" ")

#-------------------------------

def fibonacci(n):
    if n <= 1:
        return 1
    else:
        return fibonacci(n-1) + fibonacci(n-2)

print(fibonacci(5))
# 8

#-------------

n = 0
for i in range(10):
    n += i*2

print(n)


def deletrar(s):
    new_s = ""
    for i in range(len(s)-1, -1, -1):
        new_s += s[i]

    return new_s

print(deletrar("hola"))


