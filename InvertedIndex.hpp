#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

#include "LinkedListNode.hpp"
#include "Arquivo.hpp"


class InvertedIndex : public Arquivo {

private:
struct location {
    int line_number;
    int position;
};

    std::vector<location> word_loc;

    std::vector<location> vec;

public:

    InvertedIndex(const std::string&);

    void setCabecalho(std::ofstream &);

    bool is_whitespace(const std::string &);
    
    int invertedIndex(int);

    void insere(int, int, Node*);

    void printList(Node*);

    int getData (std::vector<location>, size_t);

};
