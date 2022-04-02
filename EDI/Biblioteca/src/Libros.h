#ifndef LIBROS_H_
#define LIBROS_H_
#include <iostream>
using namespace std;

class Libro {
private:
	string titulo;
	string autor;
	string tematica;
	string anio;
	string paginas;
	string ID;

public:

	/*
	 * EXPLICACION: Constructor. Inicio las variables titulo, autor, tematica, anio, paginas.
	 * COMPLEJIDAD: O(1)
	 * PRE:
	 * POST:
	 */
	Libro();

	/*
	 * EXPLICACION: Obtiene el titulo de un libro.
	 * COMPLEJIDAD: O(1)
	 * PRE:
	 * POST:
	 */
	string obtenerTitulo();

	/*
	 * EXPLICACION: Pone el titulo a un libro.
	 * COMPLEJIDAD: O(1)
	 * PRE: El libro debe de existir.
	 * POST:
	 */
	void ponerTitulo(string titulo);

	/*
	 * EXPLICACION: Obtiene el autor de un libro.
	 * COMPLEJIDAD: O(1)
	 * PRE:
	 * POST:
	 */
	string obtenerAutor();

	/*
	 * EXPLICACION: POne el autor a un libro.
	 * COMPLEJIDAD: O(1)
	 * PRE: El libro debe de existir.
	 * POST:
	 */
	void ponerAutor(string autor);

	/*
	 * EXPLICACION: Obtiene la tematica de un libro.
	 * COMPLEJIDAD: O(1)
	 * PRE:
	 * POST:
	 */
	string obtenerTematica();

	/*
	 * EXPLICACION: Pone la tematica a un libro.
	 * COMPLEJIDAD: O(1)
	 * PRE: El libro debe de existir.
	 * POST:
	 */
	void ponerTematica(string tematica);

	/*
	 * EXPLICACION: Obtiene el año de punlicación de un libro.
	 * COMPLEJIDAD: O(1)
	 * PRE:
	 * POST:
	 */
	string obtenerAnio();

	/*
	 * EXPLICACION: Pone el año de publicacion de un libro.
	 * COMPLEJIDAD: O(1)
	 * PRE: El libro debe de existir.
	 * POST:
	 */
	void ponerAnio(string anio);

	/*
	 * EXPLICACION: Obtiene el numero de paginas de un libro.
	 * COMPLEJIDAD: O(1)
	 * PRE:
	 * POST:
	 */
	string obtenerPaginas();

	/*
	 * EXPLICACION: Pone el numero de paginas a un libro.
	 * COMPLEJIDAD: O(1)
	 * PRE: El libro debe existir.
	 * POST:
	 */
	void ponerPaginas(string paginas);

	/*
	 * EXPLICACION: Genera una ID unica para cada libro, formada por las tres primeras letras del titulo,
	 * 				las tres primeras letras del nombre del autor y el año completo de publicacion del libro.
	 * 				Todos estos separados por un punto, de la forma: titulo.autor.año .
	 * COMPLEJIDAD: O(1)
	 * PRE:
	 * POST:
	 */
	void generarID();

	/*
	 * EXPLICACION: Obtiene el ID de un libro determinado.
	 * COMPLEJIDAD: O(1)
	 * PRE: El libro debe existir.
	 * POST: Devuelve la ID del libro.
	 */
	string obtenerID();

	/*
	 * EXPLICACION: Pone la ID generada anteriormente a un libro.
	 * COMPLEJIDAD: O(1)
	 * PRE:
	 * POST:
	 */
	void ponerID(string ID);

	/*
	 * EXPLICACION: Muestra toda la informacion de un libro.
	 * COMPLEJIDAD: O(1)
	 * PRE:
	 * POST:
	 */
	void mostrarLibro();

	/*
	 * EXPLICACION: Destructor.
	 * COMPLEJIDAD: O(1)
	 * PRE:
	 * POST:
	 */
	virtual ~Libro();

};

#endif /* LIBROS_H_ */
