#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<fstream>
#include<sstream>
#include"Arquivo.hpp"
using namespace std;

struct word_position
{
  int index;
};

class InvertedIndex
{
  private:
    map<int,vector<word_position>> Dictionary;

  public:

    InvertedIndex inv();

    InvertedIndex();

    InvertedIndex(const string &);

    void insere(int, int);

    void addfile(const string&);

    void show_files();

    bool search(int);

    void modify(int);

};
