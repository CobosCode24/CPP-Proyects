#include <iostream>
using namespace std;
#include "vov_libros.h"

VoV_Libros::VoV_Libros() {

	// CONSTRUCTOR.
	posicion = 0;

}

void VoV_Libros::insertarLibro(Libro *l) {

	if(posicion < MAX_LIBROS){
		VL[posicion] = l;
		posicion++;
	}

}
void VoV_Libros::eliminarLibro(string titulo) {
	int i = 0;
	bool enc = false;

	while(i < posicion && !enc){

		if(VL[i]->obtenerTitulo()== titulo){
			enc = true;
			delete VL[i];
			VL[i] = VL[posicion-1];
			VL[posicion-1] = NULL;
			posicion--;
		}
		else{
			i++;
		}
	}

}
Libro* VoV_Libros::obtenerLibroPOS(int pos) {
	return (VL[pos]);
}
Libro* VoV_Libros::obtenerLibroID(string ID) {
	int i = 0;
	bool enc = false;

	while(i < posicion && !enc){

		if(VL[i]->obtenerID() == ID){
			enc = true;
		}
		else{
			i++;
		}

	}

	return VL[i];
}
bool VoV_Libros::existeLibro(string ID) {
	bool resultado = false;
	int i = 0;

	while ((i < cuantosLibro()) && !resultado) {
		if (VL[i]->obtenerID() == ID){
			resultado = true;
		}
		else{
			i++;
		}

	}

	return resultado;
}
int VoV_Libros::cuantosLibro() {
	return posicion;
}

VoV_Libros::~VoV_Libros() {

	// DESTRUCTOR.
	int i;
	for(i = 0 ; i<posicion ; i++){
		delete VL[i];
	}
	posicion=0;

}
