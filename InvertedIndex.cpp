#include "InvertedIndex.hpp"
#include "Util.hpp"
#include "NoReferencia.hpp"
#include "CabecalhoDados.hpp"       

/*
* brief: insere referência no arquivo de dados para obtenção da chave secundária
* pre: nenhuma
* pos: referência inserida no arquivo
*/
void InvertedIndex::insere(Referencia referencia)
{
    std::ofstream file_obj;
    f = fopen("dados.txt","a");
    fprintf(f, "%s:%s:%d:%s:%s:%d\n", referencia.nome, referencia.autor, 
                                            referencia.edicao, referencia.local, 
                                            referencia.editora, referencia.ano);
    fclose(f);
    
    
}

/*
* brief: construtor para inicializar o arquivo de dados
* pre: nenhuma
* pos: arquivo de dados para as chaves secundárias criado
*/
InvertedIndex::InvertedIndex(const std::string &filename) : Arquivo(filename) {

}

/*
* brief: implementação do índice invertido e obtenção dos índices referente à chave
* param: chave secundária (ano da referência) e nome do arquivo
* pre: arquivo de dados não vazio
* pos: índices obtidos por meio da busca pela chave secundária no arquivo de dados
*/
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

/*
* brief: obtenção do índice correspondente à chave obtida por meio da lista invertida
* param: vetor contendo os índices e posição do vetor
* pre: vetor contendo os índices
* pos: índices obtidos
*/
int InvertedIndex::getData (std::vector<location> v, size_t i)
{
   return v[i].line_number;
}