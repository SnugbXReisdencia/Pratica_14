#include <string>
#include <iostream>

using namespace std;
void fatorial(int valores []);
float converteGraus(int valor);

int main(){
    int valores[] = {3, 4, 5};
    float resultado, grau;

    fatorial(valores);

    for(int i = 0; i < 3; i++) {
        cout <<"Digite o valor do grau Celsius" << endl;
        cin >> grau;
        resultado = converteGraus(grau);
        cout <<"Converte Grau "<< resultado << endl;
    }

    return 0;
}

// questão 01
void fatorial(int valores []){
    for(int j = 0; j<3; j++){
        int soma =valores[j];
        for(int i = valores[j] -1; i > 0 ; i--){
                soma = soma * i;
        }
        cout <<"Resultado do fatorial de "<< valores[j] <<": " << soma << endl;
    }
}

// questão 02
float converteGraus(int valor){

    return(1.8 * valor) + 32;
}

