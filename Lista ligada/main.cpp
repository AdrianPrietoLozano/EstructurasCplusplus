#include <iostream>
#include "ListaLigada.h"

using namespace std;

template < typename E >
void mostrar( ListaLigada< E > & );

int main( void )
{
	ListaLigada< int > lista;

	mostrar( lista );
	cout << "El tamanio de la lista es: " << lista.obtenerTamanio() << endl;
	lista.ponAlFinal( 1 );
	lista.ponAlFinal( 2 );
	lista.ponAlFinal( 3 );
	lista.ponAlFinal( 4 );
	lista.ponAlFinal( 5 );
	mostrar( lista );
	lista.irAPosicion( 2 );
	lista.insertar( 6 );
	mostrar( lista );
	cout << "El tamanio de la lista es: " << lista.obtenerTamanio() << endl;
	cout << "Se elimino el elemento " << lista.eliminar() << " de la lista." << endl;
	mostrar( lista );
	cout << "El tamanio de la lista es: " << lista.obtenerTamanio() << endl;
	lista.ponAlFinal( 7 );
	lista.ponAlFinal( 8 );
	cout << "La posicion actual es: " << lista.posicionActual() << endl;
	lista.irAPosicion( 5 );
	cout << "La posicion actual es: " << lista.posicionActual() << endl;
	lista.insertar( 9 );
	mostrar( lista );
	cout << "El tamanio de la lista es: " << lista.obtenerTamanio() << endl;
	lista.siguiente();
	cout << "La posicion actual es: " << lista.posicionActual() << endl;
	lista.ponAlFinal( 6 );
	lista.ponAlFinal( 10 );
	mostrar( lista );
	cout << "El tamanio de la lista es: " << lista.obtenerTamanio() << endl;
	lista.irAlFinal();
	cout << "El ultimo elemento de la lista es: " << lista.obtenerElemento() << endl;
	lista.irAlInicio();
	cout << "El primer elemento de la lista es: " << lista.obtenerElemento() << endl;
	cout << "Se elimino el elemento " << lista.eliminar() << " de la lista" << endl;
	mostrar( lista );
	lista.vaciar();
	cout << "El tamanio de la lista es " << lista.obtenerTamanio() << endl;
	

	return 0;
}

template < typename E >
void mostrar( ListaLigada< E > &L )
{
	int posOriginal = L.posicionActual();
	L.irAlInicio();

	cout << "[";
	for( int i = 0; i < L.obtenerTamanio(); i++ )
	{
		cout << L.obtenerElemento();
		if( !( i == ( L.obtenerTamanio() - 1 ) ) )
		{
			cout << ", ";
			L.siguiente();
		}
	}
	cout << "]" << endl;

	L.irAPosicion( posOriginal );
}