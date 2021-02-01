#ifndef INVERTEDINDEX_HPP
#define INVERTEDINDEX_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

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

    /*
    * brief: insere referência no arquivo de dados para obtenção da chave secundária
    * pre: nenhuma
    * pos: referência inserida no arquivo
    */
    void insere(Referencia);

    /*
    * brief: construtor para inicializar o arquivo de dados
    * pre: nenhuma
    * pos: arquivo de dados para as chaves secundárias criado
    */
    InvertedIndex(const std::string &);

    /*
    * brief: implementação do índice invertido e obtenção dos índices referente à chave
    * param: chave secundária (ano da referência) e nome do arquivo
    * pre: arquivo de dados não vazio
    * pos: índices obtidos por meio da busca pela chave secundária no arquivo de dados
    */
    std::array<int,10> invertedIndex(int, std::string);

    /*
    * brief: obtenção do índice correspondente à chave obtida por meio da lista invertida
    * param: vetor contendo os índices e posição do vetor
    * pre: vetor contendo os índices
    * pos: índices obtidos
    */
    int getData (std::vector<location>, size_t);

};

#endif
