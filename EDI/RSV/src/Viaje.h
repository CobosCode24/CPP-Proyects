
// Autor: Manuel Cobos Solís
// Correo: mcobosso@alumnos.unex.es
// Fecha: 02/04/2022
// Descripción: CLase Viaje.

#ifndef VIAJE_H_
#define VIAJE_H_

#include <iostream>
using namespace std;



class Viaje {
private:
	string ciudadOrigen;
	string ciudadDestino;
	int horaSalida;
	string identificador;


public:
	Viaje();

	/*
	 * PRE:
	 * POST:
	 * COMPLEJIDAD:  O(1)
	 * EXPLICACION: Crea un nuevo viaje.
	 * */
	Viaje(string ciudadOrigen,string ciudadDestino, int horaSalida, string identificador);

	/*
	 * PRE: if(viaje1 > viaje2)
	 * POST: return true.
	 * COMPLEJIDAD:  O(1)
	 * EXPLICACION: Compara si un viaje es mayor que otro. Se utiliza para la inserción en orden.
	 * */
	bool operator> (const Viaje &v);

	/*
	 * PRE:
	 * POST:
	 * COMPLEJIDAD:  O(1)
	 * EXPLICACION: Pone la ciudad de origen a un viaje.
	 * */
	void ponerCiudadOrigen(string ciudadOrigenDado);

	/*
	 * PRE:
	 * POST:
	 * COMPLEJIDAD: O(1)
	 * EXPLICACION: Pone la ciudad de destino a un viaje.
	 * */
	void ponerCuidadDestino(string ciudadDestinoDado);

	/*
	 * PRE:
	 * POST:
	 * COMPLEJIDAD: O(1)
	 * EXPLICACION: Pone la hora de salida de un viaje.
	 * */
	void ponerHoraSalida(int horaSalidaDada);

	/*
	 * PRE:
	 * POST:
	 * COMPLEJIDAD:O(1)
	 * EXPLICACION: Pone el identificador de un conductor a un viaje, con lo cual ese viaje
	 * 				queda asignado a ese Conductor.
	 * */
	void ponerIdentificador(string idDado);

	/*
	 * PRE:
	 * POST:
	 * COMPLEJIDAD:O(1)
	 * EXPLICACION: Obtiene la ciudad de Origen donde comenzará el viaje.
	 * */
	string obtenerCiudadOrigen();

	/*
	 * PRE:
	 * POST:
	 * COMPLEJIDAD:O(1)
	 * EXPLICACION: Obtiene la ciudad de destino donde terminará el viaje.
	 * */
	string obtenerCiudadDestino();

	/*
	 * PRE:
	 * POST:
	 * COMPLEJIDAD:O(1)
	 * EXPLICACION: Obtiene la hora de salida de un viaje.
	 * */
	int obtenerHoraSalida();

	/*
	 * PRE:
	 * POST:
	 * COMPLEJIDAD:O(1)
	 * EXPLICACION: Obtiene el identificador del Conductor asociado a un viaje.
	 * */
	string obtenerIdentificador();

	/*
	 * PRE:
	 * POST:
	 * COMPLEJIDAD:O(1)
	 * EXPLICACION: Muestra la informacion de un viaje, sin incluir el identificador del Conductor.
	 * */
	void mostrarViaje();

	/*
	 * PRE:
	 * POST:
	 * COMPLEJIDAD:O(1)
	 * EXPLICACION: Muestra la informacion de un viaje, incluyendo el identificador del Conductor.
	 * */
	void mostrarViajeConID();



	~Viaje();
};

#endif /* VIAJE_H_ */
