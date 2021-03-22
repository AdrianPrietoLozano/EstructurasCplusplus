#include "lista.h"
#include "Assert.cpp"
#include "Eslabon.h"

template < typename E > class ListaLigada: public Lista< E >
{
	private:
		Eslabon< E > *cabeza;
		Eslabon< E > *cola;
		Eslabon< E > *actual;
		int tamanio;
		void inicializar( void );
		void eliminarTodo( void );
	public:
		ListaLigada( void );
		~ListaLigada( void );
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
void ListaLigada< E >::inicializar( void )
{
	tamanio = 0;
	actual = cola = cabeza = new Eslabon< E >;
}

template < typename E >
void ListaLigada< E >::eliminarTodo( void )
{
	while( cabeza != NULL )
	{
		actual = cabeza;
		cabeza = cabeza -> siguiente;
		delete actual;
	}
}

template < typename E >
ListaLigada< E >::ListaLigada( void )
{
	inicializar();
}

template < typename E >
ListaLigada< E >::~ListaLigada( void )
{
	eliminarTodo();
}

template < typename E >
void ListaLigada< E >::vaciar( void )
{
	eliminarTodo();
	inicializar();
}

template < typename E >
void ListaLigada< E >::insertar( const E &item )
{
	actual -> siguiente = new Eslabon< E >( item, actual -> siguiente );
	if( cola == actual )
		cola = actual -> siguiente;
	tamanio++;
}

template < typename E >
void ListaLigada< E >::ponAlFinal( const E &item )
{
	cola = cola -> siguiente = new Eslabon< E >( item, cola -> siguiente );
	tamanio++;
}

template < typename E >
E ListaLigada< E >::eliminar( void )
{
	Assert( tamanio != 0, "Lista vacia" );

	E item = actual -> siguiente -> elemento;
	Eslabon< E > *temporal = actual -> siguiente;

	if( cola == actual -> siguiente )
		cola = actual;

	actual -> siguiente = actual -> siguiente -> siguiente;
	delete temporal;

	if( cola == actual )
		anterior();

	tamanio--;
	return item;
}

template < typename E >
void ListaLigada< E >::irAlInicio( void )
{
	actual = cabeza;
}

template < typename E >
void ListaLigada< E >::irAlFinal( void )
{
	actual = cola;
	anterior();
}

template < typename E >
void ListaLigada< E >::anterior( void )
{
	if( actual == cabeza || actual == cabeza -> siguiente )
		return;

	Eslabon< E > *temporal = new Eslabon< E >( cabeza );

	while( temporal -> siguiente != actual )
		temporal = temporal -> siguiente;

	actual = temporal;
}

template < typename E >
void ListaLigada< E >::siguiente( void )
{
	if( actual -> siguiente == cola )
		return;

	actual = actual -> siguiente;
}

template < typename E >
int ListaLigada< E >::obtenerTamanio( void ) const
{
	return tamanio;
}

template < typename E >
int ListaLigada< E >::posicionActual( void ) const
{
	Eslabon< E > *temporal;
	temporal = cabeza;
	int i;

	for( i = 0; temporal != actual; i++ )
		temporal = temporal -> siguiente;

	return i;
}

template < typename E >
void ListaLigada< E >::irAPosicion( int posicion )
{
	Assert( ( posicion >= 0 ) && ( posicion <= tamanio ), "Posicion fuera de rango" );

	actual = cabeza;

	for( int i = 0; i < posicion; i++ )
		actual = actual -> siguiente;
}

template < typename E >
const E &ListaLigada< E >::obtenerElemento( void ) const
{
	Assert( tamanio != 0, "Lista vacia" );
	return actual -> siguiente -> elemento;
}