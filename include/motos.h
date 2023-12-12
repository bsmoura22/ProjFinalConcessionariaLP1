#ifndef MOTOS_H
#define MOTOS_H
#include <iostream>
#include "veiculos.h"//classe "pai"

using namespace std;
using std::string;

class Motos : public Veiculos//herança
{
    protected:
        string modelo;//atributo unico da moto
        
    public:
        Motos(string mo, string chassi, string marca, double preco, int fabricacao);//construtor
        //Acesso modelo
        string getModelo();
        void setModelo(string mo);
        //Saída com a impressão da moto
        void print_Moto();
};

#endif