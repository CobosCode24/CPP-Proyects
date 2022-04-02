#include <iostream>
#include <fstream>
#include <string>

#include "biblioteca.h"
#include "vov_libros.h"


using namespace std;


int menu() {

	int opcion;

	do {
		cout << endl;
		cout << "_______________ MENU PRINCIPAL _______________"<< endl << endl;

		cout << "     1. Prestar un libro.                     "	<<endl;
		cout << "     2. Mostrar libros por temática.          "	<<endl;
		cout << "     3. Buscar un libro por ID.               "	<<endl;
		cout << "     4. Mostrar todos los libros.             "	<<endl;
		cout << "     5. mostrar todos los usuarios.           "	<<endl;
		cout << "     6. Mostrar usuarios que tienen prestamo. "	<<endl;
		cout << "     7. Descatalogar un libro.                "	<<endl;
		cout << "     0. Finalizar.                            " 	<<endl;
		cout << "                        Opcion:  ";
		cin >> opcion;
		cin.ignore();

	} while ((opcion < 0) || (opcion > 7));

	return opcion;
}


int main() {

	Biblioteca* ptrBiblioteca;
	ptrBiblioteca = new Biblioteca("NUEVA BIBLIO");
	bool        fin = false;
	int         opcion;
	string 		ID, dni, tematica, titulo;

	ptrBiblioteca->cargarLibros();
	ptrBiblioteca->cargarUsuarios();


	do {
		opcion = menu();

		switch (opcion) {
			case 1:

				cout<<"\nIntroduzca el ID del libro: ";
				getline (cin,ID);
				cout<<"\nIntroduzca el DNI del usuario: ";
				cin>>dni;

				ptrBiblioteca->prestarLibro(ID, dni);

				break;
			case 2:

				cout<<"\nIntrocuzca la tematica: ";
				getline(cin, tematica);

				ptrBiblioteca->mostrarLibrosPorTematica(tematica);

				break;
			case 3:

				cout<<"\nIntroduzca la ID del libro: "<<endl;
				getline(cin, ID);
				Libro *l;
				l = NULL;

				l = ptrBiblioteca->obtenerLibroID(ID);
				l->mostrarLibro();

				break;
			case 4:

				ptrBiblioteca->mostrarLibros();

				break;
			case 5:

				ptrBiblioteca->mostrarUsuarios();

				break;
			case 6:

				ptrBiblioteca->mostrarUsuarios_conPrestamo();

				break;
			case 7:

				cout<<"\nIntroduzca el título del libro a eliminar: "<<endl;
				getline(cin, titulo);

				ptrBiblioteca->eliminarLibro(titulo);

				break;

			case 0:

				ptrBiblioteca->escribirLibros_Usuarios();

				fin = true;
				break;

			default:
				break;

		}

	} while (!fin);

	delete ptrBiblioteca;
	return 0;
}

