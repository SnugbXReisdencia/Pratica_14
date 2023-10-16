#include <iostream>
#include <regex>
#include <vector>


using namespace std;

struct Manutencao {
    string data_;
    string descricao;
    double custo;

};

struct Carro {
    string marca;
    string modelo;
    int ano;
    string cor;
    int numero_portas;
    double quilometragem;
    vector <Manutencao> manutencao;

};

    
void dirigir(double distancia);


void registrar_manutencao(Carro& car);

bool valida_data(string dta_);

void informacoes_manuntencao(Carro& car);

int main() {

    Carro car1;
    
    registrar_manutencao(car1);

    informacoes_manuntencao(car1);
    return 0;
}


void dirigir(double distancia, Carro& car) {
    car.quilometragem += distancia;
}



void registrar_manutencao(Carro& car) {
    string data_manutencao;
    double custo;
    char resposta;
    Manutencao manutencao;

    do{

        do{
            cout << "Digite a data(dd/mm/yyyy) da manutenção:" << endl;
            cin >> data_manutencao;
            if(!valida_data(data_manutencao)){
                cout << "Data invalida, por favor digite outra data" << endl;
            }else{
                manutencao.data_ = data_manutencao;
            }

        }while(!valida_data(data_manutencao));

        cout << "Digite a descrição da manutencao:" << endl;
        cin.ignore();
        getline(cin, manutencao.descricao);

        do{
            cout << "Digite o custo da manutencao:" << endl;
            cin >> custo;

            if(custo <= 0){
                cout << "valor invalido, digite o valor de custo novamente." << endl;
            }else{
                manutencao.custo = custo;
            }

        }while(custo <= 0);

        car.manutencao.push_back(manutencao);  

        cout <<"Deseja registrar outra manuntecao(S/N)?" << endl;
        cin >> resposta;
    }while(resposta == 'S' || resposta == 's');
   
}

bool valida_data(string dta_){
    int dia, mes, ano;

    regex datePattern(R"(\d{2}/\d{2}/\d{4})");

    if(!regex_match(dta_, datePattern)){
        return false;
    }else{

        dia = atol(dta_.substr(0,2).c_str());
        mes = atoi(dta_.substr(3,2).c_str());
        ano = atoi(dta_.substr(6,10).c_str());

        if((dia >= 1 && dia <= 30 ) && (mes == 4||mes == 6 || mes ==9 || mes ==7 || mes ==11)){

        }
        else if((dia >= 1 && dia <= 31 ) && (mes == 1||mes == 3 || mes ==5 || mes ==7 || mes ==8 || mes ==10 || mes ==12)){

        }
        else if((dia >= 1 && dia <= 28 ) && (mes == 2)){

        }
        else if(dia >= 29 && mes == 2 && ((ano % 400 == 0 || ano % 4 == 0) && ano % 100 !=0)){

        }else{
            return false;

        }
        return true;

    }
}

void informacoes_manuntencao(Carro& car) {
    int tam = car.manutencao.size();

    for(int i=0; i< tam; i++){
        cout << "----------Manutencao-----------"<<
        "\nData: " << car.manutencao[i].data_ <<
        "\nDescricao: " << car.manutencao[i].descricao <<
        "\nCusto: " << car.manutencao[i].custo << endl;
        }
}