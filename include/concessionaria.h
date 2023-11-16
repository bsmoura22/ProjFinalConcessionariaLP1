#ifndef CONCESSIONARIA_H
#define CONCESSIONARIA_H 
#include <iostream>
#include <algorithm>
#include "veiculos.h"
#include "automoveis.h"
#include "motos.h"
#include "caminhoes.h"
using std::string;

// Definição da classe Concessionária
class concessionaria {
   protected:
      string nome;
      string cnpj;
      int estoque;

      vector<Automoveis> v_carro;
      vector<Caminhoes> v_cam;
      vector<Motos> v_moto;
      // atributos 
   public:      
        Concessionaria (string n, string cn, int e); //construtor
      
        //Utilização de vetor como TAD para armazenar os veículos
        vector<Automoveis> &getAutomoveis(); 
        void setAutomoveis(Automoveis automoveis);        
        
        vector<Caminhoes> &getCaminhoes();
        void setCaminhoes(Caminhoes caminhoes); 

        vector<Motos> &getMotos();
        void setMotos(Motos motos);   

        string getNome(); //Acesso ao nome da concessionária
        void setNome(string n);
       
        string getCnpj(); //Acesso ao CNPJ
        void setCnpj(string cn);
       
        int getEstoque();//Acesso ao estoque
        void setEstoque(int e);
       
        /*Por estar usando vetor, para fazer a localização 
        e/ou remoção de cada veiculo é necessário utilizar a posição do mesmo no vetor, 
        por isso a função para localizar o indice/index*/
        int indexCar(string chassi);
        int indexTruck(string chassi);
        int indexMoto(string chassi);

        
        bool search_vehicle(string chassi); //função para remover veiculo pelo chassi

        bool remove_vehicle(string chassi); //função para remover veiculo pelo chassi
};

#endif