#include "../include/automoveis.h"
using namespace std;
using std::string;
Automoveis::Automoveis(string t_m, string chassi, string marca, int preco, int fabricacao) //construtor do novo carro
{
    setTipo_motor(t_m);
    setMarca(marca);
    setPreco(preco);
    setChassi(chassi);
    setFabricacao(fabricacao);
}

string Automoveis::getTipo_motor()//acesso ao tipo de motor (atributo unico do carro)
{
    return tipo_de_motor;
}

void Automoveis::setTipo_motor(string t) //edição do tipo de motor recebendo o usuario
{
    tipo_de_motor = t;
}

void Automoveis::print_carro() //Saída do carro (Impressão)
{
    cout << endl;
    cout << "TIPO DE MOTOR: " << getTipo_motor() << endl;
    cout << "MARCA: " << getMarca() << endl;
    cout << "PRECO: " << getPreco() << endl;
    cout << "CHASSI: " << getChassi() << endl;
    cout << "ANO DE FABRICACAO: " << getFabricacao() << endl;
}