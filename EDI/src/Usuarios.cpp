#include "Usuarios.h"
#include <iostream>
using namespace std;

Usuario::Usuario() {

	//CONSTRUCTOR.
	// Inicializo las variables dni, nombre, apellido, correo, prestado.

	dni = "";
	nombre = "";
	apellido = "";
	correo = "";
	prestado = "";

}


string Usuario::getApellido()  {
	return apellido;
}

void Usuario::setApellido( string apellido) {
	this->apellido = apellido;
}

string Usuario::getCorreo()  {
	return correo;
}

void Usuario::setCorreo( string correo) {
	this->correo = correo;
}

string Usuario::getDni()  {
	return dni;
}

void Usuario::setDni( string dni) {
	this->dni = dni;
}

string Usuario::getNombre()  {
	return nombre;
}

void Usuario::setNombre( string nombre) {
	this->nombre = nombre;
}

string Usuario::getPrestado()  {
	return prestado;
}

void Usuario::setPrestado( string prestado) {
	this->prestado = prestado;
}

void Usuario::mostrarUsuario(){

	cout<<getDni()<<"  "<<getNombre()<<"  "<<getApellido()<<"  "<<getCorreo()<<"  "<<getPrestado()<<endl;

}

Usuario::~Usuario() {

	//DESTRUCTOR.

}
