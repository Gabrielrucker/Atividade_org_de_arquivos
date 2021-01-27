#ifndef NOREFERENCIA_HPP
#define NOREFERENCIA_HPP

/*
* \file NoReferencia.hpp
* \class NoReferencia
* \brief Responsável por representar um nó de Referencia
* \author Carlos Pedroso
* \author Eduardo Cembranel
*/

#include "Referencia.hpp"

class NoReferencia
{
   public:
      Referencia referencia;
      int prox;

      /* brief: construtor padrao
      * pre: nenhuma
      * pos: nenhuma
      */
      NoReferencia ();

      /* brief: setter Referencia
      * param: Referencia
      * pre: nenhuma
      * pos: Referencia inserida
      */
      void setReferencia (Referencia);

      /* brief: setter: posProx
      * param: posicao
      * pre: nenhuma
      * pos: posicao inserida
      */
      void setProx (int);

      /* brief: getter: posicao do No proximo
      * pre: nenhuma
      * pos: retorna a posicao do No proximo
      */
      int getProx ();

};

#endif // !NOREFERENCIA_HPP