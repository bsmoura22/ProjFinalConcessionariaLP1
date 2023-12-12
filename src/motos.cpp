#include "../include/motos.h"
using namespace std;
using std::string;

/*Uso de getters e setters para alterar e acessar as variaveis da classe.*/

Motos::Motos(string mo, string chassi, string marca, double preco, int fabricacao) //Construtor da moto
{
    setModelo(mo);
    setChassi(chassi);
    setMarca(marca);
    setPreco(preco);
    setFabricacao(fabricacao);
    
}

string Motos::getModelo() //acesso ao modelo (atributo unico da moto)
{
    return modelo;
}

void Motos::setModelo(string m) //edição do modelo da moto
{
    modelo = m;
}

void Motos::print_Moto() //Impressão final do modelo de cada moto
{
    cout << endl;
    cout << "MODELO: " << getModelo() << endl;
    cout << "MARCA: " << getMarca() << endl;
    cout << "PRECO: " << getPreco() << endl;
    cout << "CHASSI: " << getChassi() << endl;
    cout << "ANO DE FABRICACAO: " << getFabricacao() << endl;
}