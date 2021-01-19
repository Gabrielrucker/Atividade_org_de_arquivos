#ifndef REFERENCIABIBLIOGRAFICA
#define REFERENCIABIBLIOGRAFICA

#include <fstream>
#include <cstring>
#include <iostream>

using namespace std;

// protótipos das funções utilizadas e construtores da classe
class ReferenciaBibliografica {
public:		
	ReferenciaBibliografica();
	//ReferenciaBibliografica(char* autor, char* titulo, int edicao, char* local, char* editora, int ano);
	ReferenciaBibliografica(char*, char*, int, char*, char*, int);
	void writeToFile(fstream&); 
	void readFromFile(fstream&);
	void readKey();
	int size() const {
		return autorLen + tituloLen + sizeof(edicao) + localLen + editoraLen + sizeof(ano);
	}
	bool operator==(const ReferenciaBibliografica& pr) const {
		return strncmp(pr.titulo, titulo, tituloLen) == 0;
	}
protected:
	const int autorLen, tituloLen, localLen, editoraLen;
	char *autor, *titulo, *local, *editora;
	int ano, edicao;
	ostream& writeLegibly(ostream&);
	friend ostream& operator<<(ostream& out, ReferenciaBibliografica& pr) {
		return pr.writeLegibly(out);
	}
	istream& readFromConsole(istream&);
	friend istream& operator>>(istream& in, ReferenciaBibliografica& pr) {
		return pr.readFromConsole(in);
	}	
};

#endif
