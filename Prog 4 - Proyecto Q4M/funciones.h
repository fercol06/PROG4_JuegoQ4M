/*
 * funciones.h
 *
 *  Created on: 1 de mar. de 2017
 *      Author: Javi
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

typedef struct{
	int cod;
	char pregunta [100];
	char respuesta1[100];
	char respuesta2[100];
	char respuesta3[100];
	char respuesta4[100];
	char respuestaOK[100];
	int nivel;
}PREGUNTA;


/******************** FUNCIONES ARRAY PRICIPAL *******************/
void reservarMemoria(int *aNumPreguntasXNivel, PREGUNTA **aPreguntas);
void liberarMemoria(PREGUNTA **aPreguntas);
void ampliarMemoria(int *aNumPreguntasXNivel, PREGUNTA **aPreguntas, int nivel);
/******************** ! FUNCIONES ARRAY PRICIPAL *******************/

/********************  ADMINISTRACION *******************/
void Adminstracion(int *aNumPreguntasXNivel, PREGUNTA **aPreguntas );


/********************  FUNCIONES GENERICAS ADMINISTRACION *******************/
int preguntarNivel();
void mostrarPreguntasNivel(int nivel, int *aNumPreguntasXNivel, PREGUNTA **aPreguntas );
/******************** ! FUNCIONES GENERICAS ADMINISTRACION *******************/


/******************** FIN ADMINISTRACION *******************/

/******************** FUNCIONES FICHEROS *******************/
void leerNumVivelesFichero(int *aNumPreguntasXNivel);
void leerPreguntasFichero(int *aNumPreguntasXNivel, PREGUNTA **aPreguntas);
void escribirPreguntasFichero(int *aNumPreguntasXNivel, PREGUNTA **aPreguntas);
/******************** ! FUNCIONES FICHEROS *******************/

char confirmacion();




/******************** COGER RESPUESTAS ECLIPSE  *******************/
int cogerRespuestaNumerica();
char cogerRespuestaChar();
/******************** ! COGER RESPUESTAS ECLIPSE  *******************/

/******************** MENUS VISUALES *******************/
void mostrarMenuPrincipal();
void mostrarMenuAdministracion();
void preguntarNivelaMostrar();
void menuConfirmacion();
void pedirContrasenia();
/******************** ! MENUS VISUALES  *******************/
/******************** INSTRUCCIONES *******************/
void mostrarInstrucciones();
/******************** ! INSTRUCCIONES *******************/

#endif /* FUNCIONES_H_ */
