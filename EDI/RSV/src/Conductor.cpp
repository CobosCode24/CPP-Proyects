#include <iostream>
#include "Conductor.h"
using namespace std;


Conductor::Conductor() {

	identificador = "";
	nombre = "";
	edad = 0;
	anioAlta = 0;
	marcaModeloCoche = "";
	opinionesUsuarios = new Pila<Opinion*>;

}
Conductor::Conductor(string identificador, string nombre, int edad, int anioAlta, string marcaModeloCoche){

	this->identificador = identificador;
	this->nombre = nombre;
	this->edad = edad;
	this->anioAlta = anioAlta;
	this->marcaModeloCoche = marcaModeloCoche;
	this->opinionesUsuarios =  new Pila<Opinion*>;

}
void Conductor::ponerIdentificador(string identificadorDado){
	this->identificador = identificadorDado;
}
void Conductor::ponerNombre(string nombreDado){
	this->nombre = nombreDado;
}
void Conductor::ponerEdad(int edadDada){
	this->edad = edadDada;
}
void Conductor::ponerMarcaModeloCoche(string marcaModeloCocheDado){
	this->marcaModeloCoche = marcaModeloCocheDado;
}
void Conductor::ponerOpinion(Opinion* op){
	opinionesUsuarios->apilar(op);
}
string Conductor::obtenerIdentificador(){
	return identificador;
}
string Conductor::obtenerNombre(){
	return nombre;
}
int Conductor::obtenerEdad(){
	return edad;
}
int Conductor::obtenerAnio(){
	return anioAlta;
}
string Conductor::obtenerMarcaModeloCoche(){
	return marcaModeloCoche;
}
void Conductor::obtenerOpinionesUsuario(){

	Pila<Opinion*>* pilaOpiniones1 = new Pila<Opinion*>;
	Opinion* op;

	while(!opinionesUsuarios->vacia()){

		opinionesUsuarios->cima(op);
		op->mostrarOpinion();
		pilaOpiniones1->apilar(op);
		opinionesUsuarios->desapilar();

	}
	while(!pilaOpiniones1->vacia()){

		pilaOpiniones1->cima(op);
		opinionesUsuarios->apilar(op);
		pilaOpiniones1->desapilar();

	}

	delete pilaOpiniones1;
}
void Conductor::obtenerMediaValoraciones(){

	float total = 0;
	int numOpiniones = 0;
	Pila<Opinion*>* pilaOpiniones1 = new Pila<Opinion*>;
	Opinion* op;

	while(!opinionesUsuarios->vacia()){

		opinionesUsuarios->cima(op);
		total = total + op->obtenerValoracionNumerica();
		pilaOpiniones1->apilar(op);
		opinionesUsuarios->desapilar();
		numOpiniones++;

	}

	while(!pilaOpiniones1->vacia()){

		pilaOpiniones1->cima(op);
		opinionesUsuarios->apilar(op);
		pilaOpiniones1->desapilar();

	}

	if (total > 0){
		total = (total / numOpiniones);
	}
	cout<<total<<endl;

	delete pilaOpiniones1;
}
void Conductor::mostrarConductor(){
	cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;

	cout<<"ID:"<<identificador<<" | Nombre:"<<nombre<<" | Edad:"<<edad<<" | Año del alta:"<<anioAlta<<" | Coche:"<<marcaModeloCoche<<endl;
	cout<<"\nOPinion/es: "<<endl;
	obtenerOpinionesUsuario();
	cout<<"Media de las opiniones: ";
	obtenerMediaValoraciones();

}
void Conductor::eliminarPilaOpiniones(){

	while(!opinionesUsuarios->vacia()){
		opinionesUsuarios->desapilar();
	}

}

Conductor::~Conductor() {
	delete opinionesUsuarios;

}

