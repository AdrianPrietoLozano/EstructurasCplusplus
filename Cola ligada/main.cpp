#include <iostream>
#include "ColaLigada.h"
#include <string>

using namespace std;

template < typename E >
void mostrar( ColaLigada< E > & );

char opcionMenu( void );

int main( void )
{
	char opcion;
	string docNuevo;
	ColaLigada< string > cola;
	
	while( ( opcion = opcionMenu() ) != '6' )
	{
		switch( opcion )
		{
			case '1':
				cout << endl;
				cout << "Nombre del documento a imprimir: ";
				cin.ignore();
				getline( cin, docNuevo );
				cola.encolar( docNuevo );
				cout << "Listo" << endl << endl;
				break;
			case '2':
				if( cola.obtenerTamanio() > 0 )
					cout << "\nSe imprimio el documento \"" << cola.descolar() << "\"" << endl << endl;
				else
					cout << "\nLa cola de impresion esta vacia" << endl << endl;
				break;
			case '3':
				if( cola.obtenerTamanio() > 0 )
					cout << "\nSiguiente doc. a imprimir: \"" << cola.valorAlFrente() << "\"" << endl;
				else
					cout << "\nLa cola de impresion esta vacia" << endl;
				cout << "Cantidad de doc. pendientes: " << cola.obtenerTamanio() << endl << endl;
				break;
			case '4':
				cola.vaciar();
				cout << "\nSe vacio la cola de impresion" << endl << endl;
				break;
			case '5':
				cout << endl;
				if( cola.obtenerTamanio() > 0 )
					mostrar( cola );
				else
					cout << "No hay archivos que imprimir" << endl;
				cout << endl;
				break;
		}
		system( "pause" );
	}
	return 0;
}

char opcionMenu( void )
{
	char opcion;
	do
	{
		system( "cls" );
		cout << "1) Encolar documento" << endl
			 << "2) Imprimir documento" << endl
			 << "3) Consultar estado de impresion" << endl
			 << "4) Cancelar impresiones" << endl
			 << "5) Mostrar documentos pendientes" << endl
			 << "6) Salir" << endl;
		cin >> opcion;

	}while( opcion != '1' && opcion != '2' && opcion != '3' && opcion != '4' && opcion != '5' && opcion != '6' );
	return opcion;
}

template < typename E >
void mostrar( ColaLigada< E > &cola )
{
	for( int i = 0; i < cola.obtenerTamanio(); ++i )
	{
		cout << i+1 << ".  \"" << cola.valorAlFrente() << "\"" << endl;
		cola.encolar( cola.descolar() );
	}
}