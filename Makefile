# ARQUIVO DE SCRIPT MAKEFILE 
# SIMULADOR DE MEMORIA VIRTUAL 

CC = g++
INC = ./include
SRC = ./src
OBJ = ./build
BIN = ./bin
PROG = $(BIN)/simulador
PROGGER = $(BIN)/gerador
CPPFLAGSGTK = `pkg-config --cflags gtkmm-3.0` -std=c++11 -I$(INC)
LDFLAGSGTK = `pkg-config --libs gtkmm-3.0`
CPPFLAGS = -Wall -pedantic -std=c++11 -I$(INC)
OBJTS = $(OBJ)/memoria.o $(OBJ)/converterHexaToDecimal.o $(OBJ)/simulador.o $(OBJ)/JanelaPrincipal.o
OBJTSGER = $(OBJ)/algoritmosGeradorEnd.o

all: mkdirs $(PROG) $(PROGGER)

mkdirs:
	mkdir -p $(BIN)
	mkdir -p $(OBJ)

$(PROG): $(OBJTS)
	$(CC) $(CPPFLAGS) -o $(PROG) $(OBJTS) $(LDFLAGSGTK)

$(PROGGER): $(OBJTSGER)
	$(CC) $(CPPFLAGS) -o $(PROGGER) $(OBJTSGER) 

$(OBJ)/memoria.o: $(SRC)/memoria.cpp $(INC)/memoria.h
	$(CC) $(CPPFLAGS) -c $(SRC)/memoria.cpp -o $(OBJ)/memoria.o

$(OBJ)/converterHexaToDecimal.o: $(SRC)/converterHexaToDecimal.cpp $(INC)/converterHexaToDecimal.h
	$(CC) $(CPPFLAGS) -c $(SRC)/converterHexaToDecimal.cpp -o $(OBJ)/converterHexaToDecimal.o

$(OBJ)/simulador.o: $(SRC)/simulador.cpp
	$(CC) $(CPPFLAGSGTK) -c $(SRC)/simulador.cpp -o $(OBJ)/simulador.o

$(OBJ)/JanelaPrincipal.o: $(SRC)/JanelaPrincipal.cpp $(INC)/JanelaPrincipal.h
	$(CC) $(CPPFLAGSGTK) -c $(SRC)/JanelaPrincipal.cpp -o $(OBJ)/JanelaPrincipal.o

$(OBJ)/algoritmosGeradorEnd.o: $(SRC)/algoritmosGeradorEnd.cpp $(INC)/algoritmosGeradorEnd.h
		$(CC) $(CPPFLAGS) -c $(SRC)/algoritmosGeradorEnd.cpp -o $(OBJ)/algoritmosGeradorEnd.o

clean: 
	rm -f $(BIN)/*
	rm -f $(OBJ)/*

debug: $(PROG)
	gdb $(PROG)

run:
	$(PROG) $(PAR1) $(PAR2) $(PAR3) $(PAR4)
runGer:
	$(PROGGER) $(PAR1) $(PAR2) $(PAR3)