#include "caminhoes.h"
using namespace std;

Caminhao::Caminhao(string tipo_carga, string marca, double preco, double chassi, int fabricacao) //Construtor do caminhão
{
    setTipo_Carga(tipo_carga);
    setChassi(chassi);
    setMarca(marca);
    setPreco(preco);
    setFabricacao(fabricacao);
    
}

string Caminhao::getTipo_Carga() //acesso ao tipo de carga
{
    return tipo_de_carga;
}

void Caminhao::setTipo_Carga(string t) //edita o tipo de carga do caminhão
{
    tipo_de_carga = t;
}

void Caminhao::print_caminhao() //saída do caminhão feito (impressão)
{
    cout << endl;
    cout << "TIPO DE CARGA: " << getTipo_Carga() << endl;
    cout << "MARCA: " << getMarca() << endl;
    cout << "PRECO: " << getPreco() << endl;
    cout << "CHASSI: " << getChassi() << endl;
    cout << "ANO DE FABRICACAO: " << getFabricacao() << endl;
}