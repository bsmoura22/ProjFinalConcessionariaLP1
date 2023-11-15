#include "concessionaria.h"


Concessionaria::Concessionaria(string n, string cn, int e) // Construtor da concessionária
{
    setNome(n);
    setCnpj(cn);
    setEstoque(e);
}

//FUNÇÃO DE ACESSO AOS AUTOMOVEIS
//Retorna: vetor de automoveis
vector<Automoveis> &Concessionaria::getAutomoveis()
{
    return v_carro;
}

//FUNÇÃO DE EDIÇÃO DE AUTOMOVEIS
//Adiciona um novo automovel ao vetor
void Concessionaria::setAutomoveis(Automoveis automoveis)
{
    v_car.push_back(automoveis);
}   

//FUNÇÃO DE ACESSO AOS CAMINHOES
//Retorna: vetor de caminhoes
vector<Caminhao> &Concessionaria::getCaminhao()
{
    return v_cam;
}

//FUNÇÃO DE EDIÇÃO DE CAMINHOES
//Adiciona um novo caminhão ao vetor
void Concessionaria::setCaminhao(Caminhao caminhao)
{
    v_cam.push_back(caminhao);
} 

//FUNÇÃO DE ACESSO AS MOTOS
//Retorna: vetor de motos
vector<Moto> &Concessionaria::getMoto()
{
    return v_moto;
}

//FUNÇÃO DE EDIÇÃO DE MOTOS
//Adiciona uma nova moto ao vetor
void Concessionaria::setMoto(Moto moto)
{
    v_moto.push_back(moto);
}   

//FUNÇÃO DE ACESSO AO NOME DA CONCESSIONARIA
//Retorna: nome da concessionaria
string Concessionaria::getNome()
{
    return nome;
}

//FUNÇÃO DE EDIÇÃO DO NOME DA CONCESSIONARIA
//Edita o nome da concessionaria
void Concessionaria::setNome(string n)
{
    nome = n;
}

//FUNÇÃO DE ACESSO AO CNPJ DA CONCESSIONARIA
//Retorna: cnpj da concessionaria
string Concessionaria::getCnpj()
{
    return CNPJ;
}

//FUNÇÃO DE EDIÇÃO DE CNPJ DA CONCESSIONARIA
//Edita o cnpj da concessionaria
void Concessionaria::setCnpj(string cn)
{
    CNPJ = cn;
}

//FUNÇÃO DE ACESSO AO ESTOQUE
//Retorna: quantidade de veiculos no estoque
int Concessionaria::getEstoque()
{
    return estoque;
}

//FUNÇÃO DE EDIÇÃO DE ESTOQUE DA CONCESSIONARIA
//Altera o valor de veiculos no estoque
void Concessionaria::setEstoque(int e)
{
    estoque = e;
}

