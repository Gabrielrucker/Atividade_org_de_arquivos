#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

#include "InvertedIndex.hpp"
#include "Util.hpp"
#include "LinkedListNode.hpp"


InvertedIndex::InvertedIndex(const std::string &filename) : Arquivo(filename) {
   this->setCabecalho(this->out);
}

void InvertedIndex::insere(int chave, int indice, Node *h) {
    LinkedListNode *l(chave, indice);
    l->push(&h, chave);
    this->setCabecalho(this->out);
}

void InvertedIndex::setCabecalho(std::ofstream &file) {
   file.seekp(0);
   file.write((char*)this, sizeof(int));
   file.flush();
}

bool InvertedIndex::is_whitespace(const std::string &s) {
    return std::all_of(s.begin(), s.end(), isspace);
}

int InvertedIndex::invertedIndex(int chave) {
    int indice;
    std::string line;
    std::ifstream input_file("entrada.txt");
    std::map<int, std::vector<location>> word_map;

    int line_number = 0;
    int word_number = 0;

    if (input_file.is_open()) {
        while (getline(input_file, line)) {
            std::vector<std::string> info = Util::splitString(line, ':');
            location loc{};
            word_number = 0;
            int ano = Util::strToInt(info[5]);
            if(ano == chave) {
                word_number++;
                loc.line_number = line_number;
                loc.position = word_number;
                word_map[ano].push_back(loc);
            }  
            line_number++;
        }

    for (auto &it : word_map) {
        auto vec = it.second;
        std::cout << it.first << " " << vec.size() << " [";
        for (size_t i = 0; i < vec.size(); i++) {
            std::cout << "(" << vec[i].line_number << "," << vec[i].position << ")";
            if (i != vec.size() - 1)
                std::cout << ", ";
                indice = getData(vec, i);
        }
        std::cout << "]";
        std::cout << std::endl;
    }
    input_file.close();
    }
    return indice;
}

  
// This function prints contents of 
// linked list starting from head  
void InvertedIndex::printList(Node *h)  
{
    Node *no = h;
    std::cout << no->data;
    std::cout << "\n";
    while (no != NULL)  
    {    
    std::cout << no->data << " --> ";
    no = no->next;
   }
   std::cout << "NULL \n";
   Util::pressRetornar();
}

int InvertedIndex::getData (std::vector<location> v, size_t i)
{
   return v[i].line_number;
}