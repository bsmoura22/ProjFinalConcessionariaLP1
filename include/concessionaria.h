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
using std::string;

class Concessionaria
{
    protected:
        int estoque;
        string nome;
        string CNPJ;
        double valor_auto;
        double valor_caminhoes;
        double valor_motos;

        vector<Automoveis> v_auto;
        vector<Caminhoes> v_cam;
        vector<Motos> v_motos;
    
    public:

        Concessionaria(string n, string c, int e); //construtor da classe

         /*Getters e Setters dos vetores de todos os tipos de veículo (automoveis, caminhoes e motos)
         Além dos atributos da classe concessionária*/
        vector<Automoveis> &getAutomoveis();
        void setAutomoveis(Automoveis automoveis);        

        vector<Caminhoes> &getCaminhoes();
        void setCaminhoes(Caminhoes caminhoes); 

        vector<Motos> &getMotos();
        void setMotos(Motos motos);   

        string getNome();
        void setNome(string n);

        string getCnpj();
        void setCnpj(string c);

        int getEstoque();
        void setEstoque(int e);

         /*Atributos index para localizar os veículos nos vetores*/
        int indexCar(string chassi);
        int indexTruck(string chassi);
        int indexMoto(string chassi);

        bool search_vehicle(string chassi);//função de busca do veiculo com o numero de chassi

        bool remove_vehicle(string chassi);//remoção do veiculo do vetor atraves do numero de chassi
};

#endif