#include "Referencia.hpp"
#include "Util.hpp"

/* brief: mostra na tela os dados da referência bibliográfica
* param: ponteiro para a saida de dados, ponteiro para o identificador da referência bibliográfica
* pre: as informações da referência terem sido carregadas
* pos: nenhuma
*/
std::ostream& operator<< (std::ostream &out, const Referencia &referencia)
{
   out << "\n"
       << "Nome:                    " << referencia.nome          << "\n"
       << "Autor:                   " << referencia.autor         << "\n"
       << "Edicao:                  " << referencia.edicao        << "\n"
       << "Local de publicacao:     " << referencia.local         << "\n"
       << "Editora:                 " << referencia.editora       << "\n"
       << "Ano de publicacao:       " << referencia.ano           << "\n";
   return out;
}

/* brief: Seter da classe
* pre: nenhuma
* pos: nenhuma
*/
void Referencia::setReferencia ()
{
   std::cout << "Nome: ";
   std::cin.getline(this->nome, sizeof(this->nome));
   std::cout << "Autor: ";
   std::cin.getline(this->autor, sizeof(this->autor));
   std::cout << "Edicao: ";
   std::cin  >> this->edicao;
   Util::flushInput();
   std::cout << "Local: ";
   std::cin.getline(this->local, sizeof(this->local));
   std::cout << "Editora: ";
   std::cin.getline(this->editora, sizeof(this->editora));
   std::cout << "Ano de publicacao: ";
   std::cin  >> this->ano;
   Util::flushInput();
}