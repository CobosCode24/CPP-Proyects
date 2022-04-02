#include <iostream>
#include "biblioteca.h"
#include "vov_libros.h"
#include <fstream>

using namespace std;

Biblioteca::Biblioteca() {

	// CONSTRUCTOR 1.

	ptr_De_Usuarios = new VoV_Usuarios;
	ptr_De_Libros = new VoV_Libros;
	nombre = "";

}
Biblioteca::Biblioteca(string nombreDado) {

	// CONSTRUCTOR 2.

	this->nombre = nombreDado;
	ptr_De_Usuarios = new VoV_Usuarios;
	ptr_De_Libros = new VoV_Libros;

}

void Biblioteca::cargarLibros() {

	ifstream leer;
	string tituloLeido, autorLeido, tematicaLeida, anioLeido, paginasLeido, ID;

	leer.open("libros.csv"); // abre el archivo.
	if (leer.is_open()) { // comprueba si esta abierto.

		while (!leer.eof()) { //cuando el archivo ha llegado al final.

			getline(leer, tituloLeido, ';'); //titulo
			getline(leer, autorLeido, ';'); // autor
			getline(leer, tematicaLeida, ';'); //tematica
			getline(leer, anioLeido, ';'); //año
			getline(leer, paginasLeido, '\n'); //paginas 	// salta a la siguiente linea.
			if (!leer.eof()) {
				Libro *l = new Libro;
				l->ponerTitulo(tituloLeido);
				l->ponerAutor(autorLeido);
				l->ponerTematica(tematicaLeida);
				l->ponerAnio(anioLeido);
				l->ponerPaginas(paginasLeido);
				l->generarID();

				ptr_De_Libros->insertarLibro(l);
			}
		}
		leer.close(); // cierra el archivo.
	} else {
		cout << "ERROR AL ABRIR EL FICHERO libros.csv" << endl;
	}

}
void Biblioteca::cargarUsuarios() {

	ifstream leer;
	string dniLeido, nombreLeido, correoLeido, apellidoLeido, prestadoLeido;

	leer.open("usuarios.csv"); // abre el archivo.
	if (leer.is_open()) { // comprueba si esta abierto.

		while (!leer.eof()) { //cuando el archivo ha llegado al final.

			getline(leer, dniLeido, ';'); //dni
			getline(leer, nombreLeido, ';'); // nombre
			getline(leer, correoLeido, ';'); //correo
			getline(leer, apellidoLeido, ';'); //apellido
			getline(leer, prestadoLeido, '\n'); //prestamo 	// salta a la siguiente linea.
			if (!leer.eof()) {
				Usuario *u = new Usuario;
				u->setDni(dniLeido);
				u->setNombre(nombreLeido);
				u->setCorreo(correoLeido);
				u->setApellido(apellidoLeido);
				u->setPrestado(prestadoLeido);

				ptr_De_Usuarios->insertarUsuario(u);
			}
		}
		leer.close(); // cierra el archivo.
	} else {
		cout << "ERROR AL ABRIR EL FICHERO usuarios.csv" << endl;
	}

}
void Biblioteca::prestarLibro(string ID, string dni) {

	Usuario *u = NULL;
	Libro *l = NULL;

	if (ptr_De_Libros->existeLibro(ID) == true) {

		l = ptr_De_Libros->obtenerLibroID(ID);

		if (ptr_De_Usuarios->existeUsuario(dni) == true) {

			u = ptr_De_Usuarios->obtenerUsuarioDNI(dni);
			u->setPrestado(l->obtenerTitulo());
		} else {
			cout << "\nUsuario no encontrado ..." << endl;
		}
	} else {
		cout << "\nLibro no encontrado ..." << endl;
	}
}
void Biblioteca::mostrarLibrosPorTematica(string tematicaDada) {

	Libro *l = NULL;
	string tema;
	int i;

	for (i = 0; i < ptr_De_Libros->cuantosLibro(); i++) {

		l = ptr_De_Libros->obtenerLibroPOS(i);
		tema = l->obtenerTematica();
		if (tema == tematicaDada) {
			l->mostrarLibro();
		}

	}

}

Libro* Biblioteca::obtenerLibroID(string ID) {

	Libro *l = NULL;
	int i = 0;
	bool enc = false;

	while (i < (ptr_De_Libros->cuantosLibro()) && !enc) {
		l = ptr_De_Libros->obtenerLibroPOS(i);

		if (l->obtenerID() == ID) {
			enc = true;
		} else {
			i++;
		}

	}

	return l;
}

void Biblioteca::mostrarLibros() {

	int i;
	Libro *l;
	for (i = 0; i < ptr_De_Libros->cuantosLibro(); i++) {
		l = ptr_De_Libros->obtenerLibroPOS(i);
		l->mostrarLibro();
		cout << "---------------------------------------------" << endl;
	}

}

void Biblioteca::mostrarUsuarios() {

	int i;
	Usuario *u;
	for (i = 0; i < ptr_De_Usuarios->cuantosUsuario(); i++) {
		u = ptr_De_Usuarios->obtenerUsuarioPOS(i);
		u->mostrarUsuario();
		cout << "---------------------------------------------" << endl;
	}

}

void Biblioteca::mostrarUsuarios_conPrestamo() {
	int i;
	Usuario *u = NULL;

	for (i = 0; i < ptr_De_Usuarios->cuantosUsuario(); i++) {
		u = ptr_De_Usuarios->obtenerUsuarioPOS(i);
		if ((u->getPrestado()) != "sin-prestamo") {
			u->mostrarUsuario();
		}
	}
}

void Biblioteca::eliminarLibro(string titulo) {

	if (ptr_De_Usuarios->libroPrestado(titulo) == false) {
		ptr_De_Libros->eliminarLibro(titulo);
		cout << "Libro eliminado... " << endl;
	} else {
		cout << "Este libro esta prestado." << endl;
	}

}

void Biblioteca::escribirLibros_Usuarios() {

	/* Escritura de las modificaciones a los libros */

	Libro *l = NULL;
	ofstream escritura_libros;
	escritura_libros.open("libros.csv", ios::trunc);
	for (int i = 0; i < ptr_De_Libros->cuantosLibro(); i++) {

		l = ptr_De_Libros->obtenerLibroPOS(i);
		escritura_libros << l->obtenerTitulo() << ";" << l->obtenerAutor()
				<< ";" << l->obtenerTematica() << ";" << l->obtenerAnio() << ";"
				<< l->obtenerPaginas() << endl;

	}
	escritura_libros.close();

	/* Escritura de las modificaciones a los usuarios */

	Usuario *u = NULL;
	ofstream escritura_usuarios;
	escritura_usuarios.open("usuarios.csv", ios::trunc);
	for (int i = 0; i < ptr_De_Usuarios->cuantosUsuario(); i++) {

		u = ptr_De_Usuarios->obtenerUsuarioPOS(i);
		escritura_usuarios << u->getDni() << ";" << u->getNombre() << ";"
				<< u->getCorreo() << ";" << u->getApellido() << ";"
				<< u->getPrestado() << endl;

	}
	escritura_usuarios.close();

}
Biblioteca::~Biblioteca() {

	//DESTRUCTOR 2.
	delete ptr_De_Libros;
	delete ptr_De_Usuarios;

}
