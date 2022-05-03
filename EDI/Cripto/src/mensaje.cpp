/*
 * mensaje.cpp
 *
 *  Autor: Manuel Cobos Solís
 *  Fecha: 28-04-2022
 *  Corrreo: mcobosso@unex.es
 */

#include "mensaje.h"


mensaje::mensaje() {
	identificador = 0;
	texto = "";
	autorMensaje = "";
}
mensaje::mensaje(int identificador, string texto, string autor){
	this->identificador = identificador;
	this->texto = texto;
	this->autorMensaje = autor;
}
int mensaje::obtenerIdentificador(){
	return this->identificador;
}
string mensaje::obtenerTexto(){
	return this->texto;
}
string mensaje::obtenerAutorMensaje(){
	return this->autorMensaje;
}
void mensaje::ponerIdentificador(int id){
	this->identificador = id;
}
void mensaje::ponerTexto(string txt){
	this->texto = txt;
}
void mensaje::ponerAutorMensaje(string autor){
	this->autorMensaje = autor;
}
void mensaje::mostrarMensaje(){
	cout<<"ID: "<<identificador<<endl;
	cout<<"Autor: "<<autorMensaje<<endl;
	cout<<"Mensaje: "<<texto<<endl;
	cout<<"--------------------------------------------------------------"<<endl;
}

mensaje::~mensaje() {

}
