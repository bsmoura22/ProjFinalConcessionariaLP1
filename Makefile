.DEFAULT_GOAL := all

#quando adicionar uma nova dependencia não esqueça de atualizar aqui!
OBJECTS=build/sistema.o build/executor.o
build/programa.o: src/programa.cpp include/sistema.h include/executor.h 
	g++ -c src/programa.cpp -o build/programa.o

build/sistema.o: src/sistema.cpp include/sistema.h
	g++ -Iinclude src/sistema.cpp -c -o build/sistema.o

build/executor.o: src/executor.cpp include/executor.h 
	g++ -Iinclude src/executor.cpp -c -o build/executor.o

#concessionaria: build/programa.o build/sistema.o build/executor.o build/concessionaria.o build/veiculos.o build/automoveis.o build/caminhões.o build/motos.o
#	g++ -Wall -Iinclude -o ./bin/concessionaria build/programa.o build/sistema.o build/executor.o build/concessionaria.o build/veiculos.o build/automoveis.o build/caminhoes.o build/motos.o



build/concessionaria.o: src/concessionaria.cpp include/concessionaria.h
	g++ -c src/concessionaria.cpp -o build/concessionaria.o

build/veiculos.o: src/veiculos.cpp include/veiculos.h
	g++ -c src/veiculos.cpp -o build/veiculos.o

build/automoveis.o: src/automoveis.cpp include/automoveis.h
	g++ -c src/automoveis.cpp -o build/automoveis.o

build/caminhoes.o: src/caminhoes.cpp include/caminhoes.h
	g++ -c src/caminhoes.cpp -o build/caminhoes.o

build/motos.o: src/motos.cpp include/motos.h
	g++ -c src/motos.cpp -o build/motos.o
	


#para adicionar novas regras apenas siga o formato
#build/concessionaria.o: src/concessionaria.cpp include/concessionaria.h
#	g++ -Iinclude src/concessionaria.cpp -c

objects: $(OBJECTS)

programa: objects src/programa.cpp
	g++ -Wall -fsanitize=address -Iinclude $(OBJECTS) src/programa.cpp -o bin/programa

clean:
	rm build/*.o bin/programa

all: programa

run:
	./bin/programa
