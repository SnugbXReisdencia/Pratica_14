# include <iostream>
# include <limits>
# include <cstring>
# include <vector>
# include <iomanip>
#include <regex>

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

struct Motor
{
private:
    string nome;
    string fabricante;
    string modelo;
    string tipo;
    bool ligado;
    int ano;
    int potencia;
    int numMarchas;
    double velocidadeMaxima;
    double consumoCombustivel;
public:
    Motor(string nome, string fabricante, string modelo, string tipo, int ano, int potencia, int numMarchas, double velocidadeMaxima, double consumoCombustivel);
    Motor();

    string getNome();
    string getFabricante();
    string getModelo();
    string getTipo();
    int getAno();
    int getPotencia();
    int getNumMarchas();
    double getVelocidadeMaxima();
    double getConsumoCombustivel();

    void setNome(string nome);
    void setFabricante(string fabricante);
    void setModelo(string modelo);
    void setTipo(string tipo);
    void setAno(int ano);
    void setPotencia(int potencia);
    void setNumMarchas(int numMarchas);
    void setVelocidadeMaxima(double velocidadeMaxima);
    void setConsumoCombustivel(double consumoCombustivel);

    double calcularConsumoCombustivel(double distancia);
    void ligar();
    void desligar();

    string toString();
};

Motor geraMotor(vector<Motor>);

void listarMotor(vector<Motor>);

int buca_motor(vector<Motor> motores);

void alterarMotor(int, int  , vector<Motor>& );

void excluirMotor(vector<Motor> &);

string tipo_motor();

int menu_Motor();
int menu_altera_Motor();



void pause();
void limpaTela();


int main(){
    vector<Motor> motores;
    int opc, aux_int;
    char sn;
    double aux_double;
    Carro car1;

    registrar_manutencao(car1);
    informacoes_manuntencao(car1);
    
    do{
        limpaTela();
        opc = menu_Motor();
        switch(opc){
            case 1:
                do{
                    limpaTela();
                    motores.push_back(geraMotor(vector<Motor>()));
                    cout << "Motor adicionado com sucesso!" << endl;
                    cout << "Deseja adicionar outro motor? (s/n) ";
                    cin >> sn;
                    limpaTela();
                }while(sn != 'n' && sn != 'N');
                break;
            case 2:
                limpaTela();
                if(int(motores.size()) > 0){
                    listarMotor(motores);
                }else
                    cout << "Nenhum motor registrado!" << endl;
                pause();
                break;
            case 3:
                limpaTela();
                if(int(motores.size()) < 1){
                    cout << "Nenhum motor registrado!" << endl;
                    pause();
                    break;
                }
                do{
                    aux_int = buca_motor(motores);
                    if(aux_int == -1){
                        cout << "Motor inexistente!" << endl;
                        pause();
                        break;
                    }
                    limpaTela();
                    aux_int = menu_altera_Motor();
                    alterarMotor(aux_int , aux_int, motores);
                    pause();
                    cout << "Deseja alterar outro motor? (s/n) ";
                    cin >> sn;
                }while(sn != 'n' && sn != 'N');	
                break;
            case 4:
                limpaTela();
                if(int(motores.size()) < 1){
                    cout << "Nenhum motor registrado!" << endl;
                    pause();
                    break;
                }
                excluirMotor(motores);
                pause();
                break;
            case 5:
                limpaTela();
                if(int(motores.size()) < 1){
                    cout << "Nenhum motor registrado!" << endl;
                    pause();
                    break;
                }
                aux_int = buca_motor(motores);
                if(aux_int == -1){
                    cout << "Motor inexistente!" << endl;
                    pause();
                    break;
                }
                cout << "Digite a distância a ser percorrida: ";
                cin >> aux_double;
                cout << "Consumo de combustivel para essa distância e: " << fixed << setprecision(2) << motores[aux_int].calcularConsumoCombustivel(aux_double) << endl;
                pause();
                break;
            case 6:
                limpaTela();
                if(int(motores.size()) < 1){
                    cout << "Nenhum motor registrado!" << endl;
                }
                aux_int = buca_motor(motores);
                if(aux_int == -1){
                    cout << "Motor inexistente!" << endl;
                    pause();
                    break;
                }
                motores[aux_int].ligar();
                pause();
                break;
            case 7:
                limpaTela();
                if(int(motores.size()) < 1){
                    cout << "Nenhum motor registrado!" << endl;
                }
                aux_int = buca_motor(motores);
                if(aux_int == -1){
                    cout << "Motor inexistente!" << endl;
                    pause();
                    break;
                }
                motores[aux_int].desligar();
                pause();
                break;
            case 0:
                limpaTela();
                cout << "Volte sempre!" << endl;
                pause();
                break;
            default:
                limpaTela();
                cout << "Opcao invalida!" << endl;
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

int menu_Motor(){
    int opc;
    cout << "############  Menu de Motor   ############\n1 = Registrar Motor\n2 = Listar Motor(es)\n3 = Alterar dados do Motor\n4 = Excluir Motor\n5 = Calcular Consumo de um Motor\n6 = Ligar Motor\n7 = Desligar Motor\n0 = Voltar ao Menu Principal";
    cout << "\nEscolha uma opção: ";
    cin >> opc;
    return opc;
}

int menu_altera_Motor(){
    int opc;
    cout << "############  Alterar Motor   ############\n1 = Alterar Nome\n2 = Alterar Fabricante\n3 = Alterar Modelo\n4 = Alterar Tipo\n5 = Alterar Ano\n6 = Alterar Potência\n7 = Alterar Número de Marchas\n8 = Alterar Velocidade Máxima\n9 = Alterar Consumo de Combustível\n0 = Voltar ao Menu Principal";
    cout << "\nEscolha uma opção: ";
    cin >> opc;
    return opc;
}

Motor::Motor(string nome, string fabricante, string modelo, string tipo, int ano, int potencia, int numMarchas, double velocidadeMaxima, double consumoCombustivel){
    this->nome = nome;
    this->fabricante = fabricante;
    this->modelo = modelo;
    this->tipo = tipo;
    this->ano = ano;
    this->potencia = potencia;
    this->numMarchas = numMarchas;
    this->velocidadeMaxima = velocidadeMaxima;
    this->consumoCombustivel = consumoCombustivel;
    this->ligado = false;
}

Motor::Motor(){
    this->nome = "";
    this->fabricante = "";
    this->modelo = "";
    this->tipo = "";
    this->ano = 0;
    this->potencia = 0;
    this->numMarchas = 0;
    this->velocidadeMaxima = 0;
    this->consumoCombustivel = 0;
    this->ligado = false;
}

string Motor::getNome(){
    return this->nome;
}

string Motor::getFabricante(){
    return this->fabricante;
}

string Motor::getModelo(){
    return this->modelo;
}

string Motor::getTipo(){
    return this->tipo;
}

int Motor::getAno(){
    return this->ano;
}

int Motor::getPotencia(){
    return this->potencia;
}

int Motor::getNumMarchas(){
    return this->numMarchas;
}

double Motor::getVelocidadeMaxima(){
    return this->velocidadeMaxima;
}

double Motor::getConsumoCombustivel(){
    return this->consumoCombustivel;
}

void Motor::setNome(string nome){
    this->nome = nome;
}

void Motor::setFabricante(string fabricante){
    this->fabricante = fabricante;
}

void Motor::setModelo(string modelo){
    this->modelo = modelo;
}

void Motor::setTipo(string tipo){
    this->tipo = tipo;
}

void Motor::setAno(int ano){
    this->ano = ano;
}

void Motor::setPotencia(int potencia){
    this->potencia = potencia;
}

void Motor::setNumMarchas(int numMarchas){
    this->numMarchas = numMarchas;
}

void Motor::setVelocidadeMaxima(double velocidadeMaxima){
    this->velocidadeMaxima = velocidadeMaxima;
}

void Motor::setConsumoCombustivel(double consumoCombustivel){
    this->consumoCombustivel = consumoCombustivel;
}

double Motor::calcularConsumoCombustivel(double distancia){
    return distancia * this->consumoCombustivel;
}

void Motor::ligar(){
    if(this->ligado){
        cout << "Motor já esta ligado!";
    }else{
        this->ligado = true;
        cout << "Motor ligado!" << endl;
    }
}

void Motor::desligar(){
    if(!this->ligado){
        cout << "Motor já esta desligado!";
    }else{
        this->ligado = false;
        cout << "Motor desligado!" << endl;
    }
}

string Motor::toString(){
    string str = "";
    str += "Nome: " + this->nome + "\n";
    str += "Fabricante: " + this->fabricante + "\n";
    str += "Modelo: " + this->modelo + "\n";
    str += "Tipo: " + this->tipo + "\n";
    str += "Ano: " + to_string(this->ano) + "\n";
    str += "Potência: " + to_string(this->potencia) + "\n";
    str += "Número de marchas: " + to_string(this->numMarchas) + "\n";
    str += "Velocidade máxima: " + to_string(this->velocidadeMaxima) + "\n";
    str += "Consumo de combustivel: " + to_string(this->consumoCombustivel) + "\n";

    return str;
}

string tipo_motor(){
    string tipo;
    int opcao = 0;
    do{
        if (opcao != 0)
            cout << "Opcao invalida!" << endl;
        cout << "Qual o tipo do motor?" << endl;
        cout << "1 = Diesel" << endl;
        cout << "2 = Gasolina" << endl;
        cout << "3 = Eletrico" << endl;
        cin >> opcao;
    }while(opcao < 1 || opcao > 3);
    if(opcao == 1)
        tipo = "Diesel";
    else if(opcao == 2)
        tipo = "Gasolina";
    else
        tipo = "Eletrico";
    return tipo;
}

Motor geraMotor(vector<Motor> motores){
    string nome, fabricante, modelo, tipo;
    int ano, potencia, numMarchas;
    double velocidadeMaxima, consumoCombustivel;
    bool existe = false;
    cout << "\n############  Registrar Motor  ############" << endl;
    do{
        cout << "Nome: ";
        cin >> nome;
        for(Motor m : motores){
            if(m.getNome() == nome){
                existe = true;
            }
        }
        if(existe){
            cout << "Nome já existe!" << endl;
            existe = false;
            nome = "";
        }
    }while(nome == "");

    cout << "Fabricante: ";
    cin >> fabricante;
    cout << "Modelo: ";
    cin >> modelo;
    tipo = tipo_motor();
    cout << "Ano: ";
    cin >> ano;
    cout << "Potência: ";
    cin >> potencia;
    cout << "Numero de marchas: ";
    cin >> numMarchas;
    cout << "Velocidade máxima: ";
    cin >> velocidadeMaxima;
    cout << "Consumo de combustível: ";
    cin >> consumoCombustivel;

    return Motor(nome, fabricante, modelo, tipo, ano, potencia, numMarchas, velocidadeMaxima, consumoCombustivel);
}

void listarMotor(vector<Motor> motores){
    auto it = motores.begin();
    cout << "\n############  Lista de Motor(es)  ############" << endl;
    for(Motor m : motores){
        cout << "Motor " << it - motores.begin() + 1 << "ª :" << endl;
        cout << m.toString() << endl;
        cout << "------------------------------------------------------------" << endl;
        it++;
    }
}

int buca_motor(vector<Motor> motores){
    int opcao = -1;
    listarMotor(motores);
    cout << "Digite o número do motor desejado: ";
    cin >> opcao;
    if (opcao > 0 && opcao <= int(motores.size())){
        return opcao - 1;
    }
    return opcao;
}

void alterarMotor(int posi,int opc , vector<Motor>& motores){
     string nome, fabricante, modelo, tipo;
     int ano, potencia, numMarchas;
     double velocidadeMaxima, consumoCombustivel;
     bool existe = false;
     posi--;
     switch (opc)
     {
     case 1:
        do{
            cout << "Digite o novo nome: ";
            cin >> nome;
            for(Motor m : motores){
                if(m.getNome() == nome){
                    existe = true;
                }
            }
            if(existe){
                cout << "Nome já existe!" << endl;
                existe = false;
                nome = "";
            }
        }while(nome == "");
        motores[posi].setNome(nome);
        cout << "Nome alterado com sucesso!" << endl;
        break;
    case 2:
        cout << "Digite o novo fabricante: ";
        cin >> fabricante;
        motores[posi].setFabricante(fabricante);
        cout << "Fabricante alterado com sucesso!" << endl;
        break;
    case 3:
        cout << "Digite o novo modelo: ";
        cin >> modelo;
        motores[posi].setModelo(modelo);
        cout << "Modelo alterado com sucesso!" << endl;
        break;
    case 4:
        cout << "Digite o novo tipo: ";
        tipo = tipo_motor();
        motores[posi].setTipo(tipo);
        cout << "Tipo alterado com sucesso!" << endl;
        break;
    case 5:
        cout << "Digite o novo ano: ";
        cin >> ano;
        motores[posi].setAno(ano);
        cout << "Ano alterado com sucesso!" << endl;
        break;
    case 6:
        cout << "Digite a nova potência: ";
        cin >> potencia;
        motores[posi].setPotencia(potencia);
        cout << "Potência alterada com sucesso!" << endl;
        break;
    case 7:
        cout << "Digite o novo número de marchas: ";
        cin >> numMarchas;
        motores[posi].setNumMarchas(numMarchas);
        cout << "Número de marchas alterado com sucesso!" << endl;
        break;
    case 8:
        cout << "Digite a nova velocidade máxima: ";
        cin >> velocidadeMaxima;
        motores[posi].setVelocidadeMaxima(velocidadeMaxima);
        cout << "Velocidade máxima alterada com sucesso!" << endl;
        break;
    case 9:
        cout << "Digite o novo consumo de combustivel: ";
        cin >> consumoCombustivel;
        motores[posi].setConsumoCombustivel(consumoCombustivel);
        cout << "Consumo de combustivel alterado com sucesso!" << endl;
        break;
    case 0:
        break;
     default:
        break;
     }
}

void excluirMotor(vector<Motor> &motores){
    int motorBuscado = buca_motor(motores);
    auto it = motores.begin();
    for(Motor m : motores){
        if(m.getNome() == motores[motorBuscado].getNome()){
            cout << "Motor `" << motores[motorBuscado].getNome() << "` excluído!" << endl;
            motores.erase(it);
            return;
        }
        it++;
    }
    cout << "Motor `" << motores[motorBuscado].getNome() << "` não encontrado!" << endl;
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
            cout << "Digite a data(dd/mm/yyyy) da manutencao:" << endl;
            cin >> data_manutencao;
            if(!valida_data(data_manutencao)){
                cout << "Data invalida, por favor digite outra data" << endl;
            }else{
                manutencao.data_ = data_manutencao;
            }

        }while(!valida_data(data_manutencao));

        cout << "Digite a descricao da manutencao:" << endl;
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