Trie: Trie.o Nodo.o main.o
	g++ -o Trie Trie.o Nodo.o main.o

Trie.o: Trie.cpp Trie.h
	g++ -g -c Trie.cpp

Nodo.o: Nodo.cpp Nodo.h
	g++ -g -c Nodo.cpp

main.o: main.cpp Trie.h
	g++ -g -c main.cpp

clean:
	rm *.o Trie