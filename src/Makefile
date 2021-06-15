OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o Almacen.o Sala.o Inventario.o
	g++ -o program.exe *.o 

Almacen.o: Almacen.cc Almacen.hh Sala.hh Inventario.hh BinTree.hh
	g++ -c Almacen.cc $(OPCIONS) 

Sala.o: Sala.cc Sala.hh Inventario.hh
	g++ -c Sala.cc $(OPCIONS) 

Inventario.o: Inventario.cc Inventario.hh
	g++ -c Inventario.cc $(OPCIONS) 

program.o: program.cc Almacen.hh Inventario.hh BinTree.hh
	g++ -c program.cc $(OPCIONS) 
	
clean:
	rm *.o
	rm *.exe
