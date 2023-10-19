# include <iostream>
# include <limits>
# include <cstring>
# include <cmath>

using namespace std;

struct Calculadora {
    double x;
    double y;

    double static calcula_Potencia(double, double);
    double static calcula_Soma(double , double);
};

void pause();
void limpaTela();


int main(){
    
    int opc;
    do{
        limpaTela();

        

        
        pause();
    }while(opc != 0);
    return 0;
}


void pause()
{
    cin.ignore();
    cout << "\nPressione a tecla Enter para continuar...\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void limpaTela()
{
    cin.clear();

    // Verifica se a variável de ambiente WINDIR está definida (ambiente Windows)
    const char *windir = getenv("WINDIR");

    if (windir != nullptr && strlen(windir) > 0)
    {
        // Se estiver definida, estamos no Windows, então use "cls"
        system("cls");
    }
    else
    {
        // Caso contrário, estamos em um ambiente Unix/Linux, use "clear"
        system("clear");
    }
}

double Calculadora::calcula_Potencia(double valor, double p){
    return pow(valor, p);
}

double Calculadora::calcula_Soma(double valor, double valor2){
    return valor + valor2;
}
