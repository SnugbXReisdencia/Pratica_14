#include <iostream>
using namespace std;

double recebe_temperatura();
double converte(double);

int main(){
    for(int i = 0; i < 5; i++){
        double temperatura = recebe_temperatura();
        cout<<temperatura<<"C° em F° = "<<converte(temperatura)<<endl;
        cout<<endl;
    }
    return 0;
}

double recebe_temperatura(){
    double temperatura;
    cout<<"Digite a temperatuda em Celcius: ";
    cin>>temperatura;

    return temperatura;
}

double converte(double temperatura){
    return temperatura * 1.8 + 32;
}