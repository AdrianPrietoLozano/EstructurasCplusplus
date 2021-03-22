#ifndef COLA_H
#define COLA_H

template< typename E >
class Cola
{
	private:
		void operator=( const Cola & ){}
		Cola( const Cola & ){}
	public:
		Cola( void ){}
		virtual ~Cola( void ){}
		virtual void vaciar( void ) = 0;
		virtual void encolar( const E & ) = 0;
		virtual E descolar( void ) = 0;
		virtual const E &valorAlFrente( void ) const = 0;
		virtual int obtenerTamanio( void ) const = 0;
	
};

#endif