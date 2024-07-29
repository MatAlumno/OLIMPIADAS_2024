#include <iostream>
#include <cmath>
using namespace std;

int zetadieta(int C, int P, int G) {
    int calorias = 0;
    calorias += round(C / 27.0 + 0.49) * 105; // Bananas
    calorias += round(P / 30.0 + 0.49) * 120; // Atún
    calorias += G * 9; // Aceite de oliva
    return calorias;
}
int main() {
    cout << zetadieta(88, 90, 50) << endl;
    return 0;
}
