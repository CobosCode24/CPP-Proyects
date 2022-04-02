
// Autor: Manuel Cobos Solís
// Correo: mcobosso@alumnos.unex.es
// Fecha: 02/04/2022
// Descripción: Clase Conductor.

#ifndef CONDUCTOR_H_
#define CONDUCTOR_H_

#include <iostream>
#include "Opinion.h"
#include "pila.h"
using namespace std;


class Conductor {
private:
	string identificador;
	string nombre;
	int edad;
	int anioAlta;
	string marcaModeloCoche;
	Pila<Opinion*> *opinionesUsuarios;

public:
	Conductor();
	/*
	 * PRE:
	 * POST:
	 * COMPLEJIDAD:  O(1)
	 * EXPLICACION: Crea un nuevo Conductor.
	 * */
	Conductor(string identificador, string nombre, int edad, int anioAlta, string marcaModeloCoche);

	/*
	 * PRE:
	 * POST:
	 * COMPLEJIDAD:  O(1)
	 * EXPLICACION: Pone un identificador único a un Conductor.
	 * */
	void ponerIdentificador(string identificadorDado);

	/*
	 * PRE:
	 * POST:
	 * COMPLEJIDAD:  O(1)
	 * EXPLICACION: Pone un nombre al Conductor.
	 * */
	void ponerNombre(string nombreDado);

	/*
	 * PRE:
	 * POST:
	 * COMPLEJIDAD:  O(1)
	 * EXPLICACION: Pone una edad al conductor.
	 * */
	void ponerEdad(int edadDada);

	/*
	 * PRE:
	 * POST:
	 * COMPLEJIDAD:  O(1)
	 * EXPLICACION: Pone el año del alta en el que se añadió el conductor a la RSV.
	 * */
	void ponerAnio(int anioDado);

	/*
	 * PRE:
	 * POST:
	 * COMPLEJIDAD:  O(1)
	 * EXPLICACION: Pone la marca o modelo del coche que utilizará.
	 * */
	void ponerMarcaModeloCoche(string marcaModeloCocheDado);

	/*
	 * PRE:
	 * POST:
	 * COMPLEJIDAD:  O(1).
	 * EXPLICACION: Pone una nueva opinion a un conductor. Si este tiene mas de una opinion, estas se irán 'apilando', mostrando
	 * 				así la primera la mas reciente.
	 * */
	void ponerOpinion(Opinion* o);


	/*
	 * PRE:
	 * POST:
	 * COMPLEJIDAD:  O(1)
	 * EXPLICACION: Obtiene el identificador de un Conductor.
	 * */
	string obtenerIdentificador();

	/*
	 * PRE:
	 * POST:
	 * COMPLEJIDAD:  O(1)
	 * EXPLICACION: Obtiene el nombre de un Conductor.
	 * */
	string obtenerNombre();

	/*
	 * PRE:
	 * POST:
	 * COMPLEJIDAD:  O(1)
	 * EXPLICACION: Obtiene la edad de un Conductor.
	 * */
	int    obtenerEdad();

	/*
	 * PRE:
	 * POST:
	 * COMPLEJIDAD:  O(1)
	 * EXPLICACION: Obtiene el año de alta en el que se dio en el RSV.
	 * */
	int    obtenerAnio();

	/*
	 * PRE:
	 * POST:
	 * COMPLEJIDAD:  O(1)
	 * EXPLICACION: Obtiene el modelo o marca de coche que el conductor utiliza.
	 * */
	string obtenerMarcaModeloCoche();

	/*
	 * PRE:
	 * POST:
	 * COMPLEJIDAD:  O(n^2)
	 * EXPLICACION: Obtiene las opiniones del conductor.
	 * */
	void   obtenerOpinionesUsuario();

	/*
	 * PRE:
	 * POST:
	 * COMPLEJIDAD:  O(n^2)
	 * EXPLICACION: Obtiene la media de las valoraciones de un Conductor.
	 * */
	void   obtenerMediaValoraciones();


	/*
	 * PRE:
	 * POST:
	 * COMPLEJIDAD: O(n)
	 * EXPLICACION: Muestra toda la informacion del Conductor, incluyendo sus opiniones.
	 * */
	void mostrarConductor();

	/*
	 * PRE:
	 * POST:
	 * COMPLEJIDAD:  O(n)
	 * EXPLICACION: Elimina las opiniones de un determinado Conductor.
	 * */
	void eliminarPilaOpiniones();


	 ~Conductor();
};

#endif /* CONDUCTOR_H_ */
