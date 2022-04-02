#include <iostream>
#include "Viaje.h"
using namespace std;



Viaje::Viaje() {
	ciudadOrigen = "";
	horaSalida = 0;
	identificador = "";
}

Viaje::Viaje(string ciudadOrigen, string ciudadDestino, int horaSalida, string identificador){
	this->ciudadOrigen = ciudadOrigen;
	this->ciudadDestino = ciudadDestino;
	this->horaSalida = horaSalida;
	this->identificador = identificador;
}

bool Viaje::operator> (const Viaje &v){
	bool respuesta = false;

	if( ciudadOrigen > v.ciudadOrigen || ((ciudadOrigen == v.ciudadOrigen) && (horaSalida > v.horaSalida) )){
		respuesta = true;
	}

	return respuesta;
}
void Viaje::ponerCiudadOrigen(string ciudadOrigenDado){
	this->ciudadOrigen = ciudadOrigenDado;
}
void Viaje::ponerCuidadDestino(string ciudadDestinoDado){
	this->ciudadDestino = ciudadDestinoDado;
}
void Viaje::ponerHoraSalida(int horaSalidaDada){
	this->horaSalida = horaSalidaDada;
}
void Viaje::ponerIdentificador(string idDado){
	this->identificador = idDado;
}
string Viaje::obtenerCiudadOrigen(){
	return ciudadOrigen;
}
string Viaje::obtenerCiudadDestino(){
	return ciudadDestino;
}
int Viaje::obtenerHoraSalida(){
	return horaSalida;
}
string Viaje::obtenerIdentificador(){
	return identificador;
}
void Viaje::mostrarViaje(){

	cout<<"Ciudad origen: "<<ciudadOrigen<<" | Ciudad destino: "<<ciudadDestino<<" | Hora salida: "<<horaSalida<<endl;

}
void Viaje::mostrarViajeConID(){

	cout<<"Ciudad origen: "<<ciudadOrigen<<" | Ciudad destino: "<<ciudadDestino<<" | Hora salida: "<<horaSalida<<" | ID (conductor): "<<identificador<<endl;

}

Viaje::~Viaje() {


}

