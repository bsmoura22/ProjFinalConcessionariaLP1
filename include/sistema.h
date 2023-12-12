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
using std::string;

class Sistema {
  private:
		vector<string> dados;
		vector<Concessionaria> concessionarias;
		
  public:
		//ENCERRA O PROGRAMA
		string quit();

		//ACESSO E EDIÇÃO DO VETOR DE CONCESSIONARIAS
		vector<Concessionaria> &getConcessionaria();
		void setConcessionaria(Concessionaria concessionaria);

		//CRIA NOVA CONCESSIONARIA
		string create_concessionaria (const string nome);

		//ADICIONA NOVOS VEICULOS
		string add_car (const string nome);	
		string add_truck (const string nome);	
		string add_moto (const string nome);

		//PESQUISA VEICULO NO VETOR
		string search_vehicle(const string chassi);

		//REMOVE VEICULO DO VETOR
		string remove_vehicle(const string chassi);

		//LISTA FROTA DA CONCESSIONARIA
		string list_concessionaria(const string nome);

		//AUMENTA VALORES DOS VEICULOS
		string raise_price(const string nome);

		//APRESENTA DADOS DE ARQUIVO NA TELA
		string load_concessionaria(const string nome);

		//SALVA DADOS DE CONCESSIONARIA EM TXT
		string save_concessionaria(const string nome);

		//PESQUISA CONCESSIONARIA EM VETOR DE CONCESSIONARIAS
		int search_concessionaria(const string nome);

		//QUEBRA LINHA EM VETOR DE STRINGS
		vector<string> quebra_string(string str, const char* op);

		//IMPRIME CONCESSIONARIAS
		void print_concessionaria();

};

#endif