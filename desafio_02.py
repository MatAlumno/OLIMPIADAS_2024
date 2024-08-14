# CALCULA CUANTO CURA EN UNA SOLA POS
def calcularCura(position, fila, col, vidaInicial, vidaActual):
    mejor_cura = 0
    for i in range(len(fila)):     #i = indice
        posF = (fila[i], col[i])   #posF = posicion de luchador
        actualVida = vidaActual[i]
        maxVida = vidaInicial[i]
        #verifica si pos no excede la diferencia de xy mas de 2
        if abs(position[0] - posF[0]) + abs(position[1] - posF[1]) <= 2:
            cura = min(maxVida - actualVida, 10)   # cuanto puede curar al luchador
            mejor_cura = max(mejor_cura, cura)     # actualiza la mejor cura 
    return mejor_cura

def sanar(fila, col, vidaInicial, vidaActual, d, mapa): # fila Y      col X
    visitados = [[fila[0], col[0], 0]] 
    positions =  [[fila[0], col[0]]]
    direcciones = [(1, 0), (-1, 0), (0, 1), (0, -1)] 
    
    #CONSIGUE TODAS LAS POSICIONES POSIBLES DE KHRIS
    for pos in visitados:
        f, c, count = pos[0], pos[1], pos[2]  #pos actual en visitados
        
        for df, dc in direcciones:    # df y dc definen si suma o resta en las axis
            nf, nc = f + df, c + dc   # nf y nc son x y de posiciones adyacentes
            
            #comprueba si la pos es posible de visitar
            if 0 <= nf < len(mapa) and 0 <= nc < len(mapa[0]) and mapa[nf][nc] == '.' and [nf, nc] not in [v[:2] for v in visitados]:
                if count + 1 <= d:  # Verifica si no se excede los mov
                    visitados.append([nf, nc, count + 1]) 
                    positions.append([nf, nc])
    mejorCura = 0
    for pos in positions:
        cura = calcularCura(pos, fila, col, vidaInicial, vidaActual)
        if cura > mejorCura:
            mejorCura = cura
    return(mejorCura)
    
mapa = [['.','.','X','X','.','.'],
        ['.','.','.','X','X','X'],
        ['.','.','.','X','.','.'],
        ['.','.','.','.','.','.']]    
print(sanar([2,3,0,2,0,3], [2,3,5,0,4,1], [13,40,40,50,40,6], [10,34,1,48,32,1], 4, mapa))
print(sanar([0,1],[0,1],[13,40],[13,40],5,[['.','.'],['.','.']]))