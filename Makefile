# ARQUIVO DE SCRIPT MAKEFILE 
# SIMULADOR DE MEMORIA VIRTUAL 

CC = g++
INC = ./include
SRC = ./src
OBJ = ./build
BIN = ./bin
# nome do executáveL
PROG = $(BIN)/simulador
CPPFLAGS = -Wall -pedantic -std=c++11 -I$(INC)
OBJTS = $(OBJ)/memoria.o $(OBJ)/algoritmosGeradorEnd.o $(OBJ)/simulador.o 

all: mkdirs $(PROG)

mkdirs:
	mkdir -p $(BIN)
	mkdir -p $(OBJ)

$(PROG): $(OBJTS)
	$(CC) $(CPPFLAGS) -o $(PROG) $(OBJTS) 

$(OBJ)/memoria.o: $(SRC)/memoria.cpp $(INC)/memoria.h
	$(CC) $(CPPFLAGS) -c $(SRC)/memoria.cpp -o $(OBJ)/memoria.o

$(OBJ)/algoritmosGeradorEnd.o: $(SRC)/algoritmosGeradorEnd.cpp $(INC)/algoritmosGeradorEnd.h
		$(CC) $(CPPFLAGS) -c $(SRC)/algoritmosGeradorEnd.cpp -o $(OBJ)/algoritmosGeradorEnd.o

$(OBJ)/simulador.o: $(SRC)/simulador.cpp
	$(CC) $(CPPFLAGS) -c $(SRC)/simulador.cpp -o $(OBJ)/simulador.o

clean: 
	rm -f $(BIN)/*
	rm -f $(OBJ)/*

debug: $(PROG)
	gdb $(PROG)

run:
	$(PROG) $(PAR1) $(PAR2) $(PAR3) $(PAR4) 