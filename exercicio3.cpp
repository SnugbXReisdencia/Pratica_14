#include <iostream>
#include <cmath>

using namespace std;

struct Ponto {
    double x;
    double y;
};

double calcularDistancia(Ponto ponto1, Ponto ponto2) {
    double distancia = sqrt(pow(ponto2.x - ponto1.x, 2) + pow(ponto2.y - ponto1.y, 2));
    return distancia;
}

int main() {
    Ponto ponto1 = {1.0, 2.0};
    Ponto ponto2 = {4.0, 6.0};

    double distanciaEntrePontos = calcularDistancia(ponto1, ponto2);

    cout << "Distancia entre os pontos: " << distanciaEntrePontos << endl;

    return 0;
}
