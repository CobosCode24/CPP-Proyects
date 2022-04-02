
// Autor: Manuel Cobos Solís
// Correo: mcobosso@alumnos.unex.es
// Fecha: 02/04/2022
// Descripción:

#ifndef RSV_H_
#define RSV_H_

#include <fstream>
#include <iostream>
#include "lpi.h"
#include "Conductor.h"
#include "Viaje.h"
#include "cola.h"
using namespace std;



class RSV {
	LPI<Viaje *> *lv;
	LPI<Conductor *> *lc;

public:
	RSV();

	/*
	 * PRE: !buscarConductor()
	 * POST:
	 * COMPLEJIDAD: O(n^2)
	 * EXPLICACION: Lee los conductores del archivo 'conductores.csv' y vuelva la informacion en el RSV.
	 * */
	void cargarConductores();

	/*
	 * PRE: (puntuacion >= 0) && (puntuacion <= 10)
	 * POST:
	 * COMPLEJIDAD: o(n^2)
	 * EXPLICACION: Lee las opiniones del archivo 'valoraciones.csv' y vuelca la información en el RSV
	 * */
	void cargarValoraciones();

	/*
	 * PRE:
	 * POST:
	 * COMPLEJIDAD: O(n^2)
	 * EXPLICACION: Lee los viajes del archivo 'viajes.csv' y vuelca la informacion en el RSV.
	 * */
	void cargarViajes();


	// OPCIONES DEL PROGRAMA

	/*
	 * PRE:
	 * POST:
	 * COMPLEJIDAD: O(n)
	 * EXPLICACION: Inserta un opinión a un Conductor.
	 * */
	void insertaOpinion(Opinion* opinion, string identificador);

	/*
	 * PRE:
	 * POST:
	 * COMPLEJIDAD: O(n)
	 * EXPLICACION: Inserta un conductor al RSV.
	 * */
	void insertarConductor(Conductor* c);

	/*
	 * PRE:
	 * POST:
	 * COMPLEJIDAD: O(n)
	 * EXPLICACION: Pone una valoracion a un conductor.
	 * */
	void valorarConductor(string identificador, Opinion* op);

	/*
	 * PRE:
	 * POST:
	 * COMPLEJIDAD: O(n)
	 * EXPLICACION: Inserta un viaje en el RSV.
	 * */
	void insertarViaje(Viaje* v);

	/*
	 * PRE:
	 * POST:
	 * COMPLEJIDAD: O(n^2)
	 * EXPLICACION: Muestra todos los conductores del RSV.
	 * */
	void mostrarConductores();

	/*
	 * PRE:
	 * POST:
	 * COMPLEJIDAD: O(n)
	 * EXPLICACION: Muestra todos los viajes del RSV
	 * */
	void mostrarViajes();

	/*
	 * PRE:
	 * POST:
	 * COMPLEJIDAD: O(n^3)
	 * EXPLICACION: Muetsra todos los viajes junto con el conductor que los realizará.
	 * */
	void mostrarTodo();

	/*
	 * PRE: buscarConductor() = true
	 * POST: Muestra un conductor c.
	 * COMPLEJIDAD: O(n)
	 * EXPLICACION: Busca un conductor en el RSV dado un identificador.
	 * */
	bool  buscarConductor(string id, Conductor* &c);

	/*
	 * PRE: ((respuesta = "s") || (respuesta = "n"))
	 * POST:
	 * COMPLEJIDAD: O(n^2)
	 * EXPLICACION: Elimina un conductor del RSV
	 * */
	void eliminarConductor(string identificador);

	/*
	 * PRE:
	 * POST:
	 * COMPLEJIDAD: O(n)
	 * EXPLICACION: Elimina todos los viajes que estan asociados a un conductor.
	 * */
	void eliminarViajesConductor(string identificadorDado);

	/*
	 * PRE:
	 * POST:
	 * COMPLEJIDAD: O(n^2)
	 * EXPLICACION: Crea una nueva cola de viajes, y posteriormente los muestra.
	 * */
	void colaViajes(string origen, string destino, Cola<Viaje*> *&c);

	~RSV();
};

#endif /* RSV_H_ */
