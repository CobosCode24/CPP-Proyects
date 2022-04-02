#include <iostream>
#include "Opinion.h"

using namespace std;


Opinion::Opinion() {
	valoracionNumerica = 0;
	opinion = "";
}
Opinion::Opinion(int valoracionNumericaDada, string opinionDada){
	this->valoracionNumerica = valoracionNumericaDada;
	this->opinion = opinionDada;
}
void Opinion::ponerValoracionNumerica(int valoracionNumericaDada){
	this->valoracionNumerica = valoracionNumericaDada;
}
void Opinion::ponerOpinion(string opinion){
	this->opinion = opinion;
}
int Opinion::obtenerValoracionNumerica(){
	return valoracionNumerica;
}
string Opinion::obtenerOpinion(){
	return opinion;
}
void Opinion::mostrarOpinion(){
	cout<<"Valoracion: "<<valoracionNumerica<<" | Opinion: "<<opinion<<endl;
}
Opinion::~Opinion() {

}

