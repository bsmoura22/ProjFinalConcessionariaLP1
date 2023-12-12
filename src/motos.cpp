#include "../include/motos.h"

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

void Motos::print_Moto() 
{
    cout << endl;
    cout << "MODELO: " << getModelo() << endl;
    cout << "MARCA: " << getMarca() << endl;
    cout << "PRECO: " << getPreco() << endl;
    cout << "CHASSI: " << getChassi() << endl;
    cout << "ANO DE FABRICACAO: " << getFabricacao() << endl;
}