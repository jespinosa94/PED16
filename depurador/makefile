_OBJ= main.o tporo.o
COMP=g++
OPC=-g

main: $(OBJ)
	$(COMP) $(OPC) $(OBJ) -o main
main.o: ../src/main.cpp ../include/tporo.h
	$(COMP) $(OPC) -c ../src/main.cpp
tporo.o: ../include/tporo.h ../lib/tporo.cpp
	$(COMP) $(OPC) -c ../lib/tporo.cpp
