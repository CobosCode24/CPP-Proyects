/*
 * cripto.cpp
 *
 *  Autor: Manuel Cobos Solís
 *  Fecha: 28-04-2022
 *  Corrreo: mcobosso@unex.es
 */

#include <iostream>
#include <fstream>
#include <string>

#include "cripto.h"

using namespace std;


// *******************************************************************
// *                      OPERACIONES PRIVADAS						 *
// *******************************************************************

void Cripto::cargarMensajes() {
	mensaje *m;
	ifstream leer;
	int id = 0;
	string idString = "", texto = "", autor = "";

	leer.open("mensajes.csv");
	if (leer.is_open()) {
		while (!leer.eof()) {

			getline(leer, idString, '#');
			getline(leer, texto, '#');
			getline(leer, autor, '\n');

			if (leer) {
				id = stoi(idString);

				m = new mensaje(id, texto, autor);

				KeyValue<int, mensaje*> nodo(id, m);

				arbolMensajes->insert(nodo);

			}

		}
		leer.close();
	} else {
		cout << "FICHERO NO ENCONTRADO..." << endl;
	}
}

void Cripto::mostrarMensajes(BSTree<KeyValue<int, mensaje*> > *arbolAuxiliar) {

	BSTree<KeyValue<int, mensaje*>> *aux;
	//Recorrido in orden:

	if (!arbolAuxiliar->empty()) {

		aux = arbolAuxiliar->left();
		if (aux != NULL) {
			mostrarMensajes(aux);
		}
		KeyValue<int, mensaje*> KeyValue = arbolAuxiliar->root();
		mensaje *m = KeyValue.value();
		m->mostrarMensaje();

		aux = arbolAuxiliar->right();
		if (aux != NULL) {
			mostrarMensajes(aux);
		}
	}
}

bool Cripto::buscarMensaje(BSTree<KeyValue<int, mensaje*>> *arbolAux, const int data, mensaje *&m) {

	KeyValue<int, mensaje*> k;
	int id;
	bool enc = false;

	if (arbolAux->empty()) {

		enc = false;

	} else {

		BSTree<KeyValue<int, mensaje*>> *aux;
		aux = nullptr;

		k = arbolAux->root();
		id = k.key();
		if (data < id) {
			aux = arbolAux->left();
			if (aux != nullptr) {
				enc = buscarMensaje(aux, data, m);

			}

		} else if (data > id) {
			aux = arbolAux->right();
			if (aux != nullptr)
				enc = buscarMensaje(aux, data, m);
		} else {
			m = k.value();
			enc = true;
		}
	}
	return enc;
}

bool Cripto::buscarLetra(BSTree<KeyValue<char, char>> *abbAux, char letraO, char &letraS) {

	KeyValue<char, char> k;
	bool enc = false;
	if (abbAux->empty()) {

		enc = false;

	} else {

		BSTree<KeyValue<char, char>> *aux;
		aux = nullptr;

		k = abbAux->root();

		if (letraO < k.key()) {
			aux = abbAux->left();
			if (aux != nullptr) {
				enc = buscarLetra(aux, letraO, letraS);

			}

		} else if (letraO > k.key()) {
			aux = abbAux->right();
			if (aux != nullptr)
				enc = buscarLetra(aux, letraO, letraS);
		} else {
			enc = true;
			letraS = k.value();
		}
	}
	return enc;
}

void Cripto::buscarCaracter(BSTree<KeyValue<char, char>> *abbAux, char letraCodificada, char &letraOriginal, bool &enc) {

	BSTree<KeyValue<char, char>> *aux;

	if (!abbAux->empty()) {
		KeyValue<char, char> kv = abbAux->root();
		if (kv.value() == letraCodificada) {
			enc = true;
			letraOriginal = kv.key();
		} else {
			if (!enc) {
				aux = abbAux->left();
				if (aux != NULL) {
					buscarCaracter(aux, letraCodificada, letraOriginal, enc);
				}
			}
			if (!enc) {
				aux = abbAux->right();
				if (aux != NULL) {
					buscarCaracter(aux, letraCodificada, letraOriginal, enc);
				}
			}
		}
	}

}

void Cripto::buscarMensajePorAutor(BSTree<KeyValue<int, mensaje*>> *bstAux, string autor, LPI<mensaje*> *&l) {

	BSTree<KeyValue<int, mensaje*>> *aux;
	KeyValue<int, mensaje*> k;
	mensaje *m;

	if (!bstAux->empty()) {
		k = bstAux->root();
		m = k.value();
		if (m->obtenerAutorMensaje() == autor) {
			l->insertar(m);
			l->avanzar();
		}
		aux = bstAux->left();
		if (aux != NULL) {
			buscarMensajePorAutor(aux, autor, l);
		}
		aux = bstAux->right();
		if (aux != NULL) {
			buscarMensajePorAutor(aux, autor, l);
		}
	}
}


// *******************************************************************
// *                      OBTENER DATOS      						 *
// *******************************************************************

void Cripto::obtenerCasoUno(int &identificadorDado, string &textoDado, string &autorDado) {

	cout << "\nIntroduce el identificador: ";
	cin >> identificadorDado;
	cin.ignore();
	cout << "\nIntroduce el mensaje a enviar: ";
	getline(cin, textoDado);
	cout << "\nIntroduce el autor del mensaje: ";
	getline(cin, autorDado);

}

void Cripto::obtenerCasoDos(int &identificadorDado) {
	cout << "Introduce el identificador del mensaje que desea borrar: ";
	cin >> identificadorDado;
}

void Cripto::obtenerCasoTres(int &identificadorDado) {
	cout << "Introduce el id del mensaje: ";
	cin >> identificadorDado;
}

void Cripto::obtenerCasoCinco(string &autorDado) {
	cout << "Introduce el nombre del autor del mensaje: ";
	getline(cin, autorDado);
}

void Cripto::bucleMensajePorAutor(LPI<mensaje*> *l) {
	mensaje *m;
	if (!l->vacia()) {
		l->moverInicio();
		while (!l->enFin()) {
			l->consultar(m);
			m->mostrarMensaje();
			l->avanzar();
		}
	}
}


// *******************************************************************
// *                     INTERFAZ PUBLICA							 *
// *******************************************************************

Cripto::Cripto() {
	arbolMensajes = new BSTree<KeyValue<int, mensaje*>>();
	cargarMensajes();
	abbCharChar = new BSTree<KeyValue<char, char>>();
}

void Cripto::mostrarMensajes() {
	mostrarMensajes(arbolMensajes);
}

void Cripto::buscarMensaje() {
	int data;
	mensaje *m;
	buscarMensaje(arbolMensajes, data, m);
}

void Cripto::buscarLetra(char letraO, char letraS) {
	buscarLetra(abbCharChar, letraO, letraS);
}

void Cripto::buscarMensajePorAutor(string autorDado, LPI<mensaje*> *&l) {
	buscarMensajePorAutor(arbolMensajes, autorDado, l);
}

void Cripto::buscarMensajePorID(int id) {
	mensaje *m;

	if (buscarMensaje(arbolMensajes, id, m) == true) {
		m->mostrarMensaje();
	} else {
		cout << "El identificador no ha sido encontrado... " << endl;
	}
}

void Cripto::insertarMensaje(mensaje *m) {
	int id = 0;
	id = m->obtenerIdentificador();
	KeyValue<int, mensaje*> k(id, m);

	if (buscarMensaje(arbolMensajes, id, m) == false) {
		arbolMensajes->insert(k);
		cout << "Mensaje insertado..." << endl;
	} else {
		cout << "El identificador ya existe..." << endl;
	}
}

void Cripto::borrarMensaje(int identificador) {
	mensaje *m = new mensaje();
	KeyValue<int, mensaje*> k(identificador, m);

	if (buscarMensaje(arbolMensajes, identificador, m) == true) {
		arbolMensajes->remove(k);
		cout<<"Mensaje borrado correctamente..."<<endl;
	} else {
		cout << "Este mensaje no existe... " << endl;
	}
}

void Cripto::cambiarContrasenia(int pin) {

	delete abbCharChar;
	abbCharChar = new BSTree<KeyValue<char, char>>;


	this->passwd = pin % 26;
	if (this->passwd == 0) { // No permitimos que sea 0.
		this->passwd++;
	}

// Letras al árbol.
// El orden de las letras en el vector hace que el árbol resultante este equilibrado:
	char c_origen[26] = { 'm', 'g', 's', 'd', 'j', 'p', 'w', 'b', 'e', 'h', 'k',
			'n', 'r', 'u', 'y', 'a', 'c', 'f', 'i', 'l', 'o', 'q', 't', 'v',
			'x', 'z' };

	for (int i = 0; i < 26; i++) {
		char letraO, letraS;

		letraO = c_origen[i];
		letraS = (((int(letraO) - 97) + this->passwd) % 26) + 97;
		KeyValue<char, char> k(letraO, letraS);
		abbCharChar->insert(k);

	}
}

void Cripto::buscarDevolverMensajePorID(int id, mensaje *&m) {
	buscarMensaje(arbolMensajes, id, m);
}

void Cripto::buscarCaracter(char letraCodificada, char letraOriginal, bool &enc) {
	buscarCaracter(abbCharChar, letraCodificada, letraOriginal, enc);
}

void Cripto::Codificar(int id) {
	int i;
	mensaje *m;
	string mensajeOriginal;
	char letraO; //letra Original.
	char letraS; //letra sustituida.
	KeyValue<char, char> k;

	if (buscarMensaje(arbolMensajes, id, m) == true) {
		mensajeOriginal = m->obtenerTexto();

		for (i = 0; i < mensajeOriginal.length(); i++) {
			letraO = mensajeOriginal[i];
			if (abbCharChar != NULL) {
				if (buscarLetra(abbCharChar, letraO, letraS)) {
					mensajeOriginal[i] = letraS;
				}
			}
		}
		m->ponerTexto(mensajeOriginal);
		cout << "Mensaje codificado con exito..." << endl;
	}
}

void Cripto::Decodificar(int id) {
	string mensajeCodificado = "", mensajeNoCodificado ;
	char letraCodificada, letraOriginal;
	mensaje *m;
	int i = 0;
	bool enc = false;

	if (buscarMensaje(arbolMensajes, id, m) == true) {
		mensajeCodificado = m->obtenerTexto(); //Obtengo en mensaje codificado.
		mensajeNoCodificado=mensajeCodificado;
		for (i = 0; i < mensajeCodificado.length(); i++) {
			letraCodificada = mensajeCodificado[i]; //Obtengo el caracter codificádo.
			enc=false;
			buscarCaracter(abbCharChar, letraCodificada, letraOriginal, enc);
			if (enc)
				mensajeNoCodificado[i] = letraOriginal;
		}
		m->ponerTexto(mensajeNoCodificado);
		cout << "Mensaje Decodificado con exito..." << endl;
	}
}
void Cripto::preOrden(BSTree<KeyValue<int, mensaje*>> *abbMensajes,ofstream &escritura){

	BSTree<KeyValue<int, mensaje*>>* aux;
	KeyValue<int, mensaje*> k;
	mensaje* m;

	int id;
	string texto, autor;

	if(!abbMensajes->empty()){

		k=abbMensajes->root();
		m = k.value();
		id = m->obtenerIdentificador();
		texto = m->obtenerTexto();
		autor = m->obtenerAutorMensaje();
		escritura<<id<<"#"<<texto<<"#"<<autor<<endl;


		aux = abbMensajes->left();
		if(aux != NULL) {
			preOrden(aux,escritura);
		}


		aux = abbMensajes->right();
		if(aux != NULL) {
			preOrden(aux,escritura);
		}

	}

}

void Cripto::finalizarAplicacion() {
	ofstream escritura;

	escritura.open("mensajes.csv");
	if(!escritura.fail()) {
		preOrden (arbolMensajes,escritura);

		escritura.close();
	}

	cout<<"\n\n\n\t Gracias por utilizar nuestro servicio de criptografía, ¡ Hasta pronto !"<<endl;
}

Cripto::~Cripto(){

	delete abbCharChar;
	delete arbolMensajes;

}
