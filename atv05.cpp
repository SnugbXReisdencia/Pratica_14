# include <iostream>

using namespace std;

struct Motor {
    string tipo;
    double potencia;
    double consumo_combustivel; // consumo em litros por quilometro


    void ligar() {
       cout << "Ligando motor" << endl;
       cout << " Motor ligado" << endl;
    }

    void desligar() {
   cout << "Desligando motor" << endl;
    }

    double calcular_consumo(double distancia) {
        return distancia * consumo_combustivel;
    }
};


// int main() {
//     Motor motor;
//     motor.tipo = "Motor a Gasolina";
//     motor.potencia = 150.0;
//     motor.consumo_combustivel = 0.08;  
//     motor.ligar(); 

//     double distancia = 100.0; //  distaacia em quilometros
//     double consumo = motor.calcular_consumo(distancia);
//    cout << "Consumo de combustivel para " << distancia << " km: " << consumo << " litros" << endl;

//    motor.desligar();
    
//     return 0;
// }



