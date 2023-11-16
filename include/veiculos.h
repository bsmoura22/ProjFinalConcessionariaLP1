#ifndef VEICULOS_H
#define VEICULOS_H
#include <iostream>
#include <vector>
#include <list>

using namespace std; 
using std::string;

// Definição da classe Concessionária
class  {
   protected:
      string marca;
      double preco;
      string chassi;
      int fabricacao;
      // atributos 
   public:      
      Veiculos (); //construtor
       //Acesso a marca
        string getMarca();
        void setMarca(string m);
        //Acesso ao preço do veiculo
        double getPreco();
        void setPreco(double p);
        //Acesso a chassi 
        string getChassi();
        void setChassi(string c); 
        //Acesso ao ano de fabricação
        int getFabricacao();
        void setFabricacao(int f);
};

#endif