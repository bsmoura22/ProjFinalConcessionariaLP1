#ifndef CONCESSIONARIA_H
#define CONCESSIONARIA_H
#include <iostream>
#include <string>
#include <algorithm>
#include "veiculos.h"
#include "automoveis.h"
#include "motos.h"
#include "caminhoes.h"

using namespace std;

class Concessionaria
{
    protected:
        int estoque;
        string nome;
        string CNPJ;
        double valor_carros;
        double valor_caminhoes;
        double valor_motos;

        vector<Automoveis> v_auto;
        vector<Caminhoes> v_cam;
        vector<Motos> v_motos;
    
    public:
        //CONSTRUTOR DA CLASSE
        Concessionaria(string n, string c, int e);

        //ACESSO E EDIÇÃO AO VETOR DE AUTOMOVEIS
        vector<Automoveis> &getAutomoveis();
        void setAutomoveis(Automoveis automoveis);        

        //ACESSO E EDIÇÃO AO VETOR DE CAMINHOES
        vector<Caminhoes> &getCaminhoes();
        void setCaminhoes(Caminhoes caminhoes); 

        //ACESSO E EDIÇÃO AO VETOR DE MOTO
        vector<Motos> &getMotos();
        void setMotos(Motos motos);   

        //ACESSO E EDIÇÃO DE NOME DA CONCESSIONARIA
        string getNome();
        void setNome(string n);

        //ACESSO E EDIÇÃO DE CNPJ DA CONCESSIONARIA
        string getCnpj();
        void setCnpj(string c);

        //ACESSO E EDIÇÃO DO ESTOQUE DA CONCESSIONARIA
        int getEstoque();
        void setEstoque(int e);

        //RETORNA O INDICE QUE ESTÁ CADA VEICULO
        int indexCar(string chassi);
        int indexTruck(string chassi);
        int indexMoto(string chassi);

        //PESQUISA VEICULOS NO VETOR
        bool search_vehicle(string chassi);

        //REMOVE VEICULO DO VETOR
        bool remove_vehicle(string chassi);
};

#endif