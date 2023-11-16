#ifndef CAMINHOES_H
#define CAMINHOES_H
#include <iostream>

#include "veiculos.h" //classe "pai"

using namespace std;

class Caminhoes : public Veiculos //herança
{
    protected:
        string tipo_de_carga; //atributo unico do caminhão
        
    public:
        Caminhoes(string carga, string marca, double preco, string chassi, int fabricacao); //construtor

        //Acesso tipo de carga
        string getTipo_Carga();
        void setTipo_Carga(string t_g);
        //Saída com a impressão do caminhao 
        void print_caminhao();
};

#endif