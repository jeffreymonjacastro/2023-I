import pandas as pd

df = pd.read_csv("Porticos.csv", sep=";")

print(df.head())

# Pregunta 1

# categoria = df.groupby(["CATEGORIA"]).count()
#
# print(categoria["ID"])
#
# print(max(categoria["ID"]))

# Pregunta 2
# filtro = df["CATEGORIA"] == "N1"
#
# N1 = df[filtro]
#
# N1.["FECHA"] = pd.to_datetime(N1["FECHA"])
#
# print(N1.FECHA.dt.month.value_counts())

# Pregunta 3
frec = df[["FRECUENCIA"]].value_counts()

# print(frec)

filter1 = df[df["FRECUENCIA"] == 23]
filter2 = df[df["FRECUENCIA"] == 22]

# print(filter1[["PLACA"]])


