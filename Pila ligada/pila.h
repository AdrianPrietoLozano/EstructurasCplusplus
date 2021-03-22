#ifndef PILA_H
#define PILA_H

template< typename E >
class Pila
{
	private:
		void operator=( const Pila & ){}
		Pila( const Pila & ){}
	public:
		Pila( void ){}
		virtual ~Pila( void ){}
		virtual void vaciar( void ) = 0;
		virtual void push( const E &item ) = 0;
		virtual E pop( void ) = 0;
		virtual const E &top( void ) const = 0;
		virtual int obtenerTamanio( void ) const = 0; 
};

#endif