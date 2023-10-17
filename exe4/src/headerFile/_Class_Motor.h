#ifndef _CLASS_MOTOR_H
#define _CLASS_MOTOR_H

using namespace std;

class Motor
{
private:
    string nome;
    string fabricante;
    string modelo;
    string tipo;
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

Motor geraMotor();

void listarMotor(vector<Motor>);

void alterarMotor(vector<Motor> &);

void excluirMotor(vector<Motor> &);



#endif