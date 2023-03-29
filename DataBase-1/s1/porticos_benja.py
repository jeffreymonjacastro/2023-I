import pandas as pd
porticos = pd.read_csv("Porticos.csv" , index_col= 0 , sep= ";")
df = pd.DataFrame(porticos)
meses = { 1: "ENERO" , 2 : "FEBRERO" , 3: "MARZO" , 4: "ABRIL" , 5: "MAYO",
            6: "JUNIO" , 7: "JULIO" , 8: "AGOSTO" , 9 : "SEPTIEMBRE" ,
          10: "OCTUBRE" , 11: "NOVIEMBRE" , 12: "DICIEMBRE"
        }

frec_categorias = {}
frec_meses = {}
frec_frecuencias = {}
d4 = {}
d5 = {}

for i in df.index:
    categoria = df["CATEGORIA"][i]
    if categoria in frec_categorias:
        frec_categorias[categoria] +=1
    else:
        frec_categorias[categoria] = 1

    if df["CATEGORIA"][i] == "N1":
        fecha = (df["FECHA"][i]).split(" ")
        mes = int((fecha[0].split("/"))[1])
        if mes in frec_meses:
            frec_meses[mes] += 1
        else:
            frec_meses[mes] = 1

    frequency = df["FRECUENCIA"][i]
    if frequency in frec_frecuencias:
        frec_frecuencias[frequency] += 1
    else:
        frec_frecuencias[frequency] = 1




# print(df)

#Pregunta1
# max_rep = -1
# categoria_mas_repetida = ""
# for i in frec_categorias.keys():
#     if frec_categorias[i] > max_rep:
#         categoria_mas_repetida = i
#         max_rep = frec_categorias[i]
#
# print(categoria_mas_repetida , frec_categorias[categoria_mas_repetida])


#Pregunta2
# max_rep = -1
# mes_mas_repetido = 0
# for i in frec_meses.keys():
#     if frec_meses[i] > max_rep:
#         mes_mas_repetido = i
#         max_rep = frec_meses[i]
# print(meses[mes_mas_repetido] ,  frec_meses[mes_mas_repetido])


#Pregunta 3
max_frec = max(list(frec_frecuencias.keys()))
placa = int()

for i in df.index:
    if df["FRECUENCIA"][i] == max_frec:
        placa = int(df["PLACA"][i])

print(frec_frecuencias)
print(f"Frecuencia máxima: {max_frec}, Placa del vehículo: {placa}")

#Pregunta 4