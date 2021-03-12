import sys
import networkx as nx
import matplotlib.pyplot as plt

arg = sys.argv
arq_leitura = arg[1]
k = int(arg[2])
arq_saida = arg[3]

with open(arq_leitura, "r") as f:
    leitura=f.read().splitlines()

pontos = {}

for linha in leitura:
    linha = linha.split(',')
    nome = linha[0]
    coords = linha[1:]
    coords_float = []
    for coord in coords:
        coord = float(coord)
        coords_float.append(coord)

    pontos[nome] = coords_float

print(pontos, sep='\n')

G = nx.Graph()

for ponto in pontos:
    print(ponto, pontos[ponto])
    G.add_node(ponto, pos=pontos[ponto])

nx.draw(G, nx.get_node_attributes(G, 'pos'), with_labels=True, node_size=230)
plt.show()
