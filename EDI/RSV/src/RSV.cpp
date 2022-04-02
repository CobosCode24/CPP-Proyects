#include <iostream>
#include "RSV.h"
using namespace std;


RSV::RSV() {
	lv = new LPI<Viaje*>();
	lc = new LPI<Conductor*>();
}
void RSV::cargarConductores() {

	ifstream lectura;
	string identificador = "", nombre = "", marcaModeloCoche = "", edadString =
			"", anioAltaString = "";
	int edad = 0, anioAlta = 0;
	Conductor *c;

	lectura.open("conductores.csv");
	if (lectura.is_open()) {

		while (!lectura.eof()) {

			/*		LECTURA DE DATOS		*/

			getline(lectura, identificador, ';');
			getline(lectura, nombre, ';');
			getline(lectura, edadString, ';');
			getline(lectura, marcaModeloCoche, ';');
			getline(lectura, anioAltaString, '\n');
			if (lectura) {
				edad = stoi(edadString);
				anioAlta = stoi(anioAltaString);

					    c = new Conductor(identificador, nombre, edad,
						anioAlta, marcaModeloCoche);

				/*		PONER LOS DATOS EN EL lc		*/

				insertarConductor(c);

			}
		}
		lectura.close();

	}
}
void RSV::cargarValoraciones() {

	ifstream lectura;
	string identificador = "", opinion = "", puntuacionString = "";
	int puntuacion = 0;
	Opinion *op;

	lectura.open("valoraciones.csv");
	if (lectura.is_open()) {

		while (!lectura.eof()) {

			getline(lectura, identificador, ';');
			getline(lectura, puntuacionString, ';');
			getline(lectura, opinion, '\n');

			if (lectura) {
				puntuacion = stoi(puntuacionString);

				op = new Opinion(puntuacion, opinion);

				insertaOpinion(op, identificador);

			}

		}
		lectura.close();
	}
}
void RSV::cargarViajes() {

	ifstream lectura;

	string ciudadOrigen = "", ciudadDestino = "", identificador = "",
			horaSalidaString = "";
	int horaSalida = 0;
	Viaje *v;

	lectura.open("viajes.csv");

	if (lectura.is_open()) {

		lv->moverInicio();

		while (!lectura.eof()) {

			/*	LECTURA DE DATOS	*/

			getline(lectura, ciudadOrigen, ';');
			getline(lectura, ciudadDestino, ';');
			getline(lectura, horaSalidaString, ';');
			getline(lectura, identificador, '\n');

			if (lectura) {
				horaSalida = stoi(horaSalidaString);

					v = new Viaje(ciudadOrigen, ciudadDestino, horaSalida,
						identificador);

				insertarViaje(v);

			}

		}
		lectura.close();

	}
}

//-------------------------- OPCIONES DEL PROGRAMA ---------------------------------

/**/
void RSV::insertaOpinion(Opinion *opinion, string identificador) {

	Conductor *c;
	if (buscarConductor(identificador, c)) {
		c->ponerOpinion(opinion);
	}
}

/**/
void RSV::insertarConductor(Conductor *c) {

	Conductor *c2;
	if (!buscarConductor(c->obtenerIdentificador(), c2)) {
		bool enc = false;
		Conductor *cAux;

		lc->moverInicio();
		while (!enc && !lc->enFin()) {
			lc->consultar(cAux);
			if (c->obtenerIdentificador() < cAux->obtenerIdentificador()) {
				enc = true;
			} else {
				lc->avanzar();
			}

		}
		lc->insertar(c);

	}

}

/**/
void RSV::valorarConductor(string identificador, Opinion *op) {

	Conductor *c;
	if (buscarConductor(identificador, c)) {
		c->ponerOpinion(op);
	} else {
		cout << "\nConductor no encontrado." << endl;
	}

}

/**/
void RSV::insertarViaje(Viaje *v) {

	bool encontrado = false;
	Viaje *vMayorActual;

	lv->moverInicio();
	while (!lv->enFin() && !encontrado) {

		lv->consultar(vMayorActual);
		if (*vMayorActual > *v) {
			encontrado = true;
		} else {
			lv->avanzar();
		}

	}
	lv->insertar(v);

}

/**/
void RSV::mostrarConductores() {

	Conductor *c;

	lc->moverInicio();
	while (!lc->enFin()) {
		lc->consultar(c);
		c->mostrarConductor();
		lc->avanzar();
	}

}

/**/
void RSV::mostrarViajes() {

	Viaje *v;

	lv->moverInicio();
	while (!lv->enFin()) {
		lv->consultar(v);
		v->mostrarViaje();
		lv->avanzar();

	}

}

/**/
void RSV::mostrarTodo() {

	Viaje *v;
	Conductor *c;

	lv->moverInicio();
	while (!lv->enFin()) {

		lv->consultar(v);
		cout<<endl;
		v->mostrarViajeConID();

		if (buscarConductor(v->obtenerIdentificador(), c)) {
			c->mostrarConductor();
		}

		lv->avanzar();

	}

}

/**/
bool RSV::buscarConductor(string id, Conductor *&c) {

	bool enc = false;

	lc->moverInicio();
	while (!lc->enFin() && !enc) {

		lc->consultar(c);
		if (c->obtenerIdentificador() == id) {
			enc = true;

		} else {
			lc->avanzar();
		}
	}

	return enc;
}

/**/
void RSV::eliminarConductor(string identificador) {

	Conductor *c;
	if (buscarConductor(identificador, c)) {
		eliminarViajesConductor(identificador);
		delete c;
		lc->borrar();
	} else {
		cout<<"Conductor no encontrado. "<<endl;
	}

}

void RSV::eliminarViajesConductor(string identificadorDado) {

	Viaje *v;
	lv->moverInicio();
	while (!lv->enFin()) {
		lv->consultar(v);
		if (v->obtenerIdentificador() == identificadorDado) {

			lv->borrar();
			delete v;
		}
		lv->avanzar();

	}

}

/**/
void RSV::colaViajes(string origen, string destino, Cola<Viaje*> *&cola) {

	Viaje *v;
	bool enc = false;
	Cola<Viaje*> *colaAux=new Cola<Viaje*>() ;

	lv->moverInicio();
	while (!lv->enFin()) {

		lv->consultar(v);
		if ((v->obtenerCiudadOrigen() == origen)
				&& (v->obtenerCiudadDestino() == destino)) {

			enc = true;

			cola->encolar(v);

			lv->avanzar();

		} else {
			lv->avanzar();
		}

	}
	if (enc == false) {
		cout << "Ningún viaje encontrado que tenga origen " << origen
				<< " y destino " << destino << "." << endl;
	} else {

		while(!cola->vacia()){
			cola->primero(v);
			v->mostrarViaje();
			colaAux->encolar(v);
			cola->desencolar();
		}

		while(!colaAux->vacia()){
			colaAux->primero(v);
			cola->encolar(v);
			colaAux->desencolar();
		}

	}
	delete colaAux;

}

RSV::~RSV() {

	delete lc;
	delete lv;

}
