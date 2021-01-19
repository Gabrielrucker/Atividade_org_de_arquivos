#ifndef DATABASE
#define DATABASE
#include <fstream>
#include <cstring>
#include <iostream>
#include "arvoreb.h"

// protótipo das funções e construtor da classe

template<class T>

class Database{
public:
	Database();
	void run();
private:
	fstream database;
	fstream arqIndPrim;
	char fName[20];
	char fPrimName[20] = "ArqIndPrim";
	ostream& print(ostream&);
	void add(T&);
	bool find(const T&);
	bool fileExists(char* fName);
	void modify(const T&);
	friend ostream& operator<<(ostream& out, Database& db) {
		return db.print(out);
	}
};
#endif