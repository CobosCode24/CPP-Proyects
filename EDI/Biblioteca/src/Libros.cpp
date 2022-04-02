#include "Libros.h"
#include <iostream>
using namespace std;

Libro::Libro() {

	// CONSTRUCTOR.
	// Inicio las variables titulo, autor, tematica, anio, paginas.

	titulo = "";
	autor = "";
	tematica = "";
	anio = "";
	paginas = "";

}

string Libro::obtenerTitulo(){
	return titulo;
}

void Libro::ponerTitulo(string titulo){
	this->titulo=titulo;
}

string Libro::obtenerAutor(){
	return autor;
}

void Libro::ponerAutor(string autor){
	this->autor=autor;
}

string Libro::obtenerTematica(){
	return tematica;
}

void Libro::ponerTematica(string tematica){
	this->tematica=tematica;
}

string Libro::obtenerAnio(){
	return anio;
}

void Libro::ponerAnio(string anio){
	this->anio=anio;
}

string Libro::obtenerPaginas(){
	return paginas;
}
void Libro::ponerPaginas(string paginas){
	this->paginas=paginas;
}

void Libro::generarID(){
	string tit=titulo.substr(0, 3);
	string aut=autor.substr(0, 3);
	ID=tit+"."+aut+"."+anio;
}

string Libro::obtenerID(){
	return ID;
}

void Libro::ponerID(string ID){
	this->ID=ID;
}

void Libro::mostrarLibro(){

	cout<<"\nTitulo: "<<obtenerTitulo()<<"| Autor: "<<obtenerAutor()<<"| Tematica: "<<obtenerTematica()<<"| Año: "<<obtenerAnio()<<"| Paginas: "<<obtenerPaginas()<<"| ID: "<<obtenerID()<<endl;

}

Libro::~Libro() {

	// DESTRUCTOR.

}

