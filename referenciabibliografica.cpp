#define _CRT_SECURE_NO_WARNINGS

//bibliotecas
#include "referenciabibliografica.h"
#include <iostream>
#include <cstring>

//Construtor da classe
ReferenciaBibliografica::ReferenciaBibliografica() : autorLen(50), tituloLen(50), localLen(50), editoraLen(50) {
	autor = new char[autorLen + 1];
	titulo = new char[tituloLen + 1];
	local = new char[localLen + 1];
	editora = new char[editoraLen + 1];
}

//Autor, Título, Local, Editora, Ano
ReferenciaBibliografica::ReferenciaBibliografica(char* a, char* t, int ed, char* l, char* e, int an) : autorLen(30), tituloLen(30), localLen(30), editoraLen(30) {
	autor = new char[autorLen + 1];
	titulo = new char[tituloLen + 1];
	local = new char[localLen + 1];
	editora = new char[editoraLen + 1];
	strcpy(autor, a);
	strcpy(titulo, t);
	strcpy(local, l);
	strcpy(editora, e);
	edicao = ed;
	ano = an;
}

// Método para escrever no arquivo os dados bibliográficos
void ReferenciaBibliografica::writeToFile(fstream& out)  {
	
	out.write(autor, autorLen);
	out.write(titulo, tituloLen);
	out.write(local, localLen);
	out.write(editora, editoraLen);
	out.write(reinterpret_cast <char*>(&edicao), sizeof(int));
	out.write(reinterpret_cast <char*>(&ano), sizeof(int));
}

// Método de leitura dos dados a partir do arquivo
void ReferenciaBibliografica::readFromFile(fstream& in) {
	
	in.read(autor, autorLen);
	in.read(titulo, tituloLen);
	in.read(local, localLen);
	in.read(editora, editoraLen);
	in.read(reinterpret_cast <char*>(&edicao), sizeof(int));
	in.read(reinterpret_cast <char*>(&ano), sizeof(int));
}

// Método para realizar a leitura da chave primária utilizada para encontrar o registro desejado
void ReferenciaBibliografica::readKey() {
	char s[80];
	cout << "\n	Digite o título do livro: ";
	cin.getline(s, 80);
	strncpy(titulo, s, tituloLen);
}

// Faz a escrita na saída do console da bibliografia
ostream& ReferenciaBibliografica::writeLegibly(ostream& out) {
	titulo[tituloLen] = autor[autorLen] = local[localLen] = editora[editoraLen] = '\0';
	out << "--> " << autor << ". " << titulo << ". " << edicao << "ªed. " << local << ": " << editora << ", " << ano;
	return out;
}

// Faz a leitura dos dados inseridos pelo usuário a partir do console
istream& ReferenciaBibliografica::readFromConsole(istream& in) {
	titulo[tituloLen] = autor[autorLen] = local[localLen] = editora[editoraLen] = '\0';
	char s[80];
	cout << "\nTítulo: ";
	in.getline(s, 80);
	strncpy(titulo, s, tituloLen);
	cout << "Autor: ";
	in.getline(s, 80);
	strncpy(autor, s, autorLen);
	cout << "Edição: ";
	in >> edicao;
	in.ignore();
	cout << "Local: ";
	in.getline(s, 80);
	strncpy(local, s, localLen);
	cout << "Editora: ";
	in.getline(s, 80);
	strncpy(editora, s, editoraLen);
	cout << "Ano: \n";
	in >> ano;
	in.ignore();
	return in;
}
		 
