/*
 * CuatroEnFila.cpp
 *
 *  Created on: 20 abr. 2021
 *      Author: David
 *
 */
#include "CuatroEnFila.h"

void iniciarTablero(Tablero juego){

	for(int i = 0;i<FILA;i++){

		for(int j = 0;j<COLUMNA;j++){
			juego [i][j] = '*';
		}

	}


}

void mostrarTablero(Tablero juego){

	for(int i = 0;i<FILA;i++){

			for(int j = 0;j<COLUMNA;j++){
				std::cout<<" "<<juego [i][j]<<" ";
			}
			std::cout<<std::endl;
	}

	std::cout<<" 1  2  3  4  5  6  7  8  9  10"<<std::endl;

}

int insertarFicha(Tablero juego, int columna, char fichaDeJugador){

	int fila = 9;
	bool insertado = false;

	do{

		if(juego [fila][columna-1] == '*'){

			juego [fila][columna-1] = fichaDeJugador;

			insertado = true;

		}

		fila--;

	}while(insertado == false && fila >= 0);

	return fila+1;
}

bool revisarColumna(Tablero juego,int fila, int columna, char ficha){

	int contadorDeFichas = 0;
	int aux = 0;
	int inferiorColumna = fila;

	while(aux < 4 && inferiorColumna < COLUMNA ){



		if(juego[inferiorColumna][columna] == ficha){

			contadorDeFichas++;

		}

		inferiorColumna++;
		aux++;

	}

	return mensajeGanador(contadorDeFichas, ficha);
}

bool revisarFila(Tablero juego,int fila, int columna, char ficha){

	int contadorDeFichas = 0;
	int izquierdaFila = columna;
	int derechaFila = columna+1;
	int aux = 0;

	while(aux < 4 && izquierdaFila >= 0){

		if(juego [fila][izquierdaFila] == ficha && contadorDeFichas < 4){

			contadorDeFichas++;

		}

		izquierdaFila--;
		aux++;

	}

	aux = 0;

	while(aux < 3 &&  derechaFila >= 0 && contadorDeFichas <4){

		if(juego [fila][derechaFila] == ficha && contadorDeFichas < 4){

			contadorDeFichas++;

		}

		derechaFila++;
		aux++;

	}

	return mensajeGanador(contadorDeFichas, ficha);

}

bool revisarDiagonalCreciente(Tablero juego,int fila, int columna, char ficha){

	int filaActual = fila;
	int columnaActual = columna;
	int contadorDeFichas = 0;
	int aux = 0;

	while(aux < 4 && (filaActual >= 0 || columnaActual >= 0)){

		if(juego [filaActual][columnaActual] == ficha && contadorDeFichas < 4){

			contadorDeFichas++;

		}
		filaActual--;
		columnaActual++;
		aux++;

	}

	filaActual = fila + 1;
	columnaActual = columna - 1;
	aux = 0;

	while(aux < 3 && (filaActual >= 0 || columnaActual >= 0)){

			if(juego [filaActual][columnaActual] == ficha && contadorDeFichas < 4){

				contadorDeFichas++;

			}
			filaActual++;
			columnaActual--;
			aux++;

		}

	return mensajeGanador(contadorDeFichas, ficha);
}

bool revisarDiagonalDecreciente(Tablero juego,int fila, int columna, char ficha){

	int filaActual = fila;
	int columnaActual = columna;
	int contadorDeFichas = 0;
	int aux = 0;

	while(aux < 4 && (filaActual >= 0 || columnaActual >= 0) ){

		if(juego [filaActual][columnaActual] == ficha && contadorDeFichas < 4){

			contadorDeFichas++;

		}
		filaActual--;
		columnaActual--;

		aux++;

	}

	filaActual = fila + 1;
	columnaActual = columna + 1;
	aux = 0;

	while(aux < 3 && (filaActual < FILA || columnaActual < COLUMNA) ){

		if(juego [filaActual][columnaActual] == ficha && contadorDeFichas < 4){

			contadorDeFichas++;

		}
		filaActual++;
		columnaActual++;
		aux++;
	}

	return mensajeGanador(contadorDeFichas, ficha);

}

bool mensajeGanador(int contadorDeFichas, char ficha){

	bool ganador = false;

	if(contadorDeFichas == 4){

		ganador = true;

	}
	return ganador;
}



