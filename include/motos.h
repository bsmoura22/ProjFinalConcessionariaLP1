#ifndef MOTO_H
#define MOTO_H
#include <iostream>
#include "veiculos.h"//classe "pai"

using namespace std;

class Moto : public Veiculo//herança
{
    protected:
        string modelo;//atributo unico da moto
        
    public:
        Moto(string mo, string marca, double preco, double chassi, int fabricacao);//construtor
        //Acesso modelo
        string getModelo();
        void setModelo(string mo);
        //Saída com a impressão da moto
        void print_Moto();
};

#endif