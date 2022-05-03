/*
 * mensaje.h
 *
 *  Autor: Manuel Cobos Solís
 *  Fecha: 28-04-2022
 *  Corrreo: mcobosso@unex.es
 */

#ifndef MENSAJE_H_
#define MENSAJE_H_

#include <iostream>

using namespace std;

class mensaje {
	int identificador;
	string texto;
	string autorMensaje;

public:
	mensaje();
	mensaje(int identificador, string texto, string autor);
	int  obtenerIdentificador();
	string obtenerTexto();
	string obtenerAutorMensaje();
	void ponerIdentificador(int id);
	void ponerTexto(string txt);
	void ponerAutorMensaje(string autor);
	void mostrarMensaje();

	~mensaje();
};

#endif /* MENSAJE_H_ */
