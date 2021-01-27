
#include "InvertedIndex.hpp"
#include "Util.hpp"
#include "Arquivo.hpp"

InvertedIndex::InvertedIndex() {}

InvertedIndex::InvertedIndex(const string &filename)
{

}

void InvertedIndex::insere(int ano, int index)
{
  word_position obj;
  obj.index = index;
  Dictionary[ano].push_back(obj);
}

void InvertedIndex::addfile(const string &filename)
{
  ifstream fp;
  fp.open(filename,ios::in);

  if(!fp)
  {
    cout<<"Arquivo não encontrado\n";
    return ;
  }

  string line;
  Util::splitString(line, ':');
  int ano;
  int line_number=0,ano_number=0;
  while(getline(fp,line))
  {
    line_number++;
    ano_number = 0;
    stringstream s(line);
    while(s>>ano)
    {
      ano_number++;
      word_position obj;
      /* obj.file_name = filename;
      obj.line = line_number; */
      obj.index = ano_number;
      Dictionary[ano].push_back(obj);
    }
  }
  fp.close();
}

void InvertedIndex::modify(int ano)
{
  bool find = search(ano);
  int novo_ano;
  map<int,vector<word_position>> newMap;
  if(find)
  {
      cout << "Digite o novo ano: ";
      cin >> novo_ano;
      int size = (int)Dictionary[ano].size();
      for(map<int,vector<word_position>>::iterator mi=Dictionary.begin(); mi != Dictionary.end(); mi++)
      {
        Dictionary[ano] = Dictionary[novo_ano];
      }
  }

}

bool InvertedIndex::search(int ano)
{
  if(Dictionary.find(ano)==Dictionary.end())
  {
    cout<<"No instance exist\n";
    return false;
  }

  int size = (int)Dictionary[ano].size();
  cout << size;
  for(int counter = 0;counter < size ;counter++)
  {
    cout<<counter+1<<":\n";
/*     cout<<"   Arquivo: "<<Dictionary[ano][counter].file_name<<endl;
    cout<<"   Número da linha: "<<Dictionary[ano][counter].line<<endl; */
    cout<<"   Índice: "<<Dictionary[ano][counter].index<<endl;
  }

  return true;
}