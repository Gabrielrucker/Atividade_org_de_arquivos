#ifndef APP_HPP
#define APP_HPP

/*
* \file App.hpp
* \class App
* \brief Classe responsavel por gerenciar as funcionalidades do programa
* \author Carlos Pedroso
* \author Eduardo Cembranel
*/

#include <string>
#include <vector>

#include "ArquivoDados.hpp"
#include "ArquivoIndice.hpp"
#include "Referencia.hpp"
#include "InvertedIndex.hpp"

class App
{
   public:

      /* brief: construtor padrao: inicializa os arquivos de dados e indice
      * pre: nenhuma
      * pos: arquivos inicializados 
      */
      App ();
      
      /* brief: faz a escolha da opção do usuário sobre qual função utilizar
      * pre: arquivos deve estar carregados
      * pos: levar o usuário a uma função escolhida 
      */
      void run ();

      /* brief: esse é o destrutor da classe
      * pre: nenhuma
      * pos: liberar a memória alocada pelos arquivos
      */
      ~App ();

   private:
      ArquivoDados  *arq; //arquivo de dados (referências bibliográficas)
      ArquivoIndice *arq2; //arquivo de indices (arvore B)
      InvertedIndex *arq3;
      InvertedIndex inv;
      
      /* brief: percorre chave por chave da arvore b, 
      * retornando os indices do arquivo de dados correspondente aos dados, 
      * obtem os dados e imprime-os
      * pre: nenhum
      * pos: ter imprimido os dados das referências, caso existentam 
      */
      void imprimirCadastro ();

      /* brief: insere a referência no arquivo de dados e a chave no arquivo de indice
      * pre: nenhum
      * pos: ter inserido a referência na arvore e no arquivo
      */
      void insereDado ();

      /* brief: Faz a busca pelo referência desejada a partir do nome
      * pre: nenhuma
      * pos: mostrar na tela os dados da referência, caso exista
      */
      void buscaReferencia ();

      /* brief: Faz a alteração dos dados já cafastrados da referência
      * pre: referência desejada ja ter sido inserido no arquivo
      * pos: ter alterado os dados da referência desejada
      */
      void alteraReferencia ();

      /* brief: Faz a remoção da referência a partir de um nome buscado
      * pre: o usuário ter passado um nome válido para busca
      * pos: os dados da referência terem sido removidos 
      */
      void removeReferencia ();

      /* brief: mostra na tela o menu de opções para o usuário
      * pre: nenhuma
      * pos: ter printado na tela as informações necessárias
      */
      void mostraMenu ();

      /* brief: Carrega o arquivo de dados para a memória
      * pre: o Arquivo existir e ser válido
      * pos: ter carregado parte do arquivo para a memória
      */
      void carregaArquivo ();

      /* brief: Verifica se os valores passados são validos
      * pre: passagem dos dados lidos do arquivo
      * pos: retornar se os valores são verdadeiros ou não
      */
      bool ehValida (std::vector<std::string>);
      enum MenuEstado
      {
         CARREGA_ARQUIVO = 1,
         INSERE_REFERENCIA,
         ALTERA_REFERENCIA,
         BUSCA_REFERENCIA,
         REMOVE_REFERENCIA,
         IMPRIME_CADASTRO,
         IMPRIME_ARVORE,
         SAIR
      };
};

#endif // !APP_HPP