#include <iostream>
using namespace std;

struct Pneu {
    int largura;
    int altura;
    string aro;
    string tipo;
    double pressao;

    void imprimir(); 
    void inflar(double nova_pressao);
};



int main() {
    Pneu pneu1;
    pneu1.largura = 175;        // Largura do pneu em milimetros
    pneu1.altura = 75;              // Altura do pneu em milimetros
    pneu1.aro = "20";           // Diâmetro do aro em polegadas
    pneu1.pressao = 27.0;       // Pressão inicial do pneu em PSI
    pneu1.tipo = "asfalto";         // Tipo de pneu

    pneu1.imprimir(); 

    
    pneu1.inflar(35.0);

    cout << "Apos a inflacao:" << endl << endl;
    pneu1.imprimir(); 

    return 0;
}


void Pneu::imprimir() { 
    cout << "Detalhes do Pneu:" << endl;
    cout << "Largura: " << largura << " mm" << endl;
    cout << "Altura: " << altura << " mm" << endl;
    cout << "Diametro do Aro: " << aro << " polegadas" << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Pressão: " << pressao << " PSI" << endl;
}

void Pneu::inflar(double nova_pressao) { // Implementação do metodo inflar
    pressao = nova_pressao;
}