#include <fstream>
#include <cstring>
#include <iostream>
using namespace std;

#include "btreenode.h"

// Construtor para a classe BTreeNode
BTreeNode::BTreeNode(int _t, bool _leaf)
{
	// Copia o mínimo grau e a folha
	t = _t;
	leaf = _leaf;

	// Alocação de memória para o número máximo de chaves possíveis
	// e ponteiros filho
	keys = new int[2*t-1];
	C = new BTreeNode *[2*t];

	// Inicializa o número de chaves como 0
	n = 0;
}

// Função para percorrer todos os nós na sub-árvore cuja raíz é esse nó
void BTreeNode::traverse()
{
	// Há n chaves n+1 filhos, percorre através das n chaves
	// e os primeiros n filhos
	int i;
	for (i = 0; i < n; i++)
	{
		// Se esse nó não é folha, então antes de exibir key[i],
		// percorra sub-árvore cuja raiz é o filho C[i].
		if (leaf == false)
			C[i]->traverse();
		cout << " " << keys[i];
	}

	// Exiba a sub-árvore cuja raíz é o último filho
	if (leaf == false)
		C[i]->traverse();
}

// Função para encontrar uma determinada chave na sub-árvore cuja raíz é esse nó
BTreeNode *BTreeNode::search(int k)
{
	// Encontra a primeira chave maior ou igual a k
	int i = 0;
	while (i < n && k > keys[i])
		i++;

	// Se a chave encontrada é igual a k, retorna este nó
	if (keys[i] == k)
		return this;

	// Se a chave não está aqui e este é um nó folha
	if (leaf == true)
		return NULL;

	// Vá para o filho apropriado
	return C[i]->search(k);
}



// Função de inserção de uma nova chave na árvore B
void BTree::insert(int k) 
{ 
	// Se a árvore está vazia
	if (root == NULL) 
	{ 
		// Aloca memória para a raíz 
		root = new BTreeNode(t, true); 
		root->keys[0] = k; // Insere chave 
		root->n = 1; // Atualiza número de chaves na raíz 
	} 
	else // Se a árvore não está vazia
	{ 
		// Se a raíz está cheia, então a árvore cresce em altura 
		if (root->n == 2*t-1) 
		{ 
			// Aloca memória para a nova raíz
			BTreeNode *s = new BTreeNode(t, false); 

			// Transforma a raíz velha em filha da nova raíz 
			s->C[0] = root; 

			// Divide a velha raíz, e move uma chave para a nova raíz 
			s->splitChild(0, root); 

			// A nova raíz tem dois filhos agora. Decide qual deles 
			// terá a nova chave
			int i = 0; 
			if (s->keys[0] < k) 
				i++; 
			s->C[i]->insertNonFull(k); 

			// Muda a raíz
			root = s; 
		} 
		else // Se a raíz não está cheia, chama a função insertNonFull para a raíz 
			root->insertNonFull(k); 
	} 
} 

// Uma função para inserir uma nova chave neste nó 
// O nó não poderá estar cheio quando esta função for chamada 
void BTreeNode::insertNonFull(int k) 	
{ 
	// Inicializa índice como o índice do elemento mais à direita
	int i = n-1; 

	// Se este é um nó folha
	if (leaf == true) 
	{ 
		// O laço abaixo faz duas coisas:
		// a) Encontra a localização da nova chave a ser inserida 
		// b) Move todas as chaves maiores para um lugar adiante
		while (i >= 0 && keys[i] > k) 
		{ 
			keys[i+1] = keys[i]; 
			i--; 
		} 

		// Insere a nova chave na localização encontrada
		keys[i+1] = k; 
		n = n+1; 
	} 
	else // Se este nó não é folha
	{ 
		// Encontra o filho que terá a nova chave 
		while (i >= 0 && keys[i] > k) 
			i--; 

		// Verifica se o filho encontrado está cheio
		if (C[i+1]->n == 2*t-1) 
		{ 
			// Se o filho está cheio, então divide
			splitChild(i+1, C[i+1]); 

			// Após a divisão, a chave do meio de C[i] vai para cima e 
			// C[i] é dividido em dois. Verifica qual deles 
			// terá a nova chave
			if (keys[i+1] < k) 
				i++; 
		} 
		C[i+1]->insertNonFull(k); 
	} 
} 

// Função para fazer a divisão do filho y deste nó
// Obs: y precisa estar cheio ao chamar essa função 
void BTreeNode::splitChild(int i, BTreeNode *y) 
{ 
	// Cria um novo nó que irá armazenar (t-1) chaves 
	// de y 
	BTreeNode *z = new BTreeNode(y->t, y->leaf); 
	z->n = t - 1; 

	// Copia as últimas (t-1) chaves de y a z 
	for (int j = 0; j < t-1; j++) 
		z->keys[j] = y->keys[j+t]; 

	// Copia os últimos t filhos de y a z 
	if (y->leaf == false) 
	{ 
		for (int j = 0; j < t; j++) 
			z->C[j] = y->C[j+t]; 
	} 

	// Reduz o número de chaves em y
	y->n = t - 1; 

	// Como este nó terá um novo filho, 
	// cria espaço para o novo filho
	for (int j = n; j >= i+1; j--) 
		C[j+1] = C[j]; 

	// Vincula o novo filho a este nó 
	C[i+1] = z; 

	// Uma chave de y irá se mover para este nó. Encontra a localização da 
	// da nova chave e move todas as chaves maiores para uma posição adiante 
	for (int j = n-1; j >= i; j--) 
		keys[j+1] = keys[j]; 

	// Copia as chaves do meio de y para este nó
	keys[i] = y->keys[t-1]; 

	// Incrementa a contagem de chaves para este nó
	n = n + 1; 
} 
