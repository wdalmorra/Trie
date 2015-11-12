/*
	Universidade Federal de Pelotas
	Ciência da Computação - CDTec

	Aluno: William Dalmorra de Souza
	Matrícula: 11100360
*/

#include "Trie.h"

int main(int argc, char const *argv[])
{
	Trie* trie = new Trie();
	string str;

	cin >> str; 										// Lê a palavra do usuário

	str+="$"; 											// Adiciona o caracter que indica fim da string

	trie->verificaPalindroma(str);  					// Verica as maiores palíndromas desta palavra

	return 0;
}