#include <string>
#include "cola.h"
#include "Assert.cpp"

template< typename E >
class ColaEstatica: public Cola< E >
{
	private:
		int tamanioMaximo;
		int indiceFrente;
		int indiceAtras;
		int tamanioActual;
		E *arreglo;
	public:
		ColaEstatica( int );
		~ColaEstatica( void );
		void vaciar( void );
		void encolar( const E & );
		E descolar( void );
		const E &valorAlFrente( void ) const;
		int obtenerTamanio( void ) const;
		//void mostrar( void ) const;
};

template< typename E >
ColaEstatica< E >::ColaEstatica( int tamanio )
{
	tamanioMaximo = tamanio;
	indiceFrente = 0;
	indiceAtras = -1;
	tamanioActual = 0;
	arreglo = new E[ tamanioMaximo ];
}

template< typename E >
ColaEstatica< E >::~ColaEstatica( void )
{
	delete [] arreglo;
}

template< typename E >
void ColaEstatica< E >::vaciar( void )
{
	indiceFrente = 0;
	indiceAtras = -1;
	tamanioActual = 0;
}

template< typename E >
void ColaEstatica< E >::encolar( const E &nuevo )
{
	Assert( tamanioActual < tamanioMaximo, "Cola llena" );
	if( indiceAtras == tamanioMaximo - 1 )
	{
		indiceAtras = 0;
		arreglo[ indiceAtras ] = nuevo;
	}
	else
	{
		arreglo[ ++indiceAtras ] = nuevo;
	}
	tamanioActual++;
}

template< typename E >
E ColaEstatica< E >::descolar( void )
{
	Assert( tamanioActual != 0, "Cola vacia" );
	E aux = arreglo[ indiceFrente ];
	if( indiceFrente == indiceAtras )
	{
		indiceFrente = 0;
		indiceAtras = -1;
	}
	else if( indiceFrente == tamanioMaximo - 1 )
	{
		indiceFrente = 0;
	}
	else
		indiceFrente++;
	tamanioActual--;
	return aux;
}

template< typename E >
const E &ColaEstatica< E >::valorAlFrente( void ) const
{
	Assert( tamanioActual != 0, "Cola vacia" ); 
	return arreglo[ indiceFrente ];
}

template< typename E >
int ColaEstatica< E >::obtenerTamanio( void ) const
{
	return tamanioActual;
}
