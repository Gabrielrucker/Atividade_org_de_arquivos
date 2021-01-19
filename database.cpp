
#include "referenciabibliografica.h"
#include "database.h"

#include <fstream>
#include <cstring>
#include <iostream>

// Classe Database é do tipo genérica <T>
template<class T>
Database<T>::Database() {
}

// método para adicionar o registro ao arquivo
template<class T>
void Database<T>::add( T& d) {	
	database.open(fName, ios::in | ios::out | ios::binary);
	if (!database) {
		cout << " -> Erro ao abrir arquivo." << endl;
		return;
	}
	database.seekg(0, ios::end); //insere no final do arquivo
	d.writeToFile(database);
	database.close();
}

// método para realizar a modificação de um registro do arquivp
template<class T>
void Database<T>::modify(const T& d) {
	T tmp;
	database.open(fName, ios::in | ios::out | ios::binary);
	if (!database) {
		cout << " -> Erro ao abrir arquivo." << endl;
		return;
	}
	while (!database.eof()) { // lê enquanto não chegar ao final do arquivo
		tmp.readFromFile(database);
		if (tmp == d) {  //sobrecarregado ==
			cin >> tmp; //sobrecarregado >>
			database.seekp(-d.size(), ios::cur); // encontra a posição correta para modificação
			tmp.writeToFile(database);
			database.close();
			return;
		}
	}
	database.close();
	cout << "O registro a ser modificado nao esta no banco de dados! \n";
}

// Método para procurar pelo registro contido dentro do arquivo
template<class T>
bool Database<T>::find(const T& d) {
	T tmp;
	database.open(fName, ios::in | ios::out | ios::binary);//ios:: in |
	if (!database) {
		cout << " -> Erro ao abrir arquivo." << endl;
		return false;
	}
	while (!database.eof()) {
		tmp.readFromFile(database);
		if (tmp == d) { // sobrecarregado == 
			database.close();
			return true;
		}
	}
	database.close();
	return false;
}

// Método que retorna um booleano de acordo com a existência do arquivo
template<class T>
bool Database<T>::fileExists(char* fName)
{
	fstream fs;
	fs.open(fName, std::fstream::in | std::fstream::out | std::fstream::app);
	if(fs)
		return true;
	return false;
}

// Método para mostrar os valores contidos no arquivo na saída
template<class T>
ostream& Database<T>::print(ostream& out) {
	T tmp;
	database.open(fName, ios::in | ios::out | ios::binary);
	while (true) {
		tmp.readFromFile(database);
		if (database.eof())
			break;
			out << tmp << endl; //sobrecarregado <<
	}
	database.close();
	return out;
}

// Método de execução que será utilizado para as operações dentro do arquivo
template<class T>
void Database<T>::run(){
	cout << " Nome do arquivo: ";
	cin >> fName;
	fileExists(fName); //verifica se o arquivo existe

	char option[5];
	T rec;
	cout << "\n1. Adicionar;  2. Procurar; 3. Modificar Registro; 4. Sair\n";
	cout << "\nEntre uma opcao: ";
	cin.getline(option, 4); //obtem o '\n';
	while (cin.getline(option, 4)) {
		if (*option == '1') {
			cin >> rec; // recebe os dados de entrada do usuário
			add(rec); // adiciona o registro ao arquivo
		}
		else if (*option == '2') {
			rec.readKey(); // lê a chave primária introduzida pelo usuário
			if (find(rec) == false) { // verifica a existência da chave no arquivo
				cout << "\nO registro ";
				cout << "não ";
				cout << "está no banco de dados!\n\n";
			}
		}
		else if (*option == '3') {
			rec.readKey(); // lê a chave primária
			modify(rec);   // e modifica o registro
		}
		else if (*option != '4')
			cout << "\nOpcao nao reconhecida!\n";
		else return;
		cout << *this; // repete
		cout << "\nEntre com uma opcao: ";
	}
}



int main() {
	Database<ReferenciaBibliografica>().run(); // executa
	return 0;
}



