
// Autor: Manuel Cobos Solís
// Correo: mcobosso@alumnos.unex.es
// Fecha: 02/04/2022
// Descripción:

#include "RSV.h"
#include <iostream>
using namespace std;


// Muestra el menu por pantalla y devuelve una opcion elegida.
int menu() {

	int opcion;

	do {

		cout << "______________ MENU PRINCIPAL ______________" << endl << endl;

		cout << "     1. Insertar conductor                 " << endl;
		cout << "     2. Valorar conductor                  " << endl;
		cout << "     3. Insertar Viaje                     " << endl;
		cout << "     4. Mostrar conductores                " << endl;
		cout << "     5. Mostrar viajes                     " << endl;
		cout << "     6. Mostrar todo                       " << endl;
		cout << "     7. Buscar conductor                   " << endl;
		cout << "     8. Eliminar Conductor                 " << endl;
		cout << "     9. Cola Viajes                        " << endl;
		cout << endl;
		cout << "     0. Finalizar.                         " << endl;
		cout << "                        Opcion:  ";
		cin >> opcion;
		cin.ignore();

	} while ((opcion < 0) || (opcion > 9));

	return opcion;
}

void mensajeFinRSV() {
	cout << "\n\n\t\t Gracias por utilizar el servicio RSV" << endl;
}

int main() {

	//Creacción de la estructura del RSV.
	RSV *rsv = new RSV();

	//Cargamos y volcamos los datos en el RSV.
	rsv->cargarConductores();
	rsv->cargarValoraciones();
	rsv->cargarViajes();

	//Variables del programa principal.
	bool terminar = false;
	int opcion, edadLeida = 0, anioAltaLeido = 0, puntuacion = 0,
			horaSalida = 0;
	string identificadorLeido = "", nombreLeido = "", modeloCocheLeido = "",
			identificador = "", opinion = "", ciudadOrigen = "", ciudadDestino =
					"", origen = "", destino = "", respuesta = "";

	//Punteros
	Conductor *c;
	Opinion *op;
	Viaje *v;
	Cola<Viaje*> *cola;

	cout << endl;
	cout << "\t ########   ######  ##     ##" << endl;
	cout << "\t ##     ## ##    ## ##     ##" << endl;
	cout << "\t ##     ## ##       ##     ##" << endl;
	cout << "\t ########   ######  ##     ##" << endl;
	cout << "\t ##   ##         ##  ##   ##" << endl;
	cout << "\t ##    ##  ##    ##   ## ##" << endl;
	cout << "\t ##     ##  ######     ### " << endl << endl;

	//Seleccion de las opciones del programa
	while (!terminar) {
		opcion = menu();

		switch (opcion) {
		case 1:

			cout << "Introduce el identificador: " << endl;
			getline(cin, identificadorLeido);
			cout << "Introduce la edad: " << endl;
			cin >> edadLeida;
			cin.ignore();
			cout << "Introduce el nombre: " << endl;
			getline(cin, nombreLeido);
			cout << "Introduce el modelo del coche: " << endl;
			getline(cin, modeloCocheLeido);
			cout << "Introduce el año que se da de alta en la app: " << endl;
			cin >> anioAltaLeido;
			cin.ignore();

			if (!rsv->buscarConductor(identificadorLeido, c)) {

				c = new Conductor(identificadorLeido, nombreLeido, edadLeida,
						anioAltaLeido, modeloCocheLeido);
				rsv->insertarConductor(c);

			} else {
				cout
						<< "Ese Conductor ya existe y su identificador no esta disponible."
						<< endl;
			}

			break;
		case 2:

			cout << "Introduce el identificador del conductor a valorar: "
					<< endl;
			getline(cin, identificador);
			cout << "Introduce la puntuacion: " << endl;
			cin >> puntuacion;
			cin.ignore();
			if ((puntuacion >= 0) && (puntuacion <= 10)) {
				cout << "Intruduce la opinion: " << endl;
				getline(cin, opinion);
				op = new Opinion(puntuacion, opinion);
				rsv->valorarConductor(identificador, op);
			} else {
				cout
						<< "Por favor, introduce un valor válido entre 0 (pésimo) y 10 (excelente)."
						<< endl;
			}

			break;
		case 3:

			cout << "Introduce la ciudad de Origen: " << endl;
			cin >> ciudadOrigen;
			cout << "Introduce la ciudad de Destino: " << endl;
			cin >> ciudadDestino;
			cout << "Introduce la Hora de salida: " << endl;
			cin >> horaSalida;
			cout << "Intriduce el identificador del conductor: " << endl;
			cin >> identificador;
			v = new Viaje(ciudadOrigen, ciudadDestino, horaSalida,
					identificador);
			rsv->insertarViaje(v);

			break;
		case 4:

			rsv->mostrarConductores();

			break;
		case 5:

			rsv->mostrarViajes();

			break;
		case 6:

			rsv->mostrarTodo();

			break;
		case 7:

			cout << "Introduce la id del conductor: " << endl;
			getline(cin, identificador);
			if (rsv->buscarConductor(identificador, c))
				c->mostrarConductor();

			break;
		case 8:

			cout
					<< "Introduce el identificador del conductor que desea eliminar: "
					<< endl;
			getline(cin, identificador);
			cout
					<< "\n¿Esta seguro que desea eliminar al conductor del RSV? (s/n)";
			getline(cin, respuesta);
			if (respuesta == "s") {
				rsv->eliminarConductor(identificador);
			} else {
				if (respuesta == "n") {
					cout << "\nOperacion cancelada" << endl;
				} else {
					cout << "\nCaracter no válido..." << endl;
				}
			}

			break;
		case 9:

			cout << "Introduce la ciudad de origen: " << endl;
			getline(cin, origen);
			cout << "introduce la ciudad de destino:" << endl;
			getline(cin, destino);
			cola = new Cola<Viaje*>();
			rsv->colaViajes(origen, destino, cola);
			delete cola;

			break;

		case 0:

			mensajeFinRSV();

			terminar = true;
			break;

		default:
			break;

		}

	}

	return 0;

}
