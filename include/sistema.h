#ifndef SISTEMA_H
#define SISTEMA_H
#include <vector>
#include <string>
#include <iostream>
#include <istream>
#include "concessionaria.h"
#include <sstream>
#include <algorithm>
#include <fstream>
using namespace std;

// Sistema deve concentrar todas as operações
class Sistema {
  private:
        std::vector<std::string> dados;
		std::vector<Concessionaria> concessionarias; //um vetor com todos as concessionarias
  public:

		/*Encerra o funcionamento do programa.
			@return uma string com a mensagem "Saindo.."
		*/
		string quit();

		/* Cria uma concessionaria e retorna uma string de erro/sucesso 
			@param nome o nome da concessionaria
			@return uma string contendo uma mensagem de erro ou "Concessionaria Criada"
		*/
		std::string create_concessionaria (const string nome);

		vector<Concessionaria> &getConcessionaria();
		void setConcessionaria(Concessionaria concessionaria);

		
		//Cria os novos veículos
		string add_car (const string nome);	
		string add_truck (const string nome);	
		string add_moto (const string nome);

		string search_vehicle(const string chassi);  //busca o veiculo de acordo com o chassi

		string remove_vehicle(const string chassi); //remove o veículo de seu respectivo vector de acordo com o chassi

		int search_concessionaria(const string nome); //verifica a existencia da concessionária

		vector<string> quebra_string(string str, const char* op); //quebra a string recebida em dados
};

#endif
