/*
 * Menu.cpp
 *
 *  Created on: 3 may. 2021
 *      Author: David
 */

#include "Menu.h"

bool ingresarColumna(Tablero juego, char fichaDeJugador){

	int columna,fila;


	do{

		std::cout<<"Ingrese numero de columna: ";
		std::cin>>columna;
		std::cout<<std::endl;

	}while(columna > COLUMNA || columna < 0 || columnaCompleta(juego, columna-1) == true);

	fila = insertarFicha(juego, columna, fichaDeJugador);

	//std::cout<<"fila:"<<fila<<" columna:"<<columna-1<<std::endl;

	return ganador(juego, fila, columna-1, fichaDeJugador);

}

bool columnaCompleta(Tablero juego, int columna){

	bool lleno = false;

	if(juego[0][columna] != '*'){
		std::cout<<"Columna llena, elija otra"<<std::endl;
		lleno = true;
	}

	return lleno;
}

bool ganador(Tablero juego,int fila, int columna, char ficha){
	bool ganador =  false;

	if(revisarColumna(juego, fila, columna, ficha )== true){
		ganador = true;
	}else if(revisarFila(juego, fila, columna, ficha )== true){
		ganador = true;
	}else if(revisarDiagonalCreciente(juego, fila, columna, ficha)== true){
		ganador = true;
	}else if(revisarDiagonalDecreciente(juego, fila, columna, ficha)== true){
		ganador = true;
	}
	return ganador;
}

void jugar(Tablero juego){

	int contadorDePartidas = 0;
	bool ganoJugador1 = false;
	bool ganoJugador2 = false;

	std::cout<<"      -- CUATRO EN LÍNEA V1.0 --"<<std::endl;
	std::cout<<std::endl;
	std::cout<<std::endl;

	iniciarTablero(juego);
	mostrarTablero(juego);
	escribirTablero(juego);

	while(contadorDePartidas < (COLUMNA*FILA) && ganoJugador1 == false && ganoJugador2 == false ){

		if(contadorDePartidas%2 == 0){
			std::cout<<std::endl;
			std::cout<<"Turno jugador1 (O)"<<std::endl;
			std::cout<<std::endl;
			ganoJugador1 = ingresarColumna(juego, JUGADOR1);

		}else{
			std::cout<<std::endl;
			std::cout<<"Turno jugador2 (X)"<<std::endl;
			std::cout<<std::endl;
			ganoJugador2 = ingresarColumna(juego, JUGADOR2);
		}

		contadorDePartidas++;
		mostrarTablero(juego);
		escribirTablero(juego);
	}

	if(ganoJugador1 == true){

		std::cout<<std::endl;
		std::cout<<" GANO EL JUGADOR 1, FICHA: "<<JUGADOR1<<std::endl;
		std::cout<<std::endl;

	}else if(ganoJugador2 == true){
		std::cout<<std::endl;
		std::cout<<" GANO EL JUGADOR 2, FICHA: "<<JUGADOR2<<std::endl;
		std::cout<<std::endl;
	}

}


