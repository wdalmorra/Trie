/*
	Universidade Federal de Pelotas
	Ciência da Computação - CDTec

	Aluno: William Dalmorra de Souza
	Matrícula: 11100360
*/

// Arquivo .cpp onde estão implementados os métodos da classe Trie
#include "Trie.h"

Trie::Trie()																									// Construtor da classe
{
	raiz = new Nodo();																							// Instancia a raiz da trie
}

Trie::~Trie()																									// Destrutor da classe
{
	delete palindromas;																							// Deleta a trie que contém as palindromas
	this->destroiNodo(raiz);																								// Deleta a raiz da trie
}

// Método que percorre a Trie apagando os nodos, primeiro as folhas e depois os pais, fazendo uma busca por profundidade
void Trie::destroiNodo(Nodo* nodo)
{
	for (int i = 0; i < 27; i++)
	{
		if (i == 26)
		{
			delete nodo;
		}
		else
		{
			if (nodo->getNodo(i+'A') != NULL)
			{
				this->destroiNodo(nodo->getNodo(i+'A'));
			}
		}
	}
}
// Método que converte uma string para maiúscula
string converteString(string word)
{
	int tam = word.size();																						// Tamanho da string
	for (int i = 0; i < tam; ++i)																				// Percorre a string
	{
		if(islower(word[i]))																					// Se o caracter for minúsculo
		{	
			word[i] = toupper(word[i]);																			// Transforma para maiúsculo
		}
	}
	return word;	
}
// Método que inverte uma string
string inverteString(string word)
{
	int tam  = word.size();																						// tamanho da string
	string aux;																									// string auxiliar

	// Percorre toda a string ao contrario concatenando as caracteres na string auxiliar
	for (int i = 0; i < tam; ++i)		
	{
		aux += word[(tam-1)-i];
	}
	return aux;
}

// Método que insere um string na trie
void Trie::insereString(string word)
{
	int i = 0;
	Nodo* Aux;																									// Nodo auxiliar
	Aux = raiz;																									// que recebe a raiz da trie
	word = converteString(word);																				// Converte todas as letras para maiusculas

	while(word[i] != '\0')																						// enquanto nao é o fim da string vai adicionando
	{
		if (Aux->getNodo(word[i]) == NULL)																		// Se o nodo for nulo é porque ainda não foi inserido um prefixo igual
		{
			Aux->insere(word[i]);																				// Nesse caso insere um nodo com este prefixo
		}
		Aux = Aux->getNodo(word[i]);																			// E o nodo auxiliar desce um nodo na hierarquia da trie
		i++;
	}
}

// Método que verifica se um string está na trie, retorna 1 caso estejae -1 caso contrário
int Trie::buscaString(string word)
{
	int i = 0;
	Nodo* Aux;																									// Nodo auxiliar
	Aux = raiz;																									// que recebe a raiz da trie

	word = converteString(word);																				// Converte todas as letras para maiúsculas
	while(word[i] != '\0')																						// enquanto não é o fim da string continua procurando
	{
		Aux = Aux->getNodo(word[i]);																			// auxiliar recebe o nodo pra onde aponta o caracter da string

		if (Aux != NULL)																						// Se esse nodo não for nulo é porque até o momento existe a string então tem que seguir procurando
		{
			if ( word[i] == '$')																				// Caso chegou no caracter de fim de string é porque a string está na trie
			{	
				return 1;																						// Então retorna 1
			}																									// Se nao for caracter de fim de string apenas segue pro proximo caracter
		}
		else																									// Se o nodo for nulo então é porque não tem o caracter q ta procurando logo a string toda nao da na trie
		{
			return -1;																							// retorna -1
		}
		i++;
	}
}

// Método que gera a trie de sufixos para encontrar as palindromas
void Trie::criarTrieSufixos(string word)
{
	string aux;																									// String auxliar
	aux = word;																									// que recebe a palavra a ser inserido os sufixos

	while (aux.compare("$") > 0)																				// Enquanto não for o caracter '$' então segue inserindo, se for cai fora porque não precisa inseri-lo
	{
		this->insereString(aux);																				// insere a string
		aux.erase(aux.begin());																					// e remove o 1º caracter, assim ele vai inserindo todos os sufixos da palavra
	}
}

// Método que verificar quais são as maiores substrings palíndromas dentro de uma string
void Trie::verificaPalindroma(string word)
{
	word = converteString(word);																				// 1º Converte todas as letras para maiúsculas
	this->criarTrieSufixos(word);																				// 2º Cria a trie de sufixos daquela palavra
	string aux2, aux;																							// strings auxiliares
																												// aux - string invertida que é percorrida sempre diminuindo a letra do inicio
																												// aux2 - string que recebe a maior substring palimdroma encontra a partir de aux

	aux = inverteString(word);																					// aux recebe a string invertida
	aux.erase(aux.begin());																						// remover o 1º caracter que quando invertido é o '$'
	int tamMaiorPalindroma = 0;																					// tamanho da maior palindroma encontrada
	int i = 0;										

	while (aux.compare("$") > 0)																				// Enquanto a string invertida não é '$'
	{

		if (aux.size() >= tamMaiorPalindroma)																	// Se o tamanho da string for menor que a maior palindroma não tem porque seguir procurando
		{																										// já que por mais que encontre outra palindroma não tem como ela ser maior ou igual

			aux2 = this->buscaMaiorString(aux);																	// aux2 recebe a maior string encontrada a partir de aux


			if ((aux2.size() == tamMaiorPalindroma) && (aux2.compare(inverteString(aux2)) == 0))				// Se o tamanho for igual e realmente for uma palíndroma
			{																									// Então insere na trie de palindromas
				aux2+='$';
				palindromas->insereString(aux2);
			}


			if ((aux2.size() > tamMaiorPalindroma) && (aux2.compare(inverteString(aux2)) == 0))					// Se o tamanho por maior e for realmente uma palíndroma
			{																									// Então apaga a trie anterior, cria uma nova e insere a string nela
					free(palindromas);

					palindromas = new Trie();

					aux2+='$';					
					palindromas->insereString(aux2);

					tamMaiorPalindroma = aux2.size()-1;															// Nese caso o tamanho da maior palíndroma passa a ser o da string atual
			}
			aux.erase(aux.begin());																				// Remove o 1º caracter da string e recomeça a busca
		}
																												// Caso o tamanho da string for maior que a string restante pode sair do laço
		else
		{
			break;
		}
	}

	// Se o tamanho da maior palíndroma for igual a 1 então é porque só encontrou letras separadas como palíndromas nesse caso não encontrou nenhuma palíndroma de verdade
	if (tamMaiorPalindroma == 0)
	{
		cout<< "Não possui nenhuma palindroma"<< endl;
	}
	// Senão imprime a trie de palíndromas
	else
	{
		palindromas->imprimeTrie();
	}
}

// Método que encontra a maior string que se pode encontrar na trie, não necessariamente indo até o fim dela
string Trie::buscaMaiorString(string word)
{
	int i = 0;
	Nodo* aux = raiz;																							// Nodo auxiliar que recebe a raiz da trie
	string aux2;																								// string auxiliar
	while(word[i] != '\0')																						// Enquanto não for o fim da string segue procurando
	{
		aux = aux->getNodo(word[i]);																			// Nodo auxiliar recebe o próximo nodo correspondente ao caracter 
		if (aux == NULL)																						// Se ele for nulo é porque a maior substring encontrada foi a lida a agora
			break;																								// Logo sai do laço
		aux2 += word[i];																						// Se não for nulo então existe aquele caracter, logo concatena ele na string auxiliar e segue procurando pelo próximo caracter
		i++;							
	}
	return aux2;
}

// Método que imprimi a trie não recursivo
// Esse é público
void Trie::imprimeTrie()
{
	string word = "";																							// Inicia uma string auxiliar com nenhum caracter
	this->imprime(this->raiz,word);																				// Chama o método recursivo passando a raiz da trie e a string vazia
}

// Método que imprime recursivo
// Este é privado
void Trie::imprime(Nodo* nodo,string word)
{
	for (int i = 0; i < 27; i++)																				// Percorre todas as posições do nodo recebido por parâmetro
	{
		if (i == 26)																							// Se for a posição 26 enao é oc aso do caracter '$'
		{	
			if (nodo->getNodo('$') != NULL)																		// Se o nodo para o qual ele aponta for diferente de nulo enao é porque esta string está na trie
			{
				cout<< word << endl;																			// Logo imprime a string
			}
		}
		else																									// Se for qualquer outra posição
		{
			if (nodo->getNodo(i+'A') != NULL)																	// Se o nodo para o qual a posiçao aponta for diferente de nulo então é porque esse caracter existe
			{
				word += i + 'A';																				// Então concatena ele na string recebida por parâmetro
				this->imprime(nodo->getNodo(i+'A'),word);														// E manda imprimir o nodo para o qual esse ponteiro aponta usando recursão
				word.erase(word.size() - 1);																	// Quando voltar da recursão é porque imprimiu todas as atrings que continham esse mesmo prefixo então desconcatena o último caracter e segue procurando pelos outros caracteres restantes no nodo
			}
		}
	}
																												/* Isso faz com que imprima em ordem alfabética */
}