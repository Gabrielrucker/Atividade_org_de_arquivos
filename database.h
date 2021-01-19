#ifndef DATABASE
#define DATABASE
#include <fstream>
#include <cstring>
#include <iostream>

// protótipo das funções e construtor da classe

template<class T>

class Database{
public:
	Database();
	void run();
private:
	fstream database;
	char fName[20];
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