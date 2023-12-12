#include "../include/veiculos.h"
using namespace std;

Veiculos::Veiculos() //construtor sem parametros (classe "pai")
{
    setMarca("");
    setPreco(0);
    setChassi("");
    setFabricacao(0);
}

string Veiculos::getMarca() //acesso a marca
{
    return marca;
}

void Veiculos::setMarca(string m) //função que edita a marca do veiculo
{
    marca = m;
}

int Veiculos::getPreco() //acesso ao preço
{
    return preco;
}

void Veiculos::setPreco(double p) //função que edita o preço
{
    preco = p;
}

string Veiculos::getChassi() //acesso ao parametro chassi
{
    return chassi;
}

void Veiculos::setChassi(string c) //função que dita o chassi
{
    chassi = c;
}

int Veiculos::getFabricacao() //acesso ao ano de fabricação
{
    return fabricacao;
}

void Veiculos::setFabricacao(int a) //edição do ano de fabricação
{
    fabricacao = a;
}