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
    double static calcula_divisao(double , double);
};

int menu();

void pause();
void limpaTela();

int main(){
    
    int opc;
    Calculadora c;
    do{
        limpaTela();
        opc = menu();
        switch (opc)
        {
        case 1:
            limpaTela();
            cout << "************* Potencia *************" << endl;
            cout << "Insira o valor da base: ";
            cin >> c.x;
            cout << "Insira o valor do expoente: ";
            cin >> c.y;
            cout << "O resultado é: " << Calculadora::calcula_Potencia(c.x, c.y) << endl;
            pause();
            break;
        case 2:
            limpaTela();
            cout << "************* Soma *************" << endl;
            cout << "Insira o valor 1: ";
            cin >> c.x;
            cout << "Insira o valor 2: ";
            cin >> c.y;
            cout << "O resultado é: " << Calculadora::calcula_Soma(c.x, c.y) << endl;
            pause();
            break;
        case 3:
            limpaTela();
            cout << "************* Divisao *************" << endl;
            cout << "Insira o valor 1: ";
            cin >> c.x;
            cout << "Insira o valor 2: ";
            cin >> c.y;
            cout << "O resultado é: " << Calculadora::calcula_divisao(c.x, c.y) << endl;
            pause();
            break;
        case 0:
            limpaTela();
            cout << "Saindo..." << endl;
            pause();
            break;
        default:
            limpaTela();
            cout << "Opção invalida!" << endl;
            cout << "Por favor, escolha uma opção entre 1 e 2." << endl;
            pause();
        }        
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

double Calculadora::calcula_divisao(double valor_x, double valor_y){

    if(valor_x == 0.0){
        return 0.0;
    }else if(valor_y == 0.0){
        return -1;

    }

    return valor_x / valor_y;
}

int menu(){
    int op;
    cout << "############  Calculadora   ############\n";
    cout << "1 - Potencia\n";
    cout << "2 - Soma\n";
    cout << "3 - Divisao\n";
    cout << "0 - Sair\n";
    cout << "Escolha uma opcao: ";
    cin >> op;
    return op;
}