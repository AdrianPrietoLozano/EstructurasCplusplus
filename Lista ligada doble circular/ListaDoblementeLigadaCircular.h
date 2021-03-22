#include "lista.h"
#include "Assert.cpp"
#include "Eslabon.h"

template < typename E > class ListaDoblementeLigadaCircular: public Lista< E >
{
	private:
		Eslabon< E > *cabeza;
		Eslabon< E > *actual;
		Eslabon< E > *cola;
		int tamanio;
		void inicializar( void );
		void eliminarTodo( void );
	public:
		ListaDoblementeLigadaCircular( void );
		~ListaDoblementeLigadaCircular( void );
		void vaciar( void );
		void insertar( const E &item );
		void ponAlFinal( const E &item );
		E eliminar( void );
		void irAlInicio(void );
		void irAlFinal( void );
		void anterior( void );
		void siguiente( void );
		int obtenerTamanio( void ) const;
		int posicionActual( void ) const;
		void irAPosicion( int posicion );
		const E &obtenerElemento( void ) const;
};

template < typename E >
void ListaDoblementeLigadaCircular< E >::inicializar( void )
{
	cola = cabeza = actual = new Eslabon< E >();
	tamanio = 0;
}

template < typename E >
void ListaDoblementeLigadaCircular< E >::eliminarTodo( void )
{
	while( cabeza != cola )
	{
		actual = cabeza;
		cabeza = cabeza -> siguiente;
		delete actual;
	}
}

template < typename E >
ListaDoblementeLigadaCircular< E >::ListaDoblementeLigadaCircular( void )
{
	inicializar();
}

template < typename E >
ListaDoblementeLigadaCircular< E >::~ListaDoblementeLigadaCircular( void )
{
	eliminarTodo();
}

template < typename E >
void ListaDoblementeLigadaCircular< E >::vaciar( void )
{
	eliminarTodo();
	inicializar();
}

template < typename E >
void ListaDoblementeLigadaCircular< E >::insertar( const E &item )
{
	if( tamanio == 0 )
		cola = actual = cabeza = new Eslabon< E >( item );
	else
		actual = actual -> anterior = actual -> anterior -> siguiente = new Eslabon< E >( item, actual -> anterior, actual );

	if( actual -> siguiente == cabeza )
		cabeza = actual;
	tamanio++;
}

template < typename E >
void ListaDoblementeLigadaCircular< E >::ponAlFinal( const E &item )
{
	if( tamanio == 0 )
		cola = actual = cabeza = new Eslabon< E >( item );
	else
		cola = cabeza -> anterior = cola -> siguiente = new Eslabon< E >( item, cola, cabeza );
	tamanio++;
}

template < typename E >
E ListaDoblementeLigadaCircular< E >::eliminar( void )
{
	Assert( tamanio != 0, "Lista vacia" );

	E item = actual -> elemento;
	Eslabon< E > *temporal = actual;

	if( cola == actual )
		cola = actual -> anterior;
	if( cabeza == actual )
		cabeza = actual -> siguiente;

	actual -> siguiente -> anterior = actual -> anterior;
	actual -> anterior -> siguiente = actual -> siguiente;
	actual = actual -> siguiente;
	delete temporal;

	tamanio--;
	return item;
}

template < typename E >
void ListaDoblementeLigadaCircular< E >::irAlInicio( void )
{
	actual = cabeza;
}

template < typename E >
void ListaDoblementeLigadaCircular< E >::irAlFinal( void )
{
	actual = cola;
}

template < typename E >
void ListaDoblementeLigadaCircular< E >::anterior( void )
{
	if( tamanio != 0 )
		actual = actual -> anterior;
}

template < typename E >
void ListaDoblementeLigadaCircular< E >::siguiente( void )
{
	if( tamanio != 0 )
		actual = actual -> siguiente;
}

template < typename E >
int ListaDoblementeLigadaCircular< E >::obtenerTamanio( void ) const
{
	return tamanio;
}

template < typename E >
int ListaDoblementeLigadaCircular< E >::posicionActual( void ) const
{
	Eslabon< E > *temporal;
	temporal = cabeza;
	int i;

	for( i = 0; temporal != actual; i++ )
		temporal = temporal -> siguiente;

	return i;
}

template < typename E >
void ListaDoblementeLigadaCircular< E >::irAPosicion( int posicion )
{
	Assert( ( posicion >= 0 ) && ( posicion < tamanio ), "Posicion fuera de rango" );

	actual = cabeza;

	for( int i = 0; i < posicion; i++ )
		actual = actual -> siguiente;
}

template < typename E >
const E &ListaDoblementeLigadaCircular< E >::obtenerElemento( void ) const
{
	Assert( tamanio != 0, "Lista vacia" );
	return actual -> elemento;
}