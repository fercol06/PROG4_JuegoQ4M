/*
 * funciones.c
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


/******************** FUNCIONES ARRAY PRICIPAL *******************/
void reservarMemoria(int *aNumPreguntasXNivel, PREGUNTA **aPreguntas){
	int i;
	for(i=0;i<NUMNIVELES;i++){
		aPreguntas[i]=(PREGUNTA*)malloc(aNumPreguntasXNivel[i]*sizeof(PREGUNTA));
	}
}
void liberarMemoria(PREGUNTA **aPreguntas){
	int i;
	for(i=0;i<NUMNIVELES;i++){
		free(aPreguntas[i]);
	}
}
//Amplio la memoria del array dinamico con la memoria nueva y en el nivel que me dicen
void ampliarMemoria(int *aNumPreguntasXNivel, PREGUNTA **aPreguntas, int nivel){
	aPreguntas[nivel-1]=(PREGUNTA*)realloc(aPreguntas[nivel-1],(aNumPreguntasXNivel[nivel-1]+1)*sizeof(PREGUNTA));
	aNumPreguntasXNivel[nivel-1]++; //Añado que tengo otra pregunta
}
/******************** ! FUNCIONES ARRAY PRICIPAL *******************/

/******************** FUNCIONES FICHEROS *******************/
void leerNumVivelesFichero(int *aNumPreguntasXNivel) {
	FILE *pf;
	PREGUNTA p;
	int i;

	pf = fopen(fichero, "r");
	if (pf != (FILE*) NULL) {

		while (!feof(pf)){
			for(i=0;i<6;i++){
				//leemos 6 lineas que no nos interasan
				fgets(p.pregunta,TAMCADENA,pf);
			}
			fscanf(pf, "%d", &p.nivel);

			aNumPreguntasXNivel[p.nivel - 1]++;
		}

		fclose(pf);
	} else {
		printf("\nERROR! No se ha abierto el fichero");
	}
	//Visualizar numero de Preguntas por nivel
	for (i=0;i<NUMNIVELES;i++){
		printf("%d\n", aNumPreguntasXNivel[i]);
	}
}

void leerPreguntasFichero(int *aNumPreguntasXNivel, PREGUNTA **aPreguntas) {
	FILE *pf;
	PREGUNTA p;
	pf = fopen(fichero, "r");
	if (pf != (FILE*) NULL) {

		while(fgets(p.pregunta,TAMCADENA,pf) != EOF){ //Lee una línea y Mientras no lleguemos al final del fichero
			//Leemos todas las preguntas y respuestas
			fgets(p.respuesta1,TAMCADENA,pf);
			fgets(p.respuesta2,TAMCADENA,pf);
			fgets(p.respuesta3,TAMCADENA,pf);
			fgets(p.respuesta4,TAMCADENA,pf);
			fgets(p.respuestaOK,TAMCADENA,pf);
			fscanf(pf, "%d\n", &p.nivel);

			aPreguntas[p.nivel-1][aNumPreguntasXNivel[p.nivel-1]] = p;
			//Esto igual se puede quitra porque ya sabemos cunatas hay.
			//aNumPreguntasXNivel[p.nivel-1]++;
		}

		fclose(pf);
	} else {
		printf("\nERROR! No se ha abierto el fichero");
	}
}

void escribirPreguntasFichero(int *aNumPreguntasXNivel, PREGUNTA **aPreguntas) {
	FILE *pf;
	PREGUNTA p;
	int i=0, j=0;

	pf = fopen(fichero, "a");
	if (pf != (FILE*) NULL) {
		for(i=0;i<NUMNIVELES;i++){
			for(j=0;j<aNumPreguntasXNivel[i];j++){
				//???
				p.pregunta= aPreguntas[i][j].pregunta;
				p.respuesta1=aPreguntas[i][j].respuesta1;
				p.respuesta2=aPreguntas[i][j].respuesta2;
				p.respuesta3=aPreguntas[i][j].respuesta3;
				p.respuesta4=aPreguntas[i][j].respuesta4;
				p.respuestaOK=aPreguntas[i][j].respuestaOK;
				p.nivel=aPreguntas[i][j].nivel;

				fprintf(pf, "%s\n", p.pregunta);
				fprintf(pf, "%s\n", p.respuesta1);
				fprintf(pf, "%s\n", p.respuesta2);
				fprintf(pf, "%s\n", p.respuesta3);
				fprintf(pf, "%s\n", p.respuesta4);
				fprintf(pf, "%s\n", p.respuestaOK);
				fprintf(pf, "%d\n", &p.nivel);
			}
		}

		fclose(pf);
	} else {
		printf("\nERROR! No se ha podido abrir el fichero");
	}
}

/******************** ! FUNCIONES FICHEROS *******************/

/********************  FUNCIONES ARRAY *******************/
//Buscar pos
/*
int buscarPosicion(int *a, int i, int valorBuscado) {
	int pos, enc;
	enc = 0;
	pos = 0;
	while (!enc && pos < i) {
		if (a[pos] == valorBuscado) {
			enc = 1;
		} else {
			pos++;
		}
	}
	if (enc) {
		return pos;
	} else {
		return -1;
	}
}
//Funcion eliminar array
//DESPLAZAR IZQ
void eliminarPosicion(int *a, int *i, int pos) {
	int j;
	for (j = pos; j < *i - 1; j++) {
		a[j] = a[j + 1];
	}
	(*i)--;
}
//DESPLAZAR DRCHA
void eliminarPosicion(int *a, int i, int pos) {
	int j;
	for (j = i; j > pos; j++) {
		a[j] = a[j - 1];
	}
}
*/
/******************** ! FUNCIONES ARRAY *******************/

/********************  ADMINISTRACION *******************/

/*
char confirmacion() {
	char resp;
	do {
		menuConfirmacion();
		resp = cogerRespuestaChar();
		if (resp == 's' || resp == 'S' || resp == 'n' || resp == 'n') {

		} else {
			printf("Perdone, no le he entendido.\n");
			printf("Recuerda utilizar los caracteres 'S' para comfirmar y 'N' para Cancelar.\n");
		}
	} while (resp != 's' || resp != 'S' || resp != 'n' || resp != 'n');
	return resp;
}
*/

//Muestra toda la mecanica del panel de la administración.
void Adminstracion(int *aNumPreguntasXNivel, PREGUNTA **aPreguntas) {
	int opc, nivel;
	PREGUNTA p;
	do {
		mostrarMenuAdministracion();
		opc = cogerRespuestaNumerica();
		switch (opc) {
		case 1:			//1.- Editar Preguntas
			nivel = preguntarNivel();
			mostrarPreguntasNivel(nivel, aNumPreguntasXNivel,aPreguntas);
			//Seleccionar pregunta
			//pedir nuevos datos
			//Actualizar.
			break;
		case 2:			//2.- Crear pregunta

			break;
		case 3:			//3.- Borrar pregunta
						//preguntar nivel a visualizar
						//mostrar lista nivel
						//Seleccionar pregunta
						//Confirmacion
						//eliminar del array (Tenemos el indice en que esta porke es el mismo que la que selecciona)
			break;
		case 4:			//4.- Borrar todo
						//pedir confirmacion
						//Eliminar array./ Fichero
			break;
		case 5:
			printf("\nVolviendo atras!\n");
			break;
		default:
			printf("\nOpcion no valida.\n");
		}
	} while (opc < 1 && opc > 4);
}

/********************  FUNCIONES GENERICAS ADMINISTRACION *******************/
//Muestra los niveles, pide seleccionar el nivel, devuelve el nivel
int preguntarNivel() {
	int opc;
	int nivel;
	do {
		preguntarNivelaMostrar();
		opc = cogerRespuestaNumerica();
		switch (opc) {
		case 1: nivel = 0; break;
		case 2:	nivel = 1; break;
		case 3:	nivel = 2; break;
		default:
			printf("\nOpcion no valida.\n");
		}
	} while (opc < 1 && opc > 3);
	return nivel;
}

//Mostrar lista preguntas por nivel
void mostrarPreguntasNivel(int nivel, int *aNumPreguntasXNivel, PREGUNTA **aPreguntas ) { //PASAR NIVEL, ARRAY PREGUNTAS, ARRAY con NUMERO DE PREGUNTAS
	//en el array buscamos el nivel
	int i;
	printf("\n+-------------------------+\n");
	printf("|       Nivel: %d          |\n",nivel);
	printf("+-------------------------+\n");
	for(i=0; i<aNumPreguntasXNivel[nivel-1]; i++) {
		printf("%d.- %s ; %s\n", i+1, aPreguntas[nivel-1][i].pregunta,aPreguntas[nivel-1][i].respuestaOK ); // 1.- Pregunta ; RespuestaOK
	}
}

/******************** ! FUNCIONES GENERICAS ADMINISTRACION *******************/

//1.- Editar Preguntas
	void editarPregunta(int nivel) {

	}

//2.- Crear pregunta
	void crearPregunta(){//Necesito  los 2 arrays
		PREGUNTA p;
		p=pedirPregunta();
		//Añadir al array.
			//Reservar memoria nuevo
			//insertarlo al final (del nivel que corresponde)
	}

	void generarAleatoriamenteRespuesta(char *a, char *b, char *c, char *d, char *ok) {
		strcpy(a, ok);
		printf("\nIntroduce una respuesta incorrecta:");
		fflush(stdin);
		fgets(b, TAMCADENA, stdin);
		printf("\nIntroduce una respuesta incorrecta:");
		fflush(stdin);
		fgets(c, TAMCADENA, stdin);
		printf("\nIntroduce una respuesta incorrecta:");
		fflush(stdin);
		fgets(d, TAMCADENA, stdin);
	}

	PREGUNTA pedirPregunta() {
		PREGUNTA p;
		int aleatorio;
		printf("\n+-------------------------+\n");
		printf("|     Crear Pregunta      |\n");
		printf("+-------------------------+\n");
		printf("Introduce una pregunta:");
		fflush(stdin);
		fgets(p.pregunta, TAMCADENA, stdin);
		printf("\nIntroduce la respuesta correcta:");
		fflush(stdin);
		fgets(p.respuestaOK, TAMCADENA, stdin);

		aleatorio = rand() % 4; //Aleatorios entre 0,1,2,3
		switch (aleatorio) {
		case 0:
			generarAleatoriamenteRespuesta(p.respuesta1, p.respuesta2, p.respuesta3,
					p.respuesta4, p.respuestaOK);
			/*strcpy(p.respuesta1, p.respuestaOK);
			 printf("\nIntroduce una respuesta incorrecta:");
			 fflush(stdin);
			 fgets(p.respuesta2, TAMCADENA, stdin);
			 printf("\nIntroduce una respuesta incorrecta:");
			 fflush(stdin);
			 fgets(p.respuesta3, TAMCADENA, stdin);
			 printf("\nIntroduce una respuesta incorrecta:");
			 fflush(stdin);
			 fgets(p.respuesta4, TAMCADENA, stdin);*/
			break;
		case 1:
			generarAleatoriamenteRespuesta(p.respuesta2, p.respuesta1, p.respuesta3,
					p.respuesta4, p.respuestaOK);
			/*strcpy(p.respuesta2, p.respuestaOK);
			 printf("\nIntroduce una respuesta incorrecta:");
			 fflush(stdin);
			 fgets(p.respuesta1, TAMCADENA, stdin);
			 printf("\nIntroduce una respuesta incorrecta:");
			 fflush(stdin);
			 fgets(p.respuesta3, TAMCADENA, stdin);
			 printf("\nIntroduce una respuesta incorrecta:");
			 fflush(stdin);
			 fgets(p.respuesta4, TAMCADENA, stdin);*/
			break;
		case 2:
			generarAleatoriamenteRespuesta(p.respuesta3, p.respuesta1, p.respuesta2,
					p.respuesta4, p.respuestaOK);
			/*strcpy(p.respuesta3, p.respuestaOK);
			 printf("\nIntroduce una respuesta incorrecta:");
			 fflush(stdin);
			 fgets(p.respuesta1, TAMCADENA, stdin);
			 printf("\nIntroduce una respuesta incorrecta:");
			 fflush(stdin);
			 fgets(p.respuesta2, TAMCADENA, stdin);
			 printf("\nIntroduce una respuesta incorrecta:");
			 fflush(stdin);
			 fgets(p.respuesta4, TAMCADENA, stdin);*/
			break;
		case 3:
			generarAleatoriamenteRespuesta(p.respuesta4, p.respuesta1, p.respuesta2,
					p.respuesta3, p.respuestaOK);
			/*strcpy(p.respuesta4, p.respuestaOK);
			 printf("\nIntroduce una respuesta incorrecta:");
			 fflush(stdin);
			 fgets(p.respuesta1, TAMCADENA, stdin);
			 printf("\nIntroduce una respuesta incorrecta:");
			 fflush(stdin);
			 fgets(p.respuesta2, TAMCADENA, stdin);
			 printf("\nIntroduce una respuesta incorrecta:");
			 fflush(stdin);
			 fgets(p.respuesta3, TAMCADENA, stdin);*/
			break;
		}

		printf("\nIntroduce nivel:");
		scanf("%d", &p.nivel);
		return p;
	}

//3.- Borrar pregunta
//4.- Borrar todo

	/******************** FIN ADMINISTRACION *******************/

	/******************** COGER RESPUESTAS ECLIPSE  *******************/
	int cogerRespuestaNumerica() {
		int opc;
		fflush( stdin);
		scanf("%d", &opc);
		return opc;
	}
	char cogerRespuestaChar() {
		char opc;
		fflush( stdin);
		scanf("%c", &opc);
		return opc;
	}
	/******************** FIN COGER RESPUESTAS ECLIPSE  *******************/

	/******************** MENUS VISUALES *******************/
	void mostrarMenuPrincipal() {
		printf("\n+-------------------------+\n");
		printf("|    Questions4Million    |\n");
		printf("+-------------------------+\n");
		printf("+-------------------------+\n");
		printf("| 1.- Administrar         |\n");
		printf("| 2.- Instrucciones       |\n");
		printf("| 3.- Marcadores          |\n");
		printf("| 4.- Jugar               |\n");
		printf("| 5.- Salir               |\n");
		printf("+-------------------------+\n");
		printf("Seleccione una opcion: ");
	}

	void mostrarMenuAdministracion() {
		printf("\n+-------------------------+\n");
		printf("|     Administracion:     |\n");
		printf("+-------------------------+\n");
		printf("+-------------------------+\n");
		printf("| 1.- Editar pregunta     |\n");
		printf("| 2.- Crear pregunta      |\n");
		printf("| 3.- Borrar pregunta     |\n");
		printf("| 4.- Borrar todo         |\n");
		printf("| 5.- Atras               |\n");
		printf("+-------------------------+\n");
		printf("Seleccione una opcion: ");
	}

	void preguntarNivelaMostrar() {
		printf("\n+-------------------------+\n");
		printf("|         Niveles:        |\n");
		printf("+-------------------------+\n");
		printf("+-------------------------+\n");
		printf("| 1.- Facil               |\n");
		printf("| 2.- Medio               |\n");
		printf("| 3.- Dificil             |\n");
		printf("+-------------------------+\n");
		printf("Seleccione una opcion: ");
	}

	void menuConfirmacion() {
		printf("\n+---------------------------------------------------+\n");
		printf("|                   Confirmacion:                   |\n");
		printf("+---------------------------------------------------+\n");
		printf("+---------------------------------------------------+\n");
		printf("¿Esta seguro que desea reaizar esta accion? (S/N): ");
	}

	void pedirContrasenia() {
		printf("\n+------------------------------+\n");
		printf("|          Contrasenya:        |\n");
		printf("+------------------------------+\n");
		printf("+------------------------------+\n");
		printf("Introduzca la contrasenya: ");
	}

	/******************** FIN MENUS VISUALES  *******************/


	/******************** INSTRUCCIONES *******************/

	void mostrarInstrucciones(){
		printf("\n+----------------------------------------------------------+\n");
		printf("|                   Instrucciones Q4M:                     |\n");
		printf("+----------------------------------------------------------+\n");
		printf("+----------------------------------------------------------+\n");
		printf("| Bienvenido a Questions4Millions!                         |\n");
		printf("| Q4M es un juego de preguntas y respuestas donde deberás  |\n");
		printf("| contestar a todas las preguntas de forma correcta y no   |\n");
		printf("| dejar que tu openente u openentes te ganen.              |\n");
		printf("| Tu objetivo será contestár más preguntas que tus rivales |\n");
		printf("| y llevarte el gran premio.                               |\n");
		printf("+----------------------------------------------------------+\n");
		printf("| Mucha suerte!                                            |\n");
		printf("+----------------------------------------------------------+\n");
	}

	/******************** ! INSTRUCCIONES *******************/
