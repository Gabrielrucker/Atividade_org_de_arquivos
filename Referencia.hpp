#ifndef REFERENCIA_HPP
#define REFERENCIA_HPP


/*
* \file Referencia.hpp
* \class Referencia
* \brief Classe que representa a entidade "Referencia"
* \author Carlos Pedroso
* \author Eduardo Cembranel
*/

#include <iostream>

#define STR_SIZE 100

class Referencia
{
   public:
      int id;
      int edicao;
      int ano;
      char nome[STR_SIZE];
      char autor[STR_SIZE];
      char local[STR_SIZE];
      char editora[STR_SIZE];
      
      /* brief: Seter da classe
      * pre: nenhuma
      * pos: nenhuma
      */
      void setReferencia ();

      /* brief: mostra na tela os dados da referência
      * param: ponteiro para a saida de dados, ponteiro para o identificador da referência
      * pre: as informações da referência terem sido carregadas
      * pos: nenhuma
      */
      friend std::ostream& operator<< (std::ostream&, const Referencia&);

};

#endif // !REFERENCIA_HPP