#include "VoVUsuarios.h"

VoV_Usuarios::VoV_Usuarios(){

	// CONSTRUCTOR.

	posicion = 0;

}

void VoV_Usuarios::insertarUsuario(Usuario* u){

	if(posicion < MAX_USUARIOS){
		VU[posicion] = u;
		posicion++;
	}

}
void VoV_Usuarios::eliminarUsuario(string dni){
	int i = 0;
	bool enc = false;

	while(i < posicion && !enc){

		if(VU[i]->getDni() == dni){
			enc = true;
			delete VU[i];
			VU[i] = VU[posicion-1];
			VU[posicion-1] = NULL;
			posicion--;
		}
		else{
			i++;
		}
	}

}
Usuario* VoV_Usuarios::obtenerUsuarioPOS(int pos){
	return (VU[pos]);
}
Usuario* VoV_Usuarios::obtenerUsuarioDNI(string dni){
	int i = 0;
	bool enc = false;

	while(i < posicion && !enc){

		if(VU[i]->getDni() == dni){
			enc = true;
		}
		else{
			i++;
		}

	}

	return VU[i];
}
bool VoV_Usuarios::existeUsuario(string dni){
	bool resultado = false;
	int i = 0;

	while ((i < cuantosUsuario()) && !resultado) {
		if(VU[i]->getDni() == dni){
			resultado = true;
		}
		else{
			i++;
		}

	}

	return resultado;
}
int VoV_Usuarios::cuantosUsuario(){
	return posicion;
}

bool VoV_Usuarios::libroPrestado(string titulo){
	bool resultado = false;
	int i = 0;
	Usuario* u = NULL;

	while(i < cuantosUsuario() && !resultado){

		u->mostrarUsuario();
		if(u->getPrestado() == titulo){
			resultado = true;
		}
		else{
			i++;
		}
	}

	return resultado;
}

VoV_Usuarios::~VoV_Usuarios() {

	//DESTRUCTOR
	int i;
	for(i = 0 ; i<posicion ; i++){
		delete VU[i];
	}
	posicion=0;

}


