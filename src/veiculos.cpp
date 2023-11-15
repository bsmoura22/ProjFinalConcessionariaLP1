#include "veiculos.h"

Veiculo::Veiculo() //construtor sem parametros (classe "pai")
{
    setChassi("");
    setMarca("");
    setPreco(0);
    setFabricacao(0);
}

double Veiculo::getChassi() //acesso ao parametro chassi
{
    return chassi;
}

void Veiculo::setChassi(double c) //função que dita o chassi
{
    chassi = c;
}

string Veiculo::getMarca() //acesso a marca
{
    return marca;
}

void Veiculo::setMarca(string m) //função que edita a marca do veiculo
{
    marca = m;
}

double Veiculo::getPreco() //acesso ao preço
{
    return preco;
}

void Veiculo::setPreco(double p) //função que edita o preço
{
    preco = p;
}

int Veiculo::getFabricacao() //acesso ao ano de fabricação
{
    return fabricacao;
}

void Veiculo::setFabricacao(int a) //edição do ano de fabricação
{
    fabricacao = a;
}