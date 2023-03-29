import pandas as pd

# Pregunta 1
database = pd.read_csv("Porticos.csv", sep=";")

categoria = database.groupby(["CATEGORIA"]).count()

print(categoria["ID"])

print(max(categoria["ID"]))


