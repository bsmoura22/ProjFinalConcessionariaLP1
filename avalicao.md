
# Identificação

* Nome: Beatriz Santana de Moura

* Matrícula: 20220040234
  
# Compilação  

* Para iniciar a compilação digite no terminal: make
* Para rodar o programa execute a seguinte linha de código: ./build/programa
* Após iniciar, crie a concessionária com a seguinte linha:
  ```c
  | create-concessionaria <nome-concessionaria> <CNPJ> <estoque>
  | create-concessionaria IMD_SA 22.222.222/0002-22 0
* Para adicionar os veículos:
  * Automóvel:
    ```c
    | add-car <nome-concessionaria> <marca> <chassi> <preço> <ano_de_fabricação> <tipo_de_motor>
    | add-car IMD_SA Mercedes9BRBLWHEXG0107721 100000 2023 gasolina
  * Moto:
    ```c
    | add-bike <nome-concessionaria> <marca> <chassi> <preço> <ano_de_fabricação> <modelo>
    | add-bike IMD_SA Toyota 9BRBLQHEXH4208811 70000 2017 esportiva
  * Caminhão:
    ```c
    | add-truck <nome-concessionaria> <marca> <chassi> <preço> <ano_de_fabricação> <tipo_de_carga>
    | add-truck IMD_SA Volkswagen 7BRBLQHEXG0208811 700000 2022 perigosa
* Para remover e buscar um veículo utiliza-se do numero do chassi como informação base para comparar enquanto percorre o vector até localizar o index. Para isso temos:
  * Buscar:
    ```c
    | search-vehicle <chassi>
    | search-vehicle 7BRBLQHEXG0208811
  * Remover:
    ```c
    |remove-vehicle <chassi>
    |remove-vehicle 7BRBLQHEXG0208811
* Para listar os veículos registrados na concessionária:
    ```c
    |list-concessionaria <nome-concessionaria>
    |list-concessionaria IMD_SA
* Assim como para salvar os dados em um arquivo txt.:
    ```c
    |save-concessionaria <nome-arquivo.txt>
    |save-concessionaria IMD_SA.txt
* Ademais é possível apresentar os dados de um arquivo previamente salvo:
    ```c
    |load-concessionaria <nome-arquivo.txt>
    |load-concessionaria IMD_SA.txt
* Por fim a função já previamente implementada: quit.
  
   
# Limitações

* 
   
# Autoavaliação

- Modelagem e implementação das classes Concessionária, Veículo, Automóvel, Moto, Caminhão | **10/ 10**
  - 0: sem modelagem e implementação de classes
  - 5: apenas algumas classes modeladas e implementadas; ausência de herança
  - 10: modelagem e implementação completa com uso de herança
  
- Implementação e uso do comando `create-concessionaria` | **10/ 10**
  - 0: não cria concessionária via linha de comando 
  - 5: permite criar apenas uma concessionária
  - 10: permite criar mais do que uma concessionária
  
- Implementação e uso dos comandos para adicionar veículos `add-car/add-bike/add-truck` | **10 / 10**
  - 0: não permite criar veículos via linha de comando
  - 5: permite criar apenas um ou outro veículo em uma única concessionária
  - 10: permite criar qualquer tipo de veículo em qualquer uma das concessionárias disponíveis

- Não permitir adicionar um veículo que já tenha sido anteriormente adicionado | **... / 10**
  - 0: não realiza o teste
  - 10: realiza o teste e indica o erro  

- Implementação e uso do comando para remover veículos `remove-vehicle` | **... / 10**
  - 0: comando não implementado
  - 10: comando implementado e funcional

- Implementação e uso do comando para busca de veículos `search-vehicle` | **... / 15 - Bônus: ...**
  - 0: não implementado
  - 15: implementado e funcional
  - bonus +10: implementado com estratégia de busca diferente da busca exaustiva
  - bonus +10: uso de métodos virtuais para impressão na tela
  - bonus +10: uso de sobrecarga de operadores para impressão na tela

- Implementação e uso do comando `list-concessionaria` | **10/ 10 - Bônus: ...**
  - 0: não implementado
  - 10: implementado e funcional   
  - bonus +10: uso de sobrecarga de operadores para impressão na tela

- Implementação e uso do comando `raise-price` | **... / 10 - Bônus: ...**
  - 0: não implementado
  - 10: implementado e funcional 
  - bonus +10: implementado com uso de método virtual

- Implementação e uso do comando `save-concessionaria` e `load-concessionaria` | **... / 30**
  - 0: não implementado
  - 15: ambos os comandos implementados e funcionais
  
- Implementação eficiente através do uso de referencias e contêineres da STL | **... / 10**
  - 0: não usou contêiner da STL nem fez uso eficiente dos recursos computacionais
  - 5: usou contêiner da STL mas não otimizou uso dos recursos computacionais
  - 10: usou contêiner da STL junto a algoritmos e práticas de bom uso de recursos computacionais
  
- Organização do código em src, include, data | **5 / 5**
  - 0: não organizou o código
  - 5: organizou o código 
  
- Documentação do código | **5 / 5**
  - 0: não documentou o código
  - 5: documentou o código 
  
- Implementação e documentação de arquivos e procedimentos de compilação e teste | **15 / 15**
  - 0: não implementou arquivos e procedimentos de compilação e teste
  - 5: implementou alguns arquivos e procedimentos de compilação e teste (com alguma documentação) 
  - 15: Ampla implementação e documentação de arquivos e procedimentos de compilação e teste (com exemplos)
 
 # Total
 
 **... / 150 ** pontos (sem bônus)
 
 **... / 200 ** pontos (com bônus)
