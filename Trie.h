/*
	Universidade Federal de Pelotas
	Ciência da Computação - CDTec

	Aluno: William Dalmorra de Souza
	Matrícula: 11100360
*/

// Arquivo .h onde está definida a classe Trie
#ifndef TRIE_H_
#define TRIE_H_

#include "Nodo.h"
#include <cctype>
#include <string>
#include <cstring>
#include <iostream>
class Trie
{
	// 	Atributos Privados:

	Nodo* raiz;										//		Ponteio para a raiz da Trie
	Trie * palindromas;								//		Nova Trie onde serão inseridas todas as maiores palindromas caso houver mais de uma
	void imprime(Nodo* nodo,string word);			//		Método recursivo para imprimir a Trie
	friend string inverteString(string word);		//		Método que inverte a string
	string buscaMaiorString(string word);			//		Método que encontra a encontra a maior substring comum entre a trie e o parametro
	friend string converteString(string word);		//		Método que converte a string inserida para maiúscula
	void destroiNodo(Nodo* nodo);

	/* Os métodos insereString e buscaString são privados
		devido a utilidade desta trie ser apenas de encontrar palindromas.
	*/
public:
	Trie();											// 		Construtor da classe
	~Trie();										// 		Destrutor da classe
	void criarTrieSufixos(string word);				//		Método que cria a trie de sufixos
	int buscaString(string word);					//		Método que verifica se um string se encontra na trie - retorna 1 caso contenha a string e -1 caso contrário
	void insereString(string word);					//		Método que insere uma string na trie
	void verificaPalindroma(string word);			// 		Método que informa as maiores substrings palíndromas contidas na string recebida por parâmetro
	void imprimeTrie();								// 		Método público não recursivo para imprimir a trie
};
#endif