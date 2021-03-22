template < typename E > class Eslabon
{
	public:
		E elemento;
		Eslabon *siguiente;
		Eslabon( const E &valorElemento, Eslabon *valorSiguiente = NULL );
		Eslabon( Eslabon *valorSiguiente = NULL );
};

template < typename E >
Eslabon< E >::Eslabon( const E &valorElemento, Eslabon *valorSiguiente )
{
	elemento = valorElemento;
	siguiente = valorSiguiente;
}

template < typename E >
Eslabon< E >::Eslabon( Eslabon *valorSiguiente )
{
	siguiente = valorSiguiente;
}