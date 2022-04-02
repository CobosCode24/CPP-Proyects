#ifndef VOV_LIBROS_H_
#define VOV_LIBROS_H_


#include <iostream>
#include <fstream>
#include <string>
#include "Libros.h"
using namespace std;

const int MAX_LIBROS = 100;


class VoV_Libros {

private:
   Libro* VL [MAX_LIBROS];
   int posicion;

public:

	/*
	 * EXPLICACION: Construtor. Inicializa la posicion a 0.
	 * COMPLEJIDAD: O(1)
	 * PRE:
	 * POST:
	 */
	VoV_Libros ();

	/*
	 * EXPLICACION: Inserta un nuevo libro al VoV.
	 * COMPLEJIDAD: O(n)
	 * PRE:
	 * POST:
	 */
	void insertarLibro(Libro* l);

	/*
	 * EXPLICACION: Elimina un determinado libro sabiendo su titulo.
	 * COMPLEJIDAD: O(n)
	 * PRE: La ID del libro debe de ser valida.
	 * POST: Si encuentra la ID, el libro se eliminara.
	 */
	void eliminarLibro(string titulo);

	/*
	 * EXPLICACION: Obtiene un libro sabiendo la posicion en la que esta.
	 * COMPLEJIDAD: O(1)
	 * PRE: La posicion debe estar entre 0 y MAX_LIBROS.
	 * POST: Devuelve el libro.
	 */
	Libro* obtenerLibroPOS(int posicion);

	/*
	 * EXPLICACION: Obtiene un libro sabiendo la ID del mismo.
	 * COMPLEJIDAD: O(n)
	 * PRE: La ID del libro debe ser valida.
	 * POST: Devuelve el libro.
	 */
	Libro* obtenerLibroID(string ID);

	/*
	 * EXPLICACION: Comprueba si existe un libro a traves de su ID.
	 * COMPLEJIDAD: O(n)
	 * PRE: La ID debe ser valida.
	 * POST: Devuelve "true" si existe o "false" si no existe.
	 */
	bool existeLibro(string ID);

	/*
	 * EXPLICACION: Devuelve la cantidad de libros que hay en el VoV.
	 * COMPLEJIDAD: O(1)
	 * PRE:
	 * POST:
	 */
	int cuantosLibro();

	/*
	 * EXPLICACION: Destructor. Borra todos los libros del VoV.
	 * COMPLEJIDAD: O(n)
	 * PRE:
	 * POST:
	 */
	~VoV_Libros();

};




#endif /* VOV_LIBROS_H_ */
