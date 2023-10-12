#include <iostream>
using namespace std;

int faltorial_de(int);

int main(){

    long long int valores[3];
    cout<<"Digite 3 valores inteiros maiores que 0: "<<endl;
    for(int i = 0; i < 3; i++){
        cout<<"Valor "<<i+1<<": ";
        cin>>valores[i];

        if(valores[i] < 0){
            do{
                cout<<"O valor "<<i+1<<" precisa ser maior que 0, tente novamente: ";
                cin>>valores[i];
            } while(valores[i] < 0);
        }
    }

    cout<<endl;
    for(long long int valor : valores) cout<<"O fatorial de "<<valor<<" = "<<faltorial_de(valor)<<endl;

    return 0;
}

int faltorial_de(int n){
    if(n == 0 || n == 1) return 1;
    else return n * faltorial_de(n - 1);
}