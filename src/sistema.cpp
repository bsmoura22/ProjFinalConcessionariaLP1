#include "sistema.h"
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

/* Funções exercidas pelo sistema, criar concessionaria, remover e adicionar veiculos, sair do sistema e mais. */
string Sistema::quit() {
  return "Saindo...";
}

string Sistema::create_concessionaria (const string nome) {
   dados = quebra_string(nome, " ");

    int i = search_concessionaria(dados[0]);
    if (i == -1)
    {
      Concessionaria n_con(dados[0], dados[1], stoi(dados[2]));
      setConcessionaria(n_con);
    }

    else
    {
      return "concessionaria ja adicionada";
    }
    
    return "create_concessionaria";
}


//FUNÇÃO DE ACESSO AS CONCESSIONARIAS
//Retorna: o vetor de concessionaria
vector<Concessionaria> &Sistema::getConcessionaria()
{
    return concessionarias;
}

//ADICIONA AO VETOR DE CONCESSIONARIA
//Recebe: novo obj. do tipo concessionaria
void Sistema::setConcessionaria(Concessionaria concessionaria)
{
    concessionarias.push_back(concessionaria);
}

//QUEBRA A STRING ADD CADA PARTE EM UMA POSIÇÃO DO VETOR
//Recebe: string que deverá se quebrada e operador para quebra
//Retorna: um vetor com todos os dados da string
vector<string> Sistema::quebra_string(string str, const char* op) 
{
    vector<string> p;

    string resto = str, bloco;
    size_t operator_position = resto.find_first_of(op);

    while (operator_position != string::npos)
    {
        bloco = resto.substr(0, operator_position);
        resto = resto.substr(operator_position + 1);
        operator_position = resto.find_first_of(op);
        p.push_back(bloco);
    }

    if (resto.length() > 0)
    {
        p.push_back(resto);
    }

    return p;  
}


//ADICIONA UM NOVO CARRO
//Recebe os dados do novo carro
//Retorna: mensagem se a operação foi bem sucedida ou não
string Sistema::add_car(const string nome)
{
    dados = quebra_string(nome, " ");
    int i = search_concessionaria(dados[0]);

    if (i == -1)
    {
      return "Concessionaria nao encontrada\n";
    }
    

    if(getConcessionaria().at(i).search_vehicle(dados[3]))
    {
      cout << "ERRO - Veiculo " << dados[3] << " ja adicionado a concessionaria " << dados[0] << endl;
      return " ";
    }

    if (concessionarias[i].getNome() == dados[0])
    {      
      Automoveis car(dados[5], dados[2], dados[1], stof(dados[3]), stoi(dados[4]));
      concessionarias[i].setAutomoveis(car);
      concessionarias[i].setEstoque(concessionarias[i].getEstoque() + 1);
      return "add-car";
    }
    
    return "ERRO add-car";

}

//ADICIONA UM NOVO CAMINHAO
//Recebe os dados do novo caminhão
//Retorna: mensagem se a operação foi bem sucedida ou não
string Sistema::add_truck(const string nome)
{
    dados = quebra_string(nome, " ");
    int i = search_concessionaria(dados[0]);

    if (i == -1)
    {
      return "Concessionaria nao encontrada\n";
    }

    if(getConcessionaria().at(i).search_vehicle(dados[3]))
    {
      cout << "ERRO - Veiculo " << dados[3] << " ja adicionado a concessionaria " << dados[0] << endl;
      return " ";
    }

    if (concessionarias[i].getNome() == dados[0])
    {
      Caminhoes truck(dados[5], dados[2], dados[1], stof(dados[3]), stoi(dados[4]));
      concessionarias[i].setCaminhoes(truck);
      concessionarias[i].setEstoque(concessionarias[i].getEstoque() + 1);
      return "add-truck";
    }
      
    return "ERRO add-truck";
      
}

//ADICIONA UMA NOVA MOTO
//Recebe: os dados da nova moto
//Retorna: mensagem se a operação foi bem sucedida ou não
string Sistema::add_moto(const string nome)
{
    dados = quebra_string(nome, " ");
    int i = search_concessionaria(dados[0]);

    if (i == -1)
    {
      return "Concessionaria nao encontrada\n";
    }

    if(getConcessionaria().at(i).search_vehicle(dados[3]))
    {
      cout << "ERRO - Veiculo " << dados[3] << " ja adicionado a concessionaria " << dados[0] << endl;
      return " ";
    }

    if (concessionarias[i].getNome() == dados[0])
    {
      Motos motos(dados[5], dados[2], dados[1], stof(dados[3]), stoi(dados[4]));
      concessionarias[i].setMotos(motos);
      concessionarias[i].setEstoque(concessionarias[i].getEstoque() + 1);
      return "add-bike";
    }

    return "ERRO add-bike";
}



string Sistema::remove_vehicle(const string chassi)
{
    for (int i = 0; i < (int) getConcessionaria().size(); i++)
    {
      if(getConcessionaria().at(i).search_vehicle(chassi))
      {
        getConcessionaria()[i].remove_vehicle(chassi);
        getConcessionaria()[i].setEstoque(getConcessionaria()[i].getEstoque() - 1);
        return "remove-vehicle\n";
      }
    }
    return "Veiculo nao encontrado\n";
}

//PESQUISA A CONCESSIONARIA
//Recebe: o nome da concessionaria
//Retorna: indice que a concessionaria se encontra no vetor
int Sistema::search_concessionaria(const string nome)
{
    for (int i = 0; i < (int)getConcessionaria().size(); i++)
    {
      if (getConcessionaria()[i].getNome() == nome)
      {
        return i;
      }
    }
    return -1;
}



/* IMPLEMENTAR MÉTODOS PARA OS COMANDOS RESTANTES */
