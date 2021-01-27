#include "NoReferencia.hpp"
#include "CabecalhoDados.hpp"
#include <iostream>

/* brief: construtor padrao
* pre: nenhuma
* pos: nenhuma
*/
NoReferencia::NoReferencia () {}

/* brief: setter Referencia
* param: Referencia
* pre: nenhuma
* pos: Referencia inserido
*/
void NoReferencia::setReferencia (Referencia other)
{
   this->referencia = other;
}

/* brief: setter: posProx
* param: posicao
* pre: nenhuma
* pos: posicao inserida
*/
void NoReferencia::setProx (int prox)
{
   this->prox = prox;
}

/* brief: getter: posicao do No proximo
* pre: nenhuma
* pos: retorna a posicao do No proximo
*/
int NoReferencia::getProx ()
{
   return this->prox;
}