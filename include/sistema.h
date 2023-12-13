#ifndef SISTEMA_H
#define SISTEMA_H
#include <vector>
#include <string>
#include <iostream>
#include <istream>
#include "concessionaria.h"
#include <sstream>
#include <algorithm>
#include <fstream>//manipulação de arquivo

using namespace std;
using std::string;

class Sistema {
  private:
		vector<string> dados; //utilizado para facilitar leitura e manipulação dos comandos da linha de terminal
		vector<Concessionaria> concessionarias; //vetctor das concessionárias
		
  public:
		
		string quit();

		/*Get e Set do vector de concessionaria para permitir acesso e edição*/
		vector<Concessionaria> &getConcessionaria();
		void setConcessionaria(Concessionaria concessionaria);

		string create_concessionaria (const string nome); //função base criadora da concessionária
		
		/*Funções base de adição de veículo na concessionária*/
		string add_car (const string nome);	
		string add_truck (const string nome);	
		string add_moto (const string nome);

		string search_vehicle(const string chassi);//busca o veiculo atraves do chassi no vector com index

		string remove_vehicle(const string chassi);//com auxilio do search, remove o veiculo do vector

		string list_concessionaria(const string nome);//listar as concessionarias

		string raise_price(const string nome);//função para aumentar o valor dos veiculos

		int search_concessionaria(const string nome); //função que pesquisa a concessionária no vector de concessionária

		vector<string> quebra_string(string str, const char* op); //função responsável por quebrar a string recebida e alocar cada dado numa posição do vector

	    void print_concessionaria(); //função que imprime todas as informações da concessionária
        
		string load_concessionaria(const string nome); //apresenta os dados na tela

		string save_concessionaria(const string nome);//salva os dados em um arquivo
};

#endif