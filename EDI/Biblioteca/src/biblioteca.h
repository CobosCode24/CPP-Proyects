#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_


#include <iostream>
#include <fstream>
#include <string>

#include "vov_libros.h"
#include "VoVUsuarios.h"

using namespace std;


class Biblioteca {

private:

   VoV_Usuarios *ptr_De_Usuarios;
   VoV_Libros   *ptr_De_Libros;
   string 		 nombre;

public:

	/*
	 * EXPLICACION: Constructor. Reserva espacio para los VoV libros y usuario.
	 *				inicia la variable de nombre.
	 * COMPLEJIDAD: O(1)
	 * PRE:
	 * POST:
	 */
   Biblioteca();

	/*
	 * EXPLICACION: Constructor. Reserva espacio para los VoV libros y usuario.
	 *				inicia la variable de nombre.
	 * COMPLEJIDAD: O(1)
	 * PRE:
	 * POST:
	 */
   Biblioteca (string nombre);

	/*
	 * EXPLICACION: Importa los libros del archivo libros.csv.
	 * COMPLEJIDAD: O(n)
	 * PRE: El archivo debe estar lleno para empezar a importar los datos.
	 * POST:
	 */
   void cargarLibros();

	/*
	 * EXPLICACION: Importa los libros del archivo usuarios.csv
	 * COMPLEJIDAD: O(n)
	 * PRE: El archivo debe estar lleno para empezar a importar los datos.
	 * POST:
	 */
   void cargarUsuarios();

	/*
	 * EXPLICACION: Presta un libro a traves de la ID del ,mismo a un usuario
	 * 				a traves de su DNI.
	 * COMPLEJIDAD: O(1)
	 * PRE: La ID y el DNI deben existir.
	 * POST:
	 */
   void prestarLibro(string ID, string dni);

	/*
	 * EXPLICACION: Muestra todos los libros de una tematica dada.
	 * COMPLEJIDAD: O(n)
	 * PRE: La tematica dada debe existir.
	 * POST:
	 */
   void mostrarLibrosPorTematica(string tematicaDada);

	/*
	 * EXPLICACION: Obtiene un libro a traves de su ID.
	 * COMPLEJIDAD: O(n)
	 * PRE: La ID deve ser valida.
	 * POST:
	 */
   Libro* obtenerLibroID(string ID);

	/*
	 * EXPLICACION: Muestra todos los libros de la Biblioteca.
	 * COMPLEJIDAD: O(n)
	 * PRE: La biblioteca tiene que estar con al menos 1 libro.
	 * POST:
	 */
   void mostrarLibros();

	/*
	 * EXPLICACION: Muestra Todos los usuarios registrados en la Biblioteca.
	 * COMPLEJIDAD:O(n)
	 * PRE:
	 * POST:
	 */
   void mostrarUsuarios();

	/*
	 * EXPLICACION: Muestra solo los usuarios con prestamo.
	 * COMPLEJIDAD: O(n)
	 * PRE:
	 * POST:
	 */
   void mostrarUsuarios_conPrestamo();

	/*
	 * EXPLICACION: Elimina un libro de la Biblioteca.
	 * COMPLEJIDAD: O(1)
	 * PRE: La ID debe ser valida.
	 * POST:
	 */
   void eliminarLibro(string titulo);

	/*
	 * EXPLICACION: Escribe los cambios realizados durante la consulta,
	 * 				creando dos nuevos ficheros .txt, uno para los usuarios
	 * 				y otro para los libros.
	 * COMPLEJIDAD: O(n2)
	 * PRE:
	 * POST:
	 *
	 * PD: Se que tambien se pueden sobrescribir los datos en los archivos originales .csv, y asi siempre guardar los cambios y a la hora de ejecutar otra
	 * 	   vez el programa que se carguen los datos de la anterios vez. He preferido modificar archivos externos para asi no dañar el contenido de los originales.
	 */
   void escribirLibros_Usuarios();


   ~Biblioteca();

};


#endif /* BIBLIOTECA_H_ */
