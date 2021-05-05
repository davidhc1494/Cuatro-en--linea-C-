/*
 * Menu.h
 *
 *  Created on: 3 may. 2021
 *      Author: David
 */

#ifndef MENU_H_
#define MENU_H_
#include "CuatroEnFila.h"
#include "Escritura.h"

bool ingresarColumna(Tablero juego, char fichaDeJugador);

bool columnaCompleta(Tablero juego, int columna);

bool ganador(Tablero juego,int fila, int columna, char ficha);

void jugar(Tablero juego);





#endif /* MENU_H_ */
