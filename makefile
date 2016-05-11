OBJ= lib/TABBPoro_comp.o lib/tporo.o lib/tvectorporo.o lib/tlistaporo.o lib/tabbporo.o lib/tavlporo.o
COMP=g++
OPC=-g

main: $(OBJ)
	$(COMP) $(OPC) $(OBJ) -o ejecutable
lib/TABBPoro_comp.o: src/TABBPoro_comp.cpp include/tporo.h
	$(COMP) $(OPC) -c -Iinclude src/TABBPoro_comp.cpp -o lib/TABBPoro_comp.o
lib/tporo.o: include/tporo.h lib/tporo.cpp
	$(COMP) $(OPC) -c -Iinclude lib/tporo.cpp -o lib/tporo.o
lib/tvectorporo.o: include/tvectorporo.h lib/tvectorporo.cpp
	$(COMP) $(OPC) -c -Iinclude lib/tvectorporo.cpp -o lib/tvectorporo.o
lib/tlistaporo.o: include/tlistaporo.h lib/tlistaporo.cpp
	$(COMP) $(OPC) -c -Iinclude lib/tlistaporo.cpp -o lib/tlistaporo.o
lib/tabbporo.o: include/tabbporo.h lib/tabbporo.cpp
	$(COMP) $(OPC) -c -Iinclude lib/tabbporo.cpp -o lib/tabbporo.o
lib/tavlporo.o: include/tavlporo.h lib/tavlporo.cpp
	$(COMP) $(OPC) -c -Iinclude lib/tavlporo.cpp -o lib/tavlporo.o
