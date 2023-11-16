#ifndef AUTOMOVEIS_H
#define AUTOMOVEIS_H
#include <iostream>
#include "veiculos.h" //Classe pai

using namespace std;

class Automoveis : public Veiculos //herança
{
    protected:
        string tipo_de_motor; //atributo unico do carro
        
    public:
        Automoveis(string t_m, string marca, double preco, string chassi, int fabricacao);//construtor
        //Acesso ao tipo de motor
        string getTipo_motor();
        void setTipo_motor(string t);
        //Saída com a impressão do carro
        void print_carro();
};

#endif