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
OBJTS = $(OBJ)/principal.o $(OBJ)/simulador.o

all: mkdirs $(PROG)

mkdirs:
	mkdir -p $(BIN)
	mkdir -p $(OBJ)

$(PROG): $(OBJTS)
	$(CC) $(CPPFLAGS) -o $(PROG) $(OBJTS) 

$(OBJ)/principal.o: $(SRC)/principal.cpp $(INC)/principal.h
	$(CC) $(CPPFLAGS) -c $(SRC)/principal.cpp -o $(OBJ)/principal.o

$(OBJ)/simulador.o: $(SRC)/simulador.cpp
	$(CC) $(CPPFLAGS) -c $(SRC)/simulador.cpp -o $(OBJ)/simulador.o

clean: 
	rm -f $(BIN)/*
	rm -f $(OBJ)/*

debug: $(PROG)
	gdb $(PROG)

run:
	$(PROG) $(PAR1) $(PAR2) $(PAR3) $(PAR4) 