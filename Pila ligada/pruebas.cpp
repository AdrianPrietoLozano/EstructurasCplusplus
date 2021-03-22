#include <iostream>
#include <cstdlib>
#include <string>
#include <math.h>
#include "PilaLigada.h"

using namespace std;

double evaluarPostfija( string cadena );
double aplicarOperacion( char, int, int );

int main( void )
{
	string s;
	int pos = 0;
	double resultado;

	cout << "\n\t\t*** EVALUAR EXPRESION POSTFIJA ***" << endl;
	cout << "\t\t\tNO INGRESAR LETRAS" << endl << endl;

	cout << "Ingresa la expresion (exit para salir): ";
	getline( cin, s );

	while( s != "exit" )
	{
		resultado = evaluarPostfija( s );
		cout << endl << "Resultado = " << resultado << endl << endl;

		cout << "Ingresa el siguiente elemento (exit para salir): ";
		getline( cin, s );
	}
	cout << "Hasta Luego" << endl;

	return 0;
} // fin de main


double aplicarOperacion( char operador, int num1, int num2 )
{
	double resultado;
	switch( operador )
	{
		case '^':
			resultado = pow( num1, num2 );
			break;
		case '/':
			if( num2 == 0 )
			{
				printf("Falla: Division por cero\n");
				exit( -1 );
			}
			resultado = num1 / num2;
			break;
		case '*':
			resultado = num1 * num2;
			break;
		case '+':
			resultado = num1 + num2;
			break;
		case '-':
			resultado = num1 - num2;
			break;
	}
	return resultado;
} // fin función aplicarOperacion

// función que evalua la expresion postfija
double evaluarPostfija( string cadena )
{
	int pos = 0;
	int num1, num2;
	PilaLigada< char > pila;
	char c;

	for( int i = 0; i < cadena.length(); i++ )
	{
		c = cadena[ pos++ ];
		if( c == '+' || c == '*' || c == '^' || c == '-' || c == '/' ) // es un operador
		{
			num1 = pila.pop();
			num2 = pila.pop();

			pila.push( aplicarOperacion( c, num2, num1 ) );
		}
		else if( c != ' ' ) // es un operando
			pila.push( c - '0' ); // convertir el caracter a entero
	}

	return pila.pop();
} // fin función evaluarPostfija