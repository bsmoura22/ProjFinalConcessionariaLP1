#include "concessionaria.h"


Concessionaria::Concessionaria(string n, string cn, int e) // Construtor da concessionária
{
    setNome(n);
    setCnpj(cn);
    setEstoque(e);
}
 
 /*Funções de acesso (get) e edição (set) de cada vetor de veículo. 
 O acesso retorna o vetor de cada um (v_carro, v_cam, v_moto), 
 já a edição é responsável por adicionar um novo veículo em cada vetor com a função de vector "push_back".*/

vector<Automoveis> &Concessionaria::getAutomoveis()
{
    return v_carro;
}

void Concessionaria::setAutomoveis(Automoveis automoveis)
{
    v_carro.push_back(automoveis);
}   

vector<Caminhoes> &Concessionaria::getCaminhoes()
{
    return v_cam;
}

void Concessionaria::setCaminhoes(Caminhoes caminhoes)
{
    v_cam.push_back(caminhoes);
} 

vector<Motos> &Concessionaria::getMotos()
{
    return v_moto;
}

void Concessionaria::setMotos(Motos motos)
{
    v_moto.push_back(motos);
}   

/*Assim como o acesso e edição dos vetores de automoveis, motos e caminhões, 
há o acesso (get) e edição (set) de cada atributo da concessionária, 
como Nome, CNPJ, e estoque.
*/

string Concessionaria::getNome()
{
    return nome;
}

void Concessionaria::setNome(string n)
{
    nome = n;
}

string Concessionaria::getCnpj()
{
    return CNPJ;
}

void Concessionaria::setCnpj(string cn)
{
    CNPJ = cn;
}

int Concessionaria::getEstoque()
{
    return estoque;
}

void Concessionaria::setEstoque(int e)
{
    estoque = e;
}

/* Por estar utilizando vector é importante lidar com a posição de cada objeto dentro dele,
portanto, implementei a função index de cada tipo de veiculo para retornar a posição
do mesmo dentro do seu respectivo vetor, assim é possível usar essa informação na remoção de veículos 
e futuramente na busca. Recebendo a string do Chassi e retornando o indice.
*/

int Concessionaria::indexCar(string chassi)
{
    auto it = find_if(getAutomoveis().begin(), getAutomoveis().end(), [&chassi] (Automoveis &car) {return car.getChassi() == chassi;});

    if (it != getAutomoveis().end())
    {
        auto index = distance(getAutomoveis().begin(), it);
        return index;
    }

    else
    {
        return -1;
    }
}

int Concessionaria::indexTruck(string chassi)
{
    auto it = find_if(getCaminhoes().begin(), getCaminhoes().end(), [&chassi] (Caminhoes &truck) {return truck.getChassi() == chassi;});

    if (it != getCaminhoes().end())
    {
        auto index = distance(getCaminhoes().begin(), it);
        return index;
    }

    else
    {
        return -1;
    }
    
}

int Concessionaria::indexMoto(string chassi)
{
    auto it = find_if(getMotos().begin(), getMotos().end(), [&chassi] (Motos &motos) {return motos.getChassi() == chassi;});

    if (it != getMotos().end())
    {
        auto index = distance(getMotos().begin(), it);
        return index;
    }

    else
    {
        return -1;
    }
    
}
bool Concessionaria::remove_vehicle(string chassi) //Função de remoção do veículo em seu respectivo vetor, recebendo a string do chassi.
{
    if(indexCar(chassi) != -1)
    {
        getAutomoveis().erase(getAutomoveis().begin() + indexCar(chassi));
    }

    else if (indexTruck(chassi) != -1)
    {
        getCaminhoes().erase(getCaminhoes().begin() + indexTruck(chassi));
    }

    else if (indexMoto(chassi) != -1)
    {
        getMotos().erase(getMotos().begin() + indexMoto(chassi));
    }

    return false;  
}