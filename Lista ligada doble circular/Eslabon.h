template < typename E > class Eslabon
{
	public:
		E elemento;
		Eslabon *siguiente;
		Eslabon *anterior;
		Eslabon( const E &, Eslabon *, Eslabon * );
		Eslabon( E dato );
		Eslabon( void );
};

template < typename E >
Eslabon< E >::Eslabon( const E &valorElemento, Eslabon *valorAnterior, Eslabon *valorSiguiente )
{
	elemento = valorElemento;
	anterior = valorAnterior;
	siguiente = valorSiguiente;
}

// constructor en el que anterior y siguiente apuntan a si mismo y no tiene elemento
template < typename E >
Eslabon< E >::Eslabon( void )
{
	siguiente = this;
	anterior = this;
}

template < typename E >
Eslabon< E >::Eslabon( E dato )
{
	elemento = dato;
	siguiente = this;
	anterior = this;
}