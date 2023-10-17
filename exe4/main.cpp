# include <iostream>
# include "src/headerFile/utils.h"
# include "src/headerFile/menus.h"

using namespace std;

int main(){
    int opc;
    do{
        limpaTela();
        opc = menu_Motor();

        switch (opc)
        {
        case 1:
            limpaTela();
            cout << "Registrar Motor" << endl;
            pause();
            break;
        case 2:
            limpaTela();
            cout << "Listar Motor(es)" << endl;
            pause();
            break;
        case 3:
            limpaTela();
            cout << "Alterar dados do Motor" << endl;
            pause();
            break;
        case 4:
            limpaTela();
            cout << "Excluir Motor" << endl;
            pause();
            break;
        case 0:
            limpaTela();
            cout << "Voltando ao Menu Principal" << endl;
            pause();
            break;
        default:
            limpaTela();
            cout << "Opção invalida!" << endl;
            pause();
            break;
        }
    }while(opc != 0);

    return 0;
}

