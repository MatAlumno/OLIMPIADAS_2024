"""
n = cant de personajes
r = cant filas,c = cant columnas
cada valor de snar es arreglo epcepto d y map
"""
map = [['.','.','X','X','.','.'],
       ['.','.','.','X','X','X'],
       ['.','.','.','X','.','.'],
       ['.','.','.','.','.','.']]

def sanar(fila,col,vidaInicial, vidaActual, d, mapa): #fila Y      col X
    cola = []
    visitados = [[fila[0],col[0]]]
    for pos in visitados:
        f, c = pos[0], pos[1]
        
        if f+1 < len(map) and c < len(fila) and map[f+1][c] == '.' and [f+1, c] not in visitados:
            cola.append([f+1, c])

        if f-1 >= 0 and map[f-1][c] == '.' and [f-1,c] not in visitados:
            cola.append([f-1,c])
            
        if c+1 < len(fila) and map[f][c+1] == '.' and [f,c+1] not in visitados:
            cola.append([f,c+1])
            
        if c-1 >= 0 and map[f][c-1] == '.' and [f,c-1] not in visitados:
            cola.append([f,c-1])
        if cola != []:
            visitados.append(cola[0])
            cola.remove(cola[0])
    print(visitados)
sanar([2,3,0,2,0,3],[2,3,5,0,4,1],[13,40,40,50,40,6],[10,34,1,48,32,1],4,map)