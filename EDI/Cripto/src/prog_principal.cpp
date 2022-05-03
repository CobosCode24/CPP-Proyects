/*
 * prog_principal.cpp
 *
 *  Autor: Manuel Cobos Solís
 *  Fecha: 28-04-2022
 *  Corrreo: mcobosso@unex.es
 */

#include <iostream>
#include <fstream>
#include <string>

#include "cripto.h"

using namespace std;


// Muestra el menu por pantalla y devuelve una opcion elegida.
int menu() {

	int opcion;

	do {
		cout << endl;
		cout << "______________ MENU PRINCIPAL ______________"<< endl << endl;

		cout << "     1. Insertar mensaje                   " << endl;
		cout << "     2. Borrar mensaje                     " << endl;
		cout << "     3. Buscar mensaje y mostrar           " << endl;
		cout << "     4. Mostrar todos                      " << endl;
		cout << "     5. Mensajes por autor                 " << endl;
		cout << "                                           " << endl;
		cout << "     6. Cambiar PIN                        " << endl;
		cout << "     7. Codificar un mensaje               " << endl;
		cout << "     8. Decodificar un mensaje             " << endl;
		cout <<                                                  endl;
		cout << "     0. Finalizar.                         " << endl;
		cout << "                        Opcion:  ";
		cin >> opcion;
		cin.ignore();

	} while ((opcion < 0) || (opcion > 8));

	return opcion;
}


// Programa principal: 
int main() {
	bool fin = false;
	int opcion, identificadorDado = 0, pin = 0;
	string textoDado = "", autorDado = "";

	Cripto *c = new Cripto();
	mensaje* m;
	LPI<mensaje*>* l;


	while(!fin) {
		opcion = menu();

		switch (opcion) {
		case 1:
			c->obtenerCasoUno(identificadorDado, textoDado, autorDado);
			m = new mensaje(identificadorDado, textoDado, autorDado);
			c->insertarMensaje(m);

			break;
		case 2:
			c->obtenerCasoDos(identificadorDado);
			c->borrarMensaje(identificadorDado);

			break;
		case 3:
			c->obtenerCasoTres(identificadorDado);
		    c->buscarMensajePorID(identificadorDado);

			break;
		case 4:
			c->mostrarMensajes();

			break;
		case 5:
			c->obtenerCasoCinco(autorDado);
			l = new LPI<mensaje*>;
			c->buscarMensajePorAutor(autorDado, l);
			c->bucleMensajePorAutor(l);

			break;
		case 6:
			cout<<"Introduce un pin de 4 dígitos: "<<endl;
			cin>>pin;
			c->cambiarContrasenia(pin);

			break;
		case 7:
			cout<<"Introduce la id: ";
			cin>>identificadorDado;
			c->Codificar(identificadorDado);

			break;
		case 8:
			cout<<"Introduce la id: ";
			cin>>identificadorDado;
			c->Decodificar(identificadorDado);

			break;
		case 0:

			fin = true;
			c->finalizarAplicacion();

			break;

		default:
			break;

		}
	}

	return 0;
}


