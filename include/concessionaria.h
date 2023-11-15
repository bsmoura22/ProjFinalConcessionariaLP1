#ifndef CONCESSIONARIA_H
#define CONCESSIONARIA_H 
#include <iostream>
#include <algorithm>
#include "veiculos.h"
#include "automoveis.h"
#include "moto.h"
#include "caminhao.h"
using std::string;

// Definição da classe Concessionária
class concessionaria {
   protected:
      string nome;
      string cnpj;
      int estoque;

      vector<Automoveis> v_carro;
      vector<Caminhao> v_cam;
      vector<Moto> v_moto;
      // atributos 
   public:      
        Concessionaria (string n, string cn, int e); //construtor
      
        //Utilização de vetor como TAD para armazenar os veículos
        vector<Automoveis> &getAutomoveis(); 
        void setAutomoveis(Automoveis automoveis);        
        
        vector<Caminhao> &getCaminhao();
        void setCaminhao(Caminhao caminhao); 

        vector<Moto> &getMoto();
        void setMoto(Moto moto);   

        string getNome(); //Acesso ao nome da concessionária
        void setNome(string n);
       
        string getCnpj(); //Acesso ao CNPJ
        void setCnpj(string cn);
       
        int getEstoque();//Acesso ao estoque
        void setEstoque(int e);

        bool remove_vehicle(double chassi); //função para remover veiculo pelo chassi
};

#endif