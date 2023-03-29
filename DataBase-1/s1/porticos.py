import pandas as pd

database = pd.read_csv("Porticos.csv", sep=";")

d = {}

categorias = list(database["CATEGORIA"])

for i in categorias:
    d[i] = categorias.count(i)

print(d)

# M1 = database[database["CATEGORIA"] == "M1"]
#
# print(M1[["CATEGORIA"]])
