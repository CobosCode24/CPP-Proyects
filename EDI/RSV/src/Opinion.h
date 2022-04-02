
// Autor: Manuel Cobos Solís
// Correo: mcobosso@alumnos.unex.es
// Fecha: 02/04/2022
// Descripción: Clase Opinion.

#ifndef OPINION_H_
#define OPINION_H_

#include <iostream>
using namespace std;


class Opinion {
private:
	int valoracionNumerica;
	string opinion;

public:
	Opinion();

	/*
	 * PRE:
	 * POST:
	 * COMPLEJIDAD: O(1)
	 * EXPLICACION: CRea una nueva opinión a un Conductor.
	 * */
	Opinion(int valoracionNumerica, string opinion);


	/*
	 * PRE:
	 * POST:
	 * COMPLEJIDAD: O(1)
	 * EXPLICACION: Pone una valoración del 0 al 10 al Conductor, siendo 0 fatal y 10 excelente.
	 * */
	void ponerValoracionNumerica(int valoracionNumericaDada);

	/*
	 * PRE:
	 * POST:
	 * COMPLEJIDAD: O(1)
	 * EXPLICACION: Pone un breve comentario a un Conductor.
	 * */
	void ponerOpinion(string opinion);

	/*
	 * PRE:
	 * POST:
	 * COMPLEJIDAD: O(1)
	 * EXPLICACION: Obtiene una puntuacion de un Conductor concreto.
	 * */
	int    obtenerValoracionNumerica();

	/*
	 * PRE:
	 * POST:
	 * COMPLEJIDAD: O(1)
	 * EXPLICACION: Devuelve un comentario sobre un Conductor.
	 * */
	string obtenerOpinion();

	/*
	 * PRE:
	 * POST:
	 * COMPLEJIDAD: O(1)
	 * EXPLICACION: Muestra una opinion completa sobre un conductor. Incluye puntuación y comentario.
	 * */
	void   mostrarOpinion();

	~Opinion();
};

#endif /* OPINION_H_ */
