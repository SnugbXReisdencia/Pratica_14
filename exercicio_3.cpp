#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

struct Ponto{
    int x, y;
};

void calcula(Ponto, Ponto);

int main(){
    Ponto p1, p2;

    cout<<"Digite as coordenadas de dois pontos do plano cartesiano:"<<endl;
    cout<<"Ponto 1:"<<endl;
    cout<<"X: ";
    cin>>p1.x;
    cout<<"Y: ";
    cin>>p1.y;
    cout<<"Ponto 2:"<<endl;
    cout<<"X: ";
    cin>>p2.x;
    cout<<"Y: ";
    cin>>p2.y;
    calcula(p1, p2);

    return 0;
}

void calcula(Ponto p1, Ponto p2){
    double distancia = sqrt(pow(p1.y - p1.x, 2) + pow(p2.y - p2.x, 2));

    cout<<"A distancia entre os pontos ("<<p1.x<<", "<<p1.y<<") e ("<<p2.x<<", "<<p2.y<<") = "<<fixed<<setprecision(2)<<distancia<<endl;
}