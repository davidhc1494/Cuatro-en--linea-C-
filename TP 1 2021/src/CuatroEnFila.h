/*
 * cuantroEnFila.h
 *
 *  Created on: 20 abr. 2021
 *      Author: David
 */

#ifndef CUATROENFILA_H_
#define CUATROENFILA_H_

#include <iostream>

const int COLUMNA = 10;
const int FILA = 10;
const char JUGADOR1 = 'O';
const char JUGADOR2 = 'X';

typedef char Tablero[FILA][COLUMNA];

void iniciarTablero(Tablero juego);

void mostrarTablero(Tablero juego);

int insertarFicha(Tablero juego, int columna, char fichaDeJugador);

bool revisarColumna(Tablero juego,int fila, int columna, char ficha);

bool revisarFila(Tablero juego,int fila, int columna, char ficha);

bool revisarDiagonalCreciente(Tablero juego,int fila, int columna, char ficha);

bool revisarDiagonalDecreciente(Tablero juego,int fila, int columna, char ficha);

bool mensajeGanador(int contadorDeFichas, char ficha);

#endif /* CUATROENFILA_H_ */
