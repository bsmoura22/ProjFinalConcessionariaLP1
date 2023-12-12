#include "../include/sistema.h"
#include "../include/concessionaria.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;
using std::string;

//Função padrão criada pelo professor para finalizar o programa
string Sistema::quit() 
{
    return "Saindo...";
}



/*Função para criar a concessionária implementada recebendo o comando em formato de string e quebrando 
os dados em posições no vector dados criado para facilitar a organização e tratamento das linhas de código 
recebidas no terminal.
Retorna se a criação foi bem sucedida ou não. */
string Sistema::create_concessionaria (const string nome) 
{
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

/*Funções de Get e Set do vector de concessionárias para acessar e editar o vector criando 
mais concessionárias e adicionando no vector de concessionárias*/

vector<Concessionaria> &Sistema::getConcessionaria()
{
    return concessionarias;
}

void Sistema::setConcessionaria(Concessionaria concessionaria)
{
    concessionarias.push_back(concessionaria);
}

/*Função destinada a quebrar para quebrar a linha de string recebida.*/
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

/*Função criada para imprimir todas as concessionarias criadas e presentes no vector.*/
void Sistema::print_concessionaria() 
{
    for (int i = 0; i < (int)concessionarias.size(); i++)
    {
      cout << "Concessionaria: " << concessionarias[i].getNome() << endl;
      cout << "CNPJ: " << concessionarias[i].getCnpj() << endl;
      cout << "Estoque: " << concessionarias[i].getEstoque() << endl << endl;
    } 
}

/*Add_car é um dos requisitos solicitados no projeto para adicionar o carro/automovel 
na concessionária.
Para isso quebra linha de comando recebida no vector de dados
Em seguida verifica com o numero de chassi se já foi adicionado
se não foi, é adicionado.
Se foi, retorna um aviso.*/
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
      concessionarias[i].setEstoque(concessionarias[i].getEstoque() + 1); //aumenta a quantidade no estoque
      return "add-car";
    }
    
    return "ERRO add-car";

}

/*Add_truck é um dos requisitos solicitados no projeto para adicionar o carro/automovel 
na concessionária.
Para isso quebra linha de comando recebida no vector de dados
Em seguida verifica com o numero de chassi se já foi adicionado
se não foi, é adicionado.
Se foi, retorna um aviso.*/
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
      concessionarias[i].setEstoque(concessionarias[i].getEstoque() + 1);//adiciona a quantidade no estoque
      return "add-truck";
    }
      
    return "ERRO add-truck";
      
}

/*Add_moto é um dos requisitos solicitados no projeto para adicionar o carro/automovel 
na concessionária.
Para isso quebra linha de comando recebida no vector de dados
Em seguida verifica com o numero de chassi se já foi adicionado
se não foi, é adicionado.
Se foi, retorna um aviso.*/
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
      concessionarias[i].setEstoque(concessionarias[i].getEstoque() + 1);//adiciona na quantidade do estoque
      return "add-bike";
    }

    return "ERRO add-bike";
}

/*Função destinada para busca do veiculo a partir do número de chassi no vector.*/
string Sistema::search_vehicle(const string chassi)
{
    for (int i = 0; i < (int) getConcessionaria().size(); i++)
    {
      if(getConcessionaria().at(i).search_vehicle(chassi))
      {
        cout << "CONCESSIONARIA: " << getConcessionaria().at(i).getNome() << endl;
        return " ";
      }
    }
    return "Veiculo nao encontrado\n";
}

/*Função destinada para conferir todos os veiculos adicionados.
void Sistema::checkall_vehicle()
{
    for (int i = 0; i < (int) getConcessionaria().size(); i++)
    {
      cout << "CONCESSIONARIA: " << getConcessionaria().at(i).getNome() << endl;
    }
}
*/ 

/*Função criada a partir da pesquisa do nome da concessionária no 
vector e então retornando sua posição*/
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


/*A partir da pesquisa com a função Search_vehicle, executa a remoção do veículo com 
seu número de chassi e em seguida diminui a quantidade no estoque.*/
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


//LISTA FROTA DE CONCESSIONARIA
//Recebe: nome da concessionaria que irá listar
//Retorna: mensagem se a operação foi bem sucedida ou não
string Sistema::list_concessionaria(const string nome)
{
    int i = search_concessionaria(nome);
    
    if (i == -1)
    {
      return "Concessionaria nao encontrada";
    }

    double valor_carro = 0, valor_moto = 0, valor_caminhao = 0, valor_total = 0;

    for (int j = 0; j < (int)getConcessionaria()[i].getAutomoveis().size(); j++)
    {
      valor_carro += getConcessionaria()[i].getAutomoveis()[j].getPreco();
    }

    for (int j = 0; j < (int)getConcessionaria()[i].getCaminhoes().size(); j++)
    {
      valor_caminhao += getConcessionaria()[i].getCaminhoes()[j].getPreco();
    }
    
    for (int j = 0; j < (int)getConcessionaria()[i].getMotos().size(); j++)
    {
      valor_moto += getConcessionaria()[i].getMotos()[j].getPreco();
    }

    valor_total = valor_caminhao + valor_carro + valor_moto;

    cout << endl;
    cout << "Concessionaria " << nome << endl;
    cout << "Total de Automoveis: " << (int)getConcessionaria()[i].getAutomoveis().size() << "; Valor total: R$ " << valor_carro << endl;
    cout << "Total de Motos: " << (int)getConcessionaria()[i].getMotos().size() << "; Valor total: R$ " << valor_moto << endl;
    cout << "Total de Caminhoes: " << (int)getConcessionaria()[i].getCaminhoes().size() << "; Valor total: R$ " << valor_caminhao << endl;
    cout << "Valor total da frota: R$ " << valor_total << endl;
    return " ";
}

//FUNCAO QUE ATUALIZA TODOS OS VALORES DE VEICULOS DA CONCESSIONARIA
//Recebe: nome da concessionaria e porcentagem que irá aumentar
//Retorna: mensagem se a operação foi bem sucedida ou não
string Sistema::raise_price(const string nome)
{
    dados = quebra_string(nome, " ");
    int i = search_concessionaria(dados[0]);

    if (i == -1)
    {
      return "Concessionaria nao encontrada para atualizar";
    }
    
    for (int j = 0; j < (int)getConcessionaria()[i].getAutomoveis().size(); j++)
    {
      double aumento = getConcessionaria()[i].getAutomoveis()[j].getPreco() * (stof(dados[1])/100);
      getConcessionaria()[i].getAutomoveis()[j].setPreco(aumento + getConcessionaria()[i].getAutomoveis()[j].getPreco());
      cout << "Aumento de " << dados[1] << "\% nos precos de automoveis da concessionaria " << dados[0] << " realizado" << endl;
    }
    
    for (int j = 0; j < (int)getConcessionaria()[i].getCaminhoes().size(); j++)
    {
      double aumento = (getConcessionaria()[i].getCaminhoes()[j].getPreco() * (stof(dados[1])/100));
      getConcessionaria()[i].getCaminhoes()[j].setPreco(aumento + getConcessionaria()[i].getCaminhoes()[j].getPreco());
      cout << "Aumento de " << dados[1] << "\% nos precos de caminhoes da concessionaria " << dados[0] << " realizado" << endl;
    }

    for (int j = 0; j < (int)getConcessionaria()[i].getMotos().size(); j++)
    {
      double aumento = (getConcessionaria()[i].getMotos()[j].getPreco() * (stof(dados[1])/100));
      getConcessionaria()[i].getMotos()[j].setPreco(aumento + getConcessionaria()[i].getMotos()[j].getPreco());
      cout << "Aumento de " << dados[1] << "\% nos precos de motos da concessionaria " << dados[0] << " realizado" << endl;
    }

    return "raise-price \n";

}

//CRIA O ARQUIVO .TXT DA CONCESSIONARIA SOLICITADA
//Recebe: nome do arquivo que será criado
//Retorna: mensagem se a operação foi bem sucedida ou não
string Sistema::save_concessionaria(const string nome)
{
    dados = quebra_string(nome, ".");
    int i = search_concessionaria(dados[0]);

    if (i == -1)
    {
      return "concessionaria nao encontrada";
    }

    fstream file(nome, ios::out);

    file << "cons:" << getConcessionaria()[i].getNome() << " " << getConcessionaria()[i].getCnpj() << " " << getConcessionaria()[i].getEstoque() << "\n";

    for (int j = 0; j < (int)getConcessionaria()[i].getAutomoveis().size(); j++)
    {
      //IMD-SE jipe 400000 3BRBJTWPCM2563458 2018 comum
      file << "car:" << getConcessionaria()[i].getNome() << " " << getConcessionaria()[i].getAutomoveis()[j].getMarca() << " " << getConcessionaria()[i].getAutomoveis()[j].getPreco()  << " " << getConcessionaria()[i].getAutomoveis()[j].getChassi() << " " << getConcessionaria()[i].getAutomoveis()[j].getFabricacao()  << " "<< getConcessionaria()[i].getAutomoveis()[j].getTipo_motor() << "\n";
    }

    for (int j = 0; j < (int)getConcessionaria()[i].getCaminhoes().size(); j++)
    {
      file << "truck:" << getConcessionaria()[i].getNome() <<  " " << getConcessionaria()[i].getCaminhoes()[j].getMarca() << " " << getConcessionaria()[i].getCaminhoes()[j].getPreco() << " " << getConcessionaria()[i].getCaminhoes()[j].getChassi()<< " " << getConcessionaria()[i].getCaminhoes()[j].getFabricacao() << " " << getConcessionaria()[i].getCaminhoes()[j].getTipo_Carga() << "\n";
    }

    for (int j = 0; j < (int)getConcessionaria()[i].getMotos().size(); j++)
    {
      file << "bike:" << getConcessionaria()[i].getNome() << " " << getConcessionaria()[i].getMotos()[j].getMarca() << " " << getConcessionaria()[i].getMotos()[j].getPreco() << " " << getConcessionaria()[i].getMotos()[j].getChassi() << " " << getConcessionaria()[i].getMotos()[j].getFabricacao() << " " << getConcessionaria()[i].getMotos()[j].getModelo() << "\n";
    }
    
    return "save-concessionaria";
}

//FUNÇÃO QUE RECUPERA DADOS DO ARQUIVO 
//Recebe: nome do arquivo txt
//Retorna: mensagem se a operação foi bem sucedida ou não
string Sistema::load_concessionaria(const string nome)
{
    string linha;

    ifstream concessionaria;
    concessionaria.open(nome);

    if(concessionaria.is_open())
    {      
      while (getline(concessionaria, linha))
      {
        dados = quebra_string(linha, ":");

        if (dados[0] == "car")
        {
          add_car(dados[1]);
        }

        else if (dados[0] == "truck")
        {
          add_truck(dados[1]);
        }

        else if (dados[0] == "bike")
        {
          add_moto(dados[1]);
        }

        else if(dados[0] == "conc")
        {
          create_concessionaria(dados[1]);
        }
        
      } 

    }
    return "load-concessionaria";
}