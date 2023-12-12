#include "../include/caminhoes.h"
using namespace std;
using std::string;

/*Uso de getters e setters para alterar e acessar as variaveis da classe.*/

Caminhoes::Caminhoes(string tipo_carga, string chassi, string marca, double preco, int fabricacao) //Construtor do caminhão
{
    setTipo_Carga(tipo_carga);
    setMarca(marca);
    setPreco(preco);
    setChassi(chassi);
    setFabricacao(fabricacao);
    
}

string Caminhoes::getTipo_Carga() //acesso ao tipo de carga
{
    return tipo_de_carga;
}

void Caminhoes::setTipo_Carga(string t) //edita o tipo de carga do caminhão
{
    tipo_de_carga = t;
}

void Caminhoes::print_Caminhoes() //saída do caminhão feito (impressão)
{
    cout << endl;
    cout << "TIPO DE CARGA: " << getTipo_Carga() << endl;
    cout << "MARCA: " << getMarca() << endl;
    cout << "PRECO: " << getPreco() << endl;
    cout << "CHASSI: " << getChassi() << endl;
    cout << "ANO DE FABRICACAO: " << getFabricacao() << endl;
}