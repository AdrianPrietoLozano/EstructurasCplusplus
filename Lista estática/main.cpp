#include <iostream>
#include "listaEstatica.h"
using namespace std;

void mostrar( ListaEstatica<int> & );

int main( void )
{
	ListaEstatica< int > miLista( 10 );

	//miLista.anterior(); // produce una falla
	mostrar( miLista );
	cout << "El tamanio de la lista es: " << miLista.tamanio() << endl;
	miLista.ponAlFinal( 1 );
	miLista.ponAlFinal( 2 );
	miLista.ponAlFinal( 3 );
	miLista.ponAlFinal( 4 );
	miLista.ponAlFinal( 5 );
	mostrar( miLista );
	miLista.irAPosicion( 2 );
	miLista.insertar( 6 );
	mostrar( miLista );
	cout << "El tamanio de la lista es: " << miLista.tamanio() << endl;
	cout << "Se elimino el elemento " << miLista.eliminar() << " de la lista." << endl;
	mostrar( miLista );
	cout << "El tamanio de la lista es: " << miLista.tamanio() << endl;
	miLista.ponAlFinal( 7 );
	miLista.ponAlFinal( 8 );
	cout << "La posicion actual es: " << miLista.posicionActual() << endl;
	miLista.irAPosicion( 5 );
	cout << "La posicion actual es: " << miLista.posicionActual() << endl;
	miLista.insertar( 9 );
	mostrar( miLista );
	cout << "El tamanio de la lista es: " << miLista.tamanio() << endl;
	miLista.siguiente();
	cout << "La posicion actual es: " << miLista.posicionActual() << endl;
	miLista.ponAlFinal( 6 );
	miLista.ponAlFinal( 10 );
	mostrar( miLista );
	cout << "El tamanio de la lista es: " << miLista.tamanio() << endl;
	miLista.irAlFinal();
	cout << "El ultimo elemento de la lista es: " << miLista.obtenerElemento() << endl;
	miLista.irAlInicio();
	cout << "El primer elemento de la lista es: " << miLista.obtenerElemento() << endl;
	//miLista.anterior(); // error
	cout << "Se elimino el elemento " << miLista.eliminar() << " de la lista" << endl;
	mostrar( miLista );
	miLista.vaciar();
	cout << "El tamanio de la lista es " << miLista.tamanio() << endl;

	return 0;
}

void mostrar( ListaEstatica<int> &L )
{
	int pos = L.posicionActual();
	L.irAlInicio();
	cout << "[";
	for( int i = 0; i < L.tamanio(); i++ )
	{
		cout << L.obtenerElemento();
		if( !( i == ( L.tamanio() - 1 ) ) )
		{
			cout << ", ";
			L.siguiente();
		}
	}
	cout << "]" << endl;
	L.irAPosicion( pos );
}