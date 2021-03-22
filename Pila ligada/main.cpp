#include <iostream>
#include <cstdlib>
#include <string>
#include <math.h>
#include "PilaLigada.h"

#define TAM 50

using namespace std;

double evaluarPostfija( const string cadenas[], int tamanio );
double aplicarOperacion( char, double, double );

int main( void )
{
	string cadenas[ TAM ];
	string s;
	int pos = 0;
	double resultado;

	cout << "\n\t\t*** EVALUAR EXPRESION POSTFIJA ***" << endl;
	cout << "\t\t\tNO INGRESAR LETRAS" << endl << endl;

	cout << "Ingresa el primer elemento (exit para terminar): ";
	fflush( stdin );
	cin >> s;

	while( s != "exit" )
	{
		cadenas[ pos++ ] = s;
		cout << "Ingresa el siguiente elemento (exit para terminar): ";
		fflush( stdin );
		cin >> s;
	}
	resultado = evaluarPostfija( cadenas, pos );
	cout << endl << "Resultado = " << resultado << endl << endl;

	return 0;
} // fin de main


double aplicarOperacion( char operador, double num1, double num2 )
{
	double resultado;
	switch( operador )
	{
		case '^':
			resultado = pow( num1, num2 );
			break;
		case '/':
			Assert( num2 != 0, "Division por cero" );
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
double evaluarPostfija( const string cadenas[], int tamanio )
{
	int pos = 0;
	string s;
	PilaLigada< double > pila;
	double valor, num1, num2;

	for( int i = 0; i < tamanio; i++ )
	{
		s = cadenas[ pos++ ];
		if( s == "+" || s == "*" || s == "^" || s == "-" || s == "/" ) // es un operador
		{
			num1 = pila.pop();
			num2 = pila.pop();

			pila.push( aplicarOperacion( s[ 0 ], num2, num1 ) );
		}
		else // es un operando
		{
			valor = stod ( s );
			pila.push( valor ); // convertir el string a double
		}
	}

	return pila.pop();
} // fin función evaluarPostfija