#include "cola.h"
#include "Assert.cpp"
#include "Eslabon.h"
#include <iomanip>

template< typename E >
class ColaLigada: public Cola< E >
{
	private:
		Eslabon< E > *frente;
		Eslabon< E > *atras;
		int tamanio;
	public:
		ColaLigada( void );
		~ColaLigada( void );
		void vaciar( void );
		void encolar( const E & );
		E descolar( void );
		const E &valorAlFrente( void ) const;
		int obtenerTamanio( void ) const; 
};

template < typename E >
ColaLigada< E >::ColaLigada( void )
{
	frente = atras = new Eslabon< E >; // new Eslabon< E >();
	tamanio = 0;
}

template < typename E >
void ColaLigada< E >::vaciar( void )
{
	while( tamanio > 0 )
	{
		atras = frente;
		frente = frente -> siguiente;
		delete atras;
		tamanio--;
	}
	atras = frente;
}

template < typename E >
ColaLigada< E >::~ColaLigada( void )
{
	vaciar();
	delete frente;
}

template < typename E >
void ColaLigada< E >::encolar( const E &item )
{
	atras = atras -> siguiente = new Eslabon< E >( item );
	tamanio++;
}

template < typename E >
E ColaLigada< E >::descolar( void )
{
	Assert( tamanio != 0, "Cola vacia" );
	E item = frente -> siguiente -> elemento;
	Eslabon< E > *temporal = frente -> siguiente;
	frente -> siguiente = frente -> siguiente -> siguiente;
	if( temporal == atras )
		atras = frente;
	delete temporal;

	tamanio--;
	return item;
}

template < typename E >
const E &ColaLigada< E >::valorAlFrente( void ) const
{
	Assert( tamanio != 0, "Cola vacia" );
	return frente -> siguiente -> elemento;
}

template < typename E >
 int ColaLigada< E >::obtenerTamanio( void ) const
{
	return tamanio;
}
