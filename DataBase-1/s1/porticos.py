import pandas as pd

df = pd.read_csv("Porticos.csv", sep=";")
#
# # Pregunta 1
#
# categoria = df.groupby(["CATEGORIA"]).count()
#
# print(categoria["ID"])
#
# print(max(categoria["ID"]))

# La categoria con mayor cantidad de vehículos es N1


# Pregunta 2
# filtro = df["CATEGORIA"] == "N1"
#
# N1 = df[filtro]
#
# N1["FECHA"] = pd.to_datetime(N1["FECHA"])
#
# print(N1.FECHA.dt.month.value_counts())

# Noviembre


# Pregunta 3

frec = df[["FRECUENCIA"]].value_counts()

print(frec)

print()

filter1 = df[df["FRECUENCIA"] == 23]
filter2 = df[df["FRECUENCIA"] == 22]

print(filter1[["PLACA"]])
print(filter2[["PLACA"]])

# Max cantidad de veces que pasó por el pórtico = 23


# Pregunta 4
#
# N3 = df[(df["CATEGORIA"] == "N3") & (df["ALERTA"] == 2111)]
#
# N3["FECHA"] = pd.to_datetime(N3["FECHA"])
#
# print(N3.FECHA.dt.month.value_counts())

# Noviembre


# Pregunta 5

# alertas = df[df[""]]

# print(df.ALERTA.value_counts())