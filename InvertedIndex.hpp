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

    FILE *f;

    #define MAX_CAMINHO 256

    std::vector<location> word_loc;

public:

    void insere(Referencia);

    InvertedIndex(const std::string &);

    std::array<int,10> invertedIndex(int, std::string);

    int getData (std::vector<location>, size_t);

    void transformaArquivo(char[MAX_CAMINHO], char[MAX_CAMINHO]);

};
