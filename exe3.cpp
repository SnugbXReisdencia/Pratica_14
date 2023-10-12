# include <iostream>
# include <limits>
# include <cstring>
# include <cmath>
# include <iomanip>

using namespace std;

struct Ponto
{
    float x;
    float y;

    float distancia(Ponto);
};

void pause();
void limpaTela();

int main(){
    
    char sn;
    Ponto p, p2;

    do{
        limpaTela();

        cout << "Informe as Informações do primeiro Ponto: \n";
        cout << "Valor de X = ";
        cin >> p.x;
        cout << "Valor de y = ";
        cin >> p.y;

        cout << "Informe as Informações do segundo Ponto: \n";
        cout << "Valor de X = ";
        cin >> p2.x;
        cout << "Valor de y = ";
        cin >> p2.y;

        cout << "\nA distancia entre o Ponto 1 e o Ponto 2 é: "<< fixed << setprecision(1) << p.distancia(p2);
        

        cout << "\n\nDeseja continuar (S/N)? ";
        cin >> sn;

    }while(sn != 'N' && sn != 'n');

    pause();
    return 0;
}

float Ponto::distancia(Ponto p){
    return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
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