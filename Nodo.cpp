/*
	Universidade Federal de Pelotas
	Ciência da Computação - CDTec

	Aluno: William Dalmorra de Souza
	Matrícula: 11100360
*/

// Arquivo .cpp onde estão definidos os métodos da classe Nodo
#include "Nodo.h"
Nodo::Nodo(){
	for (int i = 0; i < 27; ++i)
	{
		letras[i] = NULL;
	}
}  								// Contrutor da classe, não inicializa nenhum atributo

Nodo::~Nodo()									// Destrutor da classe
{
	for (int i = 0; i < 27; ++i)
	{
		free(letras[i]);						// libera a área alocada pelos ponteiros
	}
}		

// insere um novo ponteiro que representa um caracter da string
void Nodo::insere(char posicao)
{
	Nodo* nodo = new Nodo();					// cria um novo Nodo para onde este irá apontar

	if (posicao == '$')							// se for o caracter de fim da string a posiçao 26 aponta pro novo Nodo
	{
		letras[26] = nodo;						// Este novo nodo nao irá apontar para ninguém apenas indica que o caracter '$' foi inserido
	}
	else
		letras[posicao - 'A'] = nodo;			// Se for um caracter do alfabeto então coloca o nodo na posição correta diminuindo 'A' do valor da posição, futuramente este nodo apontará para outro caracter	
}

// Retorna um dos ponteiros do nodo
Nodo* Nodo::getNodo(char posicao)
{
	if (posicao == '$')							// Se for a posição 26 retorna o fim da string
		return letras[26];

	return letras[posicao - 'A'];				// Senão retorna a posição correta
}
