# ARQUIVO DE SCRIPT MAKEFILE 
# SIMULADOR DE MEMORIA VIRTUAL 

CC = g++
INC = ./include
SRC = ./src
OBJ = ./build
BIN = ./bin
# nome do executáveL
PROG = $(BIN)/simulador
CPPFLAGSGTK = `pkg-config --cflags gtkmm-3.0` -Wall -std=c++11 -I$(INC)
LDFLAGSGTK = `pkg-config --libs gtkmm-3.0`
OBJTS = $(OBJ)/principal.o $(OBJ)/JanelaPrincipal.o $(OBJ)/simulador.o

all: mkdirs $(PROG)

mkdirs:
	mkdir -p $(BIN)
	mkdir -p $(OBJ)

$(PROG): $(OBJTS)
	$(CC) -o $(PROG) $(OBJTS) $(LDFLAGSGTK)

$(OBJ)/simulador.o: $(SRC)/simulador.cpp
	$(CC) $(CPPFLAGSGTK) -c $(SRC)/simulador.cpp -o $(OBJ)/simulador.o

$(OBJ)/JanelaPrincipal.o: $(SRC)/JanelaPrincipal.cpp $(INC)/JanelaPrincipal.h
	$(CC) $(CPPFLAGSGTK) -c $(SRC)/JanelaPrincipal.cpp -o $(OBJ)/JanelaPrincipal.o

$(OBJ)/principal.o: $(SRC)/principal.cpp $(INC)/principal.h
	$(CC) $(CPPFLAGS) -c $(SRC)/principal.cpp -o $(OBJ)/principal.o

clean: 
	rm -f $(BIN)/*
	rm -f $(OBJ)/*

debug: $(PROG)
	gdb $(PROG)

run:
	$(PROG) $(PAR1) $(PAR2) $(PAR3) $(PAR4) 