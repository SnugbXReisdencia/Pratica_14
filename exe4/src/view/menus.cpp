#include <iostream>
#include <vector>
#include <string>

#include "../headerFile/utils.h"
#include "../headerFile/menus.h"

using namespace std;
int menu_Motor(){
    int opc;
    do{
        vector<string> str = {"############  Menu de Motor   ############",
        " 1 = Registrar Motor",
        " 2 = Listar Motor(es)",
        " 3 = Alterar dados do Motor",
        " 4 = Excluir Motor",
        " 0 = Voltar ao Menu Principal",
        };
        opc = geraMenus(str, 5);
        if(opc < 0 || opc > 4){
            cout << "Opção invalida!" << endl;
            cout << "Por favor, escolha uma opção entre 0 e 4." << endl;
            pause();
            limpaTela();
        }
    }while(opc < 0 || opc > 4);
    return opc;
}

int menu_altera_Motor(){
    int opc;
    do{
        vector<string> str = {"############  Alterar Motor   ############",
        " 1 = Alterar Nome",
        " 2 = Alterar Fabricante",
        " 3 = Alterar Modelo",
        " 4 = Alterar Tipo",
        " 5 = Alterar Ano",
        " 6 = Alterar Potência",
        " 7 = Alterar Número de Marchas",
        " 8 = Alterar Velocidade Máxima",
        " 9 = Alterar Consumo de Combustível",
        " 0 = Voltar ao Menu Principal",
        };
        opc = geraMenus(str, 10);
        if(opc < 0 || opc > 9){
            cout << "Opção invalida!" << endl;
            cout << "Por favor, escolha uma opção entre 0 e 9." << endl;
            pause();
            limpaTela();
        }
    }while(opc < 0 || opc > 9);
    return opc;
}