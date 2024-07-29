def zetadieta(C, P, G):
    if 0 <= C <= 10**9 and 0 <= P <= 10**9 and 0 <= G <= 10**9:
        calorias = 0
        calorias += round(C/27+0.49) * 105 #bananas
        calorias += round(P/30+0.49) * 120 #atun
        calorias += G * 9 #aceite de oliva
        return(calorias)
    else:
        return('Los valores no son compatibles')
print(zetadieta(88, 90, 50))