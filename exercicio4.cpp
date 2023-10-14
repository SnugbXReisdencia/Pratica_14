#include <iostream>
#include <cmath>

using namespace std;

struct Calculadora {
    double x;
    double y;
};

void pedir_valor(Calculadora& calculadora);
double calcula_divisao(Calculadora& calculadora);

int main() {
    Calculadora calculadora;

    double resultado_divisao = calcula_divisao(calculadora);

    if(resultado_divisao == -1){
        cout << "Não é possível dividir por zero" << endl;
    }else{
        cout << resultado_divisao << endl;
    }

    return 0;
}


void pedir_valor(Calculadora& calculadora){
    cout << "Digite o valor de X: " << endl;
    cin >> calculadora.x;

    cout << "Digite o valor de Y: " << endl;
    cin >> calculadora.y;


}

double calcula_divisao(Calculadora& calculadora){

    pedir_valor(calculadora);
    if(calculadora.x == 0.0){
        return 0.0;
    }else if(calculadora.y == 0.0){
        return -1;

    }
    double divisao = calculadora.x / calculadora.y;

    return divisao;
}