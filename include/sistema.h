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

		//CRIA NOVA CONCESSIONARIA
		//string create_concessionaria (const string nome);

		//ADICIONA NOVOS VEICULOS
		string add_car (const string nome);	
		string add_truck (const string nome);	
		string add_moto (const string nome);

		//REMOVE VEICULO DO VETOR
		string remove_vehicle(const string chassi);

		//PESQUISA CONCESSIONARIA EM VETOR DE CONCESSIONARIAS
		int search_concessionaria(const string nome);

		//QUEBRA LINHA EM VETOR DE STRINGS
		vector<string> quebra_string(string str, const char* op);
};

#endif
