/*
 * main.c
 *
 *  Created on: 1 de mar. de 2017
 *      Author: Javi
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funciones.h"

#define fichero "preguntas.txt"
#define TAMCADENA 100
#define NUMNIVELES 3


int main(void){

	PREGUNTA *aPreguntas[NUMNIVELES];
	int aNumPreguntasXNivel[NUMNIVELES];

	//Leemos el numero de preguntas por nivel
	leerNumVivelesFichero(aNumPreguntasXNivel);
	//Reservamos memoria en el array de arrays
	reservarMemoria(aNumPreguntasXNivel,aPreguntas);

	int opc = 1;
	do {
		mostrarMenuPrincipal();
		opc = cogerRespuestaNumerica();
		switch (opc) {
		case 1:
			Adminstracion(aNumPreguntasXNivel,aPreguntas);
			break;
		case 2: //Instrucciones
			mostrarInstrucciones();
			break;
		case 3: //marcador
			printf("Marcadores\n");
			break;
		case 4: //jugar
			printf("Jugando...\n");
			break;
		case 5:
			printf("\nSaliendo... Hasta la proxima!\n");
			break;
		default:
			printf("\nOpcion no valida.\n");
		}
	}while (opc < 1 && opc > 4);

	//pasamos al fichero las preguntas almacenadas
	escribirPreguntasFichero(aNumPreguntasXNivel,aPreguntas) ;

	return 0;
}
