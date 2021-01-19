#ifndef BTREENODE
#define BTREENODE
#include <fstream>
#include <cstring>
#include <iostream>


// Um nó da árvore B 
class BTreeNode
{
	int *keys; // um vetor de chaves
	int t;	 // Grau mínimo definido pelo intervalo da quantidade de chaves possíveis
	BTreeNode **C; // Um vetor de ponteiros filho
	int n;	 // Número atual de chaves
	bool leaf; // Verdadeiro quando nó é uma folha e falso para o contrário
public:
	BTreeNode(int _t, bool _leaf); // Construtor da classe
	
	// Uma função para inserir uma nova chave neste nó 
	// O nó não poderá estar cheio quando esta função for chamada 
	void insertNonFull(int k); 

 	// Função para fazer a divisão do filho y deste nó
	// Obs: y precisa estar cheio ao chamar essa função 
	void splitChild(int i, BTreeNode *y); 

	// Função que percorre todos os nós na sub-árvore cuja raíz é esse nó
	void traverse();

	// Função para encontrar uma determinada chave na sub-árvore cuja raíz é esse nó
	BTreeNode *search(int k); // retorna NULL se a chave está ausente.

// Transforma a classe BTree em friend para que membros privados dessa classe 
// sejam acessados nas funções da classe BTree.
friend class BTree;
};

// Uma árvore B
class BTree
{
	BTreeNode *root; // Ponteiro para o nó raíz
	int t; // Grau mínimo
public:
	// Construtor (inicializa a árvore vazia)
	BTree(int _t)
	{ root = NULL; t = _t; }

	// Função para percorrer a árvore
	void traverse()
	{ if (root != NULL) root->traverse(); }

	// Função para encontrar uma chave nessa árvore
	BTreeNode* search(int k)
	{ return (root == NULL)? NULL : root->search(k); }

    void insert(int k); 
};

#endif