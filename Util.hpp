#ifndef UTIL_HPP
#define UTIL_HPP

#include <string>
#include <vector>

/*
* \file Util.hpp
* \class Util
* \brief Classe totalmente privada, com metodos gerais e auxiliares
* \author Carlos Pedroso
* \author Eduardo Cembranel
*/

class Util
{
   public:
      /* brief: Faz o split do vetor de strings
      * param: uma string com as informações do médico e um caracter divisor de dados (:)
      * pre: Nenhuma
      * pos: dividir a string em pedaços menores
      */
      static std::vector<std::string> splitString (std::string, char);

      /* brief: limpa a tela do console
      * pre: nenhuma
      * pos: tela limpada do console
      */
      static void clear ();

      /* brief: exibe a mensagem esperando por um ENTER e aguarda o mesmo
      * pre: buffer de entrada esta limpo
      * pos: nenhuma
      */
      static void pressRetornar();

      /* brief: limpa os dados de entrada, para tirar espaços desnescessários
      * pre: nenhuma
      * pos:ter retirado os espaços desnecessários
      */
      static void flushInput ();

      /* brief: transforma os caracteres em inteiros
      * pre: a string ser válida
      * pos: passar os caracteres transformados em números
      */
      static int strToInt (const std::string &);

      /* brief: verifica se a string é nula
      * pre: nenhuma
      * pos: retorna se o comprimento da string é maior que 0
      */
      static bool ehNula(const std::string &);

   private:
      /* brief: construtor privado, impossibilitando a instancia de objetos
      * pre: nenhuma
      * pos: nenhuma
      */
      Util ();
};

#endif // !UTIL_HPP