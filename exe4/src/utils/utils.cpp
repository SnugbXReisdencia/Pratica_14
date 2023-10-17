# include <iostream>
# include <limits>
# include <cstring>
# include "../headerFile/utils.h"

using namespace std;

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

int geraMenus(vector<string> str, int qtd){
    cin.clear();
    int tam = str.size();
    int opc;
    for(string s : str){
        cout << s << endl;
    }
    cout << "Escolha uma opção: ";
    cin >> opc;
    return opc;
}
