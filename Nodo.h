/*
	Universidade Federal de Pelotas
	Ciência da Computação - CDTec

	Aluno: William Dalmorra de Souza
	Matrícula: 11100360
*/

// Arquivo .h onde esta definida a classe Nodo

#ifndef NODO_H_
#define NODO_H_

#include <cstdlib>

using namespace std;
class Nodo
{
	// Declaração dos atributos
	// - Um vetor de ponteiros para Nodos onde cada ponteiro representa um caracter do alfabeto e um ponteiro para o caracter de fim de string '$'

	Nodo* letras[27];  					// A 26ª posição representa o caracter '$'

public:

	Nodo(); 							// Construtor da classe
	~Nodo();  							// Destrutor da classe
	void insere(char posicao); 			// Método que adiciona um ponteiro para o nodo
	Nodo* getNodo(char posicao);  		// Método que retorna um dos ponteiros do nodo
};
#endif