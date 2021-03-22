#include "pila.h"
#include "Assert.cpp"
#include "Eslabon.h"

template< typename E >
class PilaLigada: public Pila< E >
{
	private:
		Eslabon< E > *tope;
		int tamanio;
	public:
		PilaLigada( void );
		~PilaLigada( void );
		void vaciar( void );
		void push( const E & );
		E pop( void );
		const E &top( void ) const;
		int obtenerTamanio( void ) const; 
};

template < typename E >
PilaLigada< E >::PilaLigada( void )
{
	tope = NULL;
	tamanio = 0;
}

template < typename E >
void PilaLigada< E >::vaciar( void )
{
	Eslabon< E > *temporal = tope;
	while( tope != NULL )
	{
		tope = tope -> siguiente;
		delete temporal;
		temporal = tope;
	}
}

template < typename E >
PilaLigada< E >::~PilaLigada( void )
{
	vaciar();
}

template < typename E >
void PilaLigada< E >::push( const E &item )
{
	tope = new Eslabon< E >( item, tope );
	tamanio++;
}

template < typename E >
E PilaLigada< E >::pop( void )
{
	Assert( tamanio != 0, "Pila vacia" );
	E item = tope -> elemento;
	Eslabon< E > *temporal = tope -> siguiente;
	delete tope;
	tope = temporal;
	tamanio--;
	return item;
}

template < typename E >
const E &PilaLigada< E >::top( void ) const
{
	Assert( tamanio != 0, "Pila vacia" );
	return tope -> elemento;
}

template < typename E >
 int PilaLigada< E >::obtenerTamanio( void ) const
{
	return tamanio;
}
