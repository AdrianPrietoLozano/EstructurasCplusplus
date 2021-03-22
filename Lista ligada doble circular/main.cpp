#include <iostream>
#include <string>
#include "ListaDoblementeLigadaCircular.h"

using namespace std;

template < typename E >
void mostrar( ListaDoblementeLigadaCircular< E > & );

int main( void )
{
	ListaDoblementeLigadaCircular< string > lista;

	lista.ponAlFinal( "Abeja" );
	lista.ponAlFinal( "Elefante" );
	lista.ponAlFinal( "Iguana" );
	lista.ponAlFinal( "Oso" );
	lista.ponAlFinal( "Urraca" );

	cout << endl;
	cout << "LISTA ORIGINAL" << endl;
	mostrar( lista );

	cout << endl;

	lista.irAlInicio();
	for( int i = 0; i < lista.obtenerTamanio() * 2; i++ )
	{
		cout << "El elemento actual es \"" << lista.obtenerElemento() << "\"" << endl;
		lista.anterior();
	}

	cout << endl;

	lista.irAlFinal();
	for( int i = 0; i < lista.obtenerTamanio() * 2; i++ )
	{
		cout << "El elemento actual es \"" << lista.obtenerElemento() << "\"" << endl;
		lista.siguiente();
	}

	cout << endl;
	
	int tamanio = lista.obtenerTamanio();

	cout << "LISTA ORIGINAL" << endl;
	mostrar( lista );
	cout << endl;

	for( int i = 0; i < tamanio; i++ )
	{
		lista.irAlInicio();
		cout << "Se elimino \"" << lista.eliminar() << "\" de la lista" << endl;
		mostrar( lista );
		cout << endl;
	}

	return 0;
}

template < typename E >
void mostrar( ListaDoblementeLigadaCircular< E > &L )
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

	if( posOriginal )
		L.irAPosicion( posOriginal );
}