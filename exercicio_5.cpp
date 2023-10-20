#include <string>
#include <vector>

using namespace std;

struct Proprietario{
    private:
        string nome;
        string cnh;
        string telefone;
        string email;
        char sexo;
        // vector<Carro> carros;
    public:
        Proprietario();
        Proprietario(string, string, string, string, char);
        string getNome();
        string getCnh();
        string getTelefone();
        string getEmail();
        char getSexo();
        // void adquirirCarro(Carro carro);
};

Proprietario::Proprietario(){

}

Proprietario::Proprietario(string nome, string cnh, string telefone, string email, char sexo){
    this->nome = nome;
    this->cnh = cnh;
    this->telefone = telefone;
    this->email = email;
    this->sexo = sexo;
}

string Proprietario::getNome(){
    return this->nome;
}

string Proprietario::getCnh(){
    return this->cnh;
}

string Proprietario::getTelefone(){
    return this->telefone;
}

string Proprietario::getEmail(){
    return this->email;
}

char Proprietario::getSexo(){
    return this->sexo;
}

/*
void Proprietario::adquirirCarro(Carro carro){
    this->Carros.push_back(carro);
}
*/
