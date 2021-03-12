import string
import random
import sys

args = sys.argv
N = int(args[1])
M = int(args[2])
saida = args[3]

pontos = []
letras = string.hexdigits

for i in range(N):
    ponto = []
    ponto.append("".join(random.choice(letras) for i in range(random.randint(1, 31))))

    tem_repetido = True
    while tem_repetido:
        tem_repetido = False
        coordenadas = []

        for i in range(M):
            coordenadas.append(random.random() * 10)
        
        for i, ponto_obs in enumerate(pontos):
            if i == 0: 
                continue

            iguais = 0
            for coord in coordenadas:
                tem_igual = all(elemento == coord for elemento in ponto_obs)
                
                if tem_igual:
                    iguais += 1
             
            if iguais == len(coordenadas):
                tem_repetido = True
            else:
                tem_igual = all(elemento == ponto[0] for elemento in ponto_obs)
  
        if tem_repetido:
            continue
        else:
            break    
    
    ponto.append(coordenadas)
    pontos.append(ponto)

f = open(saida, "w")
for ponto in pontos:
    f.write(ponto[0])
    for coord in ponto[1]:
        f.write(",")
        f.write(str(coord))
    f.write("\n")

# printing punctuation
