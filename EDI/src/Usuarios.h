#ifndef USUARIOS_H_
#define USUARIOS_H_
#include <iostream>
using namespace std;

class Usuario {

private:
	string dni;
	string nombre;
	string apellido;
	string correo;
	string prestado;

public:

	/*
	 * EXPLICACION: Inicializa el dni, nombre, apellido, correo, prestado.
	 * COMPLEJIDAD: O(1)
	 * PRE
	 * POST:
	 */
	Usuario();

	/*
	 * EXPLICACION: Obtiene el apellido de un usuario.
	 * COMPLEJIDAD: O(1).
	 * PRE:
	 * POST:
	 */
	string getApellido();

	/*
	 * EXPLICACION: Pone el apellido a una persona.
	 * COMPLEJIDAD: O(1)
	 * PRE: El usuario ha de existir.
	 * POST:
	 */
	void setApellido( string apellido);

	/*
	 * EXPLICACION: Obtiene el apellido de un usuario.
	 * COMPLEJIDAD: O(1)
	 * PRE:
	 * POST:
	 */
	string getCorreo();

	/*
	 * EXPLICACION: Pone la direccion de correo electronico a un usuario.
	 * COMPLEJIDAD: O(1)
	 * PRE: El usuario ha de existir.
	 * POST:
	 */
	void setCorreo( string correo);

	/*
	 * EXPLICACION: Obtiene el apellido de un usuario.
	 * COMPLEJIDAD: O(1)
	 * PRE:
	 * POST:
	 */
	string getDni();

	/*
	 * EXPLICACION:  Pone el dni a un usuario.
	 * COMPLEJIDAD: O(1)
	 * PRE: El usuario ha de existir.
	 * POST:
	 */
	void setDni( string dni);

	/*
	 * EXPLICACION: Obtiene el apellido de un usuario.
	 * COMPLEJIDAD: O(1)
	 * PRE:
	 * POST:
	 */
	string getNombre();

	/*
	 * EXPLICACION: Pone el nombre a un usuario.
	 * COMPLEJIDAD: O(1)
	 * PRE: El usuario ha de existir.
	 * POST:
	 */
	void setNombre( string nombre);

	/*
	 * EXPLICACION: Obtiene el estado de prestamo de un usuario.
	 * COMPLEJIDAD: O(1)
	 * PRE:
	 * POST: Devolvera 'con-prestamo' o 'sin-prestamo'.
	 */
	string getPrestado();

	/*
	 * EXPLICACION: Pone el estado de prestamo de un usuario.
	 * COMPLEJIDAD: O(1)
	 * PRE: El usuario ha de existir.
	 * POST:
	 */
	void setPrestado( string prestado);

	/*
	 * EXPLICACION: Muestra toda la informacion de un determinado usuario.
	 * COMPLEJIDAD: O(1)
	 * PRE:
	 * POST:
	 */
	void mostrarUsuario();

	/*
	 * EXPLICACION: Destructor.
	 * COMPLEJIDAD: O(1)
	 * PRE:
	 * POST:
	 */
	virtual ~Usuario();

};

#endif /* USUARIOS_H_ */
