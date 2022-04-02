#ifndef VOVUSUARIOS_H_
#define VOVUSUARIOS_H_
#include <iostream>
#include "Usuarios.h"
using namespace std;

const int MAX_USUARIOS = 200;


class VoV_Usuarios {
private:
	Usuario* VU [MAX_USUARIOS];
	int posicion;

public:

	/*
	 * EXPLICACION: Es el constructor. Inicializa la posicion a 0.
	 * COMPLEJIDAD: O(1)
	 * PRE:
	 * POST:
	 */
	VoV_Usuarios();

	/*
	 * EXPLICACION: Inserta un nuevo usuario al VoV de usuarios.
	 * COMPLEJIDAD: O(1).
	 * PRE: Suponemos que hay espacio en el VoV.
	 * POST: Inserta el usuario.
	 */
	void insertarUsuario(Usuario* u);

	/*
	 * EXPLICACION: Elimina a un usuario del VoV a traves de su dni.
	 * COMPLEJIDAD: O(n)
	 * PRE: El dni dado debe existir.
	 * POST: Elimina al usuario si ha encontrado el dni.
	 */
	void eliminarUsuario(string dni);

	/*
	 * EXPLICACION: Obtiene toda la informacion de un usuario sabiendo en la posicion
	 * 				del VoV en la que se encuentra.
	 * COMPLEJIDAD: O(1)
	 * PRE: La posicion dada debe ser mayor o igual a 0.
	 * POST: Develve el usuario que esta en esa posicion.
	 */
	Usuario* obtenerUsuarioPOS(int posicion);

	/*
	 * EXPLICACION: Obteiene toda la informacion de un usuario sabiendo su dni.
	 * COMPLEJIDAD: O(n)
	 * PRE: El dni debe de ser valido.
	 * POST: Devuelve al usuario con ese dni.
	 */
	Usuario* obtenerUsuarioDNI(string dni);

	/*
	 * EXPLICACION: Comprueba si existe un usuario en el VoV a traves de su dni.
	 * COMPLEJIDAD: O(n)
	 * PRE: El dni introducido debe ser valido. En caso contrario, no se eliminara.
	 * POST: Si se ha encontrado el usuario, será eliminado.
	 */
	bool existeUsuario(string dni);

	/*
	 * EXPLICACION: Devuelve la cantidad de usuarios que hay en el VoV.
	 * COMPLEJIDAD: O(1)
	 * PRE:
	 * POST:
	 */
	int cuantosUsuario();

	/*
	 * EXPLICACION: Obtiene si el libro esta prestado o no?
	 * COMPLEJIDAD: O(n)
	 * PRE: El titulo del libro debe de existir.
	 * POST: Devuelve true si el libro esta prestado o false si el libro esta si prestar.
	 * */
	bool libroPrestado(string titulo);

	/*
	 * EXPLICACION: Destructor. Elimina todos los usuarios del VoV.
	 * COMPLEJIDAD: O(n)
	 * PRE:
	 * POST:
	 */

	virtual ~VoV_Usuarios();

};

#endif /* VOVUSUARIOS_H_ */
