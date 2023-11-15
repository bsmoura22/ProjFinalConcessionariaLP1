#include "motos.h"

Moto::Moto(string mo, string marca, double preco, double chassi, int fabricacao) //Construtor da moto
{
    setModelo(mo);
    setChassi(chassi);
    setMarca(marca);
    setPreco(preco);
    setFabricacao(fabricacao);
    
}

string Moto::getModelo() //acesso ao modelo (atributo unico da moto)
{
    return modelo;
}

void Moto::setModelo(string m) //edição do modelo da moto
{
    modelo = m;
}

void Moto::print_Moto() 
{
    cout << endl;
    cout << "MODELO: " << getModelo() << endl;
    cout << "MARCA: " << getMarca() << endl;
    cout << "PRECO: " << getPreco() << endl;
    cout << "CHASSI: " << getChassi() << endl;
    cout << "ANO DE FABRICACAO: " << getFabricacao() << endl;
}