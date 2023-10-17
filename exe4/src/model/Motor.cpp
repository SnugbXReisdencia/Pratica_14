#include <iostream>
#include <vector>
#include <string>

#include "../headerFile/_Class_Motor.h"

using namespace std;

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
    cout << "Motor ligado!" << endl;
}

void Motor::desligar(){
    cout << "Motor desligado!" << endl;
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

Motor geraMotor(){
    string nome, fabricante, modelo, tipo;
    int ano, potencia, numMarchas;
    double velocidadeMaxima, consumoCombustivel;

    cout << "\n############  Registrar Motor  ############" << endl;
    cout << "Nome: ";
    cin >> nome;
    cout << "Fabricante: ";
    cin >> fabricante;
    cout << "Modelo: ";
    cin >> modelo;
    cout << "Tipo: ";
    cin >> tipo;
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
    cout << "\n############  Listar Motor(es)  ############" << endl;
    for(Motor m : motores){
        cout << "Motor " << it - motores.begin() + 1 << "ª :" << endl;
        cout << m.toString() << endl;
        cout << "------------------------------------------------------------" << endl;
    }
}