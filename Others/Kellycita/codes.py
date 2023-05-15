# Validar n = 1 - 9
# Condición diferente (OR)
# n = int(input("Filas: "))
#
# while n < 1 or n > 9:
#     n = int(input("Filas: "))

# Condición es igual (AND)

def cuadrado_num():
    while True:
        n = int(input("Filas: "))

        if 1 <= n <= 9:
            break

    for i in range(n):
        m = n
        for j in range(n):
            if i + j >= n-1:
                print(m, end="")
                m -= 1
            else:
                print(0, end="")
        print()


def tabla_mult():
    while True:
        n = int(input("Numero desde 1 a 9: "))

        if 1 <= n <= 9:
            break

    if n % 2 == 0:
        for i in range(2, n+1, 2):
            for j in range(1, 11):
                print(f"{i} x {j} = {i*j}")
            print()
    else:
        for i in range(1, n+1, 2):
            for j in range(1, 11):
                print(f"{i} x {j} = {i * j}")
            print()


n = int(input("N: "))

for i in range(4):
    for j in range(n):
        print(" "*(n-j-1) + "*"*(j+1))

    print()




