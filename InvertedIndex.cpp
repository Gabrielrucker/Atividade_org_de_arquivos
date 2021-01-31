#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>


#include "InvertedIndex.hpp"
#include "Util.hpp"
#include "NoReferencia.hpp"
#include "CabecalhoDados.hpp"       

void InvertedIndex::insere(Referencia referencia)
{
    std::ofstream file_obj;
    f = fopen("dados.txt","a");
    fprintf(f, "%s:%s:%d:%s:%s:%d\n", referencia.nome, referencia.autor, 
                                            referencia.edicao, referencia.local, 
                                            referencia.editora, referencia.ano);
    fclose(f);
    
    
}

InvertedIndex::InvertedIndex(const std::string &filename) : Arquivo(filename) {

}

std::array<int, 10> InvertedIndex::invertedIndex(int chave, std::string filename) {
    std::string line;
    std::ifstream input_file(filename);
    std::map<int, std::vector<location>> word_map;
    std::array<int,10> indices;
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

    indices.fill(-1);
    for (auto &it : word_map) {
        auto vec = it.second;
        std::cout << it.first << " " << vec.size() << " [";
        for (size_t i = 0; i < vec.size(); i++) {
            std::cout << "(" << vec[i].line_number << "," << vec[i].position << ")";
            if (i != vec.size() - 1)
                std::cout << ", ";
            indices[i] = getData(vec,i);
        }
        std::cout << "]";
        std::cout << std::endl;
    }
    input_file.close();
    }
    return indices;
}

int InvertedIndex::getData (std::vector<location> v, size_t i)
{
   return v[i].line_number;
}

void InvertedIndex::transformaArquivo(char arquivoBin[MAX_CAMINHO], char arquivoRes[MAX_CAMINHO])
{
    FILE *arqBin, *arqRes;
    NoReferencia ref;
    int pos = 0;

    arqBin = fopen(arquivoBin, "rb");
    arqRes = fopen(arquivoRes, "w");

    fread(&ref, sizeof(CabecalhoDados) + sizeof(NoReferencia), 1, arqBin);
    while(!feof(arqBin)) {
        fprintf(arqRes, "%s:%s:%d:%s:%s:%d\n", ref.referencia.nome, ref.referencia.autor, 
                                            ref.referencia.edicao, ref.referencia.local, 
                                            ref.referencia.editora, ref.referencia.ano);
        fread(&ref, pos * sizeof(NoReferencia), 1, arqBin);
        pos++;
    }

    fclose(arqBin);
    fclose(arqRes);
}