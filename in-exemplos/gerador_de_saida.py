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
    ponto.append("".join(random.choice(letras) for i in range(10)))
    for i in range(M):
        ponto.append(random.random() * 10)
    pontos.append(ponto)

f = open(saida, "w")

for ponto in pontos:
    f.write(ponto[0])
    for i in range(M):
        f.write(",")
        f.write(str(ponto[i+1]))
    f.write("\n")

# printing punctuation
