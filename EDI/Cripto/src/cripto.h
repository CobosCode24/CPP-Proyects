/*
 * cripto.h
 *
 *  Autor: Manuel Cobos Solís
 *  Fecha: 28-04-2022
 *  Corrreo: mcobosso@unex.es
 */

#ifndef __CRIPTO_H
#define __CRIPTO_H

#include <iostream>
#include <fstream>
#include <string>

#include "bstree.h"
#include "mensaje.h"
#include "lpi.h"

using namespace std;


class Cripto {
		BSTree<KeyValue<int, mensaje*>>* arbolMensajes;
		int passwd;
		BSTree<KeyValue<char, char>>* abbCharChar;

private:

// *******************************************************************
// *                      OPERACIONES PRIVADAS						 *
// *******************************************************************

/*
 * EXPLICACIÓN= Carga la información del archivo 'mensajes.csv' y vuelca la informacion al arbol.
 * PRE=
 * POST=
 * COMPLEJIDAD= O(n)
 * */
   void cargarMensajes();

   /*
    * EXPLICACIÓN= Muestra todos los mensajes que contiene el arbol.
    * PRE= !arbolMensajesAux->empty()
    * POST=
    * COMPLEJIDAD= O(todo)
    * */
   void mostrarMensajes(BSTree<KeyValue<int, mensaje*> > *arbolMensajesAux);

   /*
    * EXPLICACIÓN= Busca si existe un mensaje en el arbol dado su id.
    * PRE=
    * POST= return true si el id está en el arbol, false si no lo está.
    * COMPLEJIDAD= O(todo)
    * */
   bool buscarMensaje(BSTree<KeyValue<int, mensaje*>>* arbolAux, const int data, mensaje* &m);

   /*
    * EXPLICACIÓN= Busca si la letraO (letra Original) esta en el arbol de caracteres. Si es así,
    * 			   la sustituye por su correspondiente.
    * PRE= buscarMensajes(arbolMensajes, id, m) == true
    * POST=
    * COMPLEJIDAD= O(todo)
    * */
   bool buscarLetra(BSTree<KeyValue<char, char>> *abbAux, char letraO, char &letraS);

   /*
    * EXPLICACIÓN= Busca si la letraCodificada está en el arbol de caracteres. Si es así,
    * 			   la sustituye por su letraOriginal.
    * PRE=
    * POST=
    * COMPLEJIDAD= O(todo)
    * */
   void buscarCaracter(BSTree<KeyValue<char, char>> *abbAux, char letraCodificada, char &letraOriginal, bool &enc);

   /*
    * EXPLICACIÓN= Busca todos los mensajes que hay en el arbol de un mismo autor.
    * PRE=
    * POST=
    * COMPLEJIDAD= O(todo)
    * */
   void buscarMensajePorAutor(BSTree<KeyValue<int, mensaje*>>* bstAux, string autor, LPI<mensaje*>* &l);

   
public:

   // PRE  = { }
   // POST = { passwd = 0 }
   // DESC:  Carga datos de mensajes en el sistema.
   // COMPL:
   Cripto      ();
      
   // *******************************************************************
   // *                      OPERACIONES PÚBLICAS						*
   // *******************************************************************

   /*
    * EXPLICACIÓN= Obtiene los datos necesarios del caso 1.
    * PRE=
    * POST=
    * COMPLEJIDAD= O(1)
    * */
   void obtenerCasoUno(int &identificadorDado, string &textoDado, string &autorDado);

   /*
    * EXPLICACIÓN=Obtiene los datos necesarios del caso 1.
    * PRE=
    * POST=
    * COMPLEJIDAD=O(1)
    * */
   void obtenerCasoDos(int &identificadorDado);

   /*
    * EXPLICACIÓN=Obtiene los datos necesarios del caso 1.
    * PRE=
    * POST=
    * COMPLEJIDAD=O(1)
    * */
   void obtenerCasoTres(int &identificadorDado);

   /*
    * EXPLICACIÓN=Obtiene los datos necesarios del caso 1.
    * PRE=
    * POST=
    * COMPLEJIDAD=O(1)
    * */
   void obtenerCasoCinco(string &autorDado);

   /*
    * EXPLICACIÓN= Muestra una lista de una serie de mensajes.
    * PRE=
    * POST=
    * COMPLEJIDAD= O(n)
    * */
   void bucleMensajePorAutor(LPI<mensaje*> *l);

   /*
    * EXPLICACIÓN= Llama recursivamente al buscarmensaje()
    * PRE=
    * POST=
    * COMPLEJIDAD= O(todo)
    * */
   void buscarMensaje();

   /*
    * EXPLICACIÓN= Llama recursivamente al buscarLetra()
    * PRE=
    * POST=
    * COMPLEJIDAD= O(todo)
    * */
   void buscarLetra(char letraO, char letraS);

   /*
    * EXPLICACIÓN= Llama recursivamente a buscarCaracter()
    * PRE=
    * POST=
    * COMPLEJIDAD= O(todo)
    * */
   void buscarCaracter(char letraCodificada, char letraOriginal, bool &enc);

   /*
    * EXPLICACIÓN= inserta un mensaje en el arbol.
    * PRE= buscarMensaje(arbolMensajes, id, m) == false
    * POST=
    * COMPLEJIDAD= O(todo)
    * */
   void insertarMensaje(mensaje* m);

   /*
    * EXPLICACIÓN= Borra un mensaje del arbol.
    * PRE= buscarMensaje(arbolMensajes, identificador, m) == true
    * POST=
    * COMPLEJIDAD= O(todo)
    * */
   void borrarMensaje(int identificador);

   /*
    * EXPLICACIÓN= Busca y muestra un mensaje del arbol dado su identificador.
    * PRE=
    * POST=
    * COMPLEJIDAD= O(todo)
    * */
   void buscarMensajePorID(int id);

   /*
    * EXPLICACIÓN= Llamada recursiva a mostrarMensajes()
    * PRE=
    * POST=
    * COMPLEJIDAD= O(todo)
    * */
   void mostrarMensajes();

   /*
    * EXPLICACIÓN= Llamada recursiva a buscarMensajePorAutor()
    * PRE=
    * POST=
    * COMPLEJIDAD= O(todo)
    * */
   void buscarMensajePorAutor(string autorDado, LPI<mensaje*> *&l);

   // PRE  = { }
   // POST = { this->passwd = passwd % 26, if (passwd==0) then 1 }
   // DESC:  Establece una contraseña y la guarda codificada. En realidad, es un
   //        desplazamiento de cada una de las 26 letras entre 1 y 25.
   // COMPL:
   void cambiarContrasenia (int passwd);

   /*
    * EXPLICACIÓN= Llamada recursiva al modulo buscarDevolverMensajePorID()
    * PRE=
    * POST=
    * COMPLEJIDAD= O(todo)
    * */
   void buscarDevolverMensajePorID(int id, mensaje* &m);

   /*
    * EXPLICACIÓN= Dada la id de un mensaje, busca el texto que se desea codificar y letra por letra
    * 			   se va codificando.
    * PRE= Debe de haberse seleccionado el modo de encriptamiento en la opcion 6 del programa.
    * POST=
    * COMPLEJIDAD= O(todo)
    * */
   void Codificar(int id);

   /*
    * EXPLICACIÓN= Hace un recorrido a todoo el arbol hasta que enc=true, entonces a partir del k.value()
    * 			   (que es por lo que estamos buscando), obtenemos el k.key() que seria la letra original
    * 			   antes de haber sido codificada.
    * PRE=
    * POST=
    * COMPLEJIDAD= O(todo)
    * */
   void Decodificar(int id);

   /*
    * EXPLICACIÓN= Hace un recorrido pre-orden al arbol y va volcando la informacion de cada nodo del
    * 			   arbol a un fichero .csv
    * PRE= !escritura.fail()
    * POST=
    * COMPLEJIDAD= O(todo)
    * */
   void preOrden(BSTree<KeyValue<int, mensaje*>> *aux,ofstream &escritur);

   /*
    * EXPLICACIÓN= Llama al modulo preOrden con el fin de vaciar el arbol de la informacion y volcarlos
    * 			   a un arvhivo externo.
    * PRE=
    * POST=
    * COMPLEJIDAD= O(todo)
    * */
   void finalizarAplicacion();


	~Cripto();
};


#endif /* __CRIPTO_H */
