/*
 * Escritura.cpp
 *
 *  Created on: 4 may. 2021
 *      Author: David
 */


#include "Escritura.h"


void escribirTablero(Tablero juego){

	std::string rutaSalida = "escrituraTablero.txt";
	std::ofstream salida;

	salida.open(rutaSalida.c_str());

	salida<<std::endl;

	for(int i = 0;i<FILA;i++){

			for(int j = 0;j<COLUMNA;j++){
				salida<<" "<<juego [i][j]<<" ";
			}
			salida<<std::endl;
	}

	salida<<" 1  2  3  4  5  6  7  8  9  10"<<std::endl;

	salida<<std::endl;

	salida.close();

}

