#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <string>

#include "App.hpp"
#include "Util.hpp"

/* brief: construtor padrao: inicializa os arquivos de dados e indice
* pre: nenhuma
* pos: arquivos inicializados 
*/

using namespace std;

App::App ()
{
   arq  = new ArquivoDados("dados.bin");
   arq2 = new ArquivoIndice("indices.bin");
   arq3 = new InvertedIndex("indices-invertidos.bin");
}

/* brief: faz a escolha da opção do usuário sobre qual função utilizar
* pre: arquivos deve estar carregados
* pos: levar o usuário a uma função escolhida 
*/
void App::run ()
{
   int escolha;
   do
   {
      this->mostraMenu();
      std::cin >> escolha;
      Util::flushInput();
      switch (escolha)
      {
         case CARREGA_ARQUIVO:
            this->carregaArquivo();
            break;
         case INSERE_REFERENCIA:
            this->insereDado();
            break;
         case ALTERA_REFERENCIA:
            this->alteraReferencia();
            break;
         case BUSCA_REFERENCIA:
            this->buscaReferencia();
            break;
         case REMOVE_REFERENCIA:
            this->removeReferencia();
            break;
         case IMPRIME_CADASTRO:
            this->imprimirCadastro();
            break;
         case IMPRIME_ARVORE:
            this->arq2->mostrarPorNivel();
            break;
         case SAIR:
            break;
         default:
            std::cout << "\nOpcao invalida!\n";
            Util::pressRetornar();  
            break;
      }
   } while (escolha != SAIR);
}

/* brief: insere a referencia no arquivo de dados e a chave no arquivo de indice
* pre: nenhum
* pos: ter inserido a referencia na arvore e no arquivo
*/
void App::insereDado ()
{
   Util::clear();
   std::cout << "[Inserir Referencia]\n\n";

   Referencia elem;
   elem.setReferencia();
   
   bool erro = false;

   if (elem.autor <= 0)
   {
      std::cout << "\nAutor invalido!\n";
      erro = true;
   }
   if (Util::ehNula(elem.local))
   {
      std::cout << "\nLocal invalido!\n";
      erro = true;
   }
   if (elem.local <= 0)
   {
      std::cout << "\nLocal invalido!\n";
      erro = true;
   }
   if (Util::ehNula(elem.editora))
   {
      std::cout << "\nEditora invalida!\n";
      erro = true;
   }
   if (elem.editora <= 0)
   {
      std::cout << "\nEditora invalida!\n";
      erro = true;
   }
   if (elem.edicao <= 0)
   {
      std::cout << "\nEdicao invalida!\n";
      erro = true;
   }
   if (elem.ano <= 0)
   {
      std::cout << "\nAno invalido!\n";
      erro = true;
   }
   if (erro == false)
   {
      int pos = arq->insere(elem);
      arq2->insere(elem.nome, pos);
      std::cout << "\nReferencia inserida com sucesso!\n";
   }
   else
   {
      std::cout << "\nNao foi possivel inserir os dados!\n";
   }
   Util::pressRetornar();
}

/* brief: percorre chave por chave da arvore b, 
* retornando os indices do arquivo de dados correspondente aos dados, 
* obtem os dados e imprime-os
* pre: nenhum
* pos: ter imprimido os dados dos médicos, caso existentam 
*/
void App::imprimirCadastro ()
{
   std::vector<int> indices = this->arq2->getIndices();

   Util::clear();
   std::cout << "[Cadastros]\n";
   if (indices.size() == 0)
      std::cout << "\nNenhuma referencia cadastrado!\n";
   else
      for (int i = 0; i < indices.size(); ++i)
      {
         NoReferencia temp = this->arq->getData(indices[i]);
         std::cout << temp.referencia << "\n";
      }
   Util::pressRetornar();
}

/* brief: Faz a busca pelo médico desejado a partir do seu ID
* pre: nenhuma
* pos: mostrar na tela os dados do médico, caso exista
*/
void App::buscaReferencia ()
{
   int op;
   Util::clear();
   std::cout << "[Buscar dados de Referencia]\n\n1)Pelo Nome \n2)Pelo Ano\n\nSelecione uma opcao: ";
   std::cin >> op;
   Util::flushInput();
   if(op == 1)
   {
      char nome[STR_SIZE];
      std::cout << "\n\nDigite o nome: ";
      std::cin.getline(nome, sizeof(nome));
      int indice = this->arq2->getIndice(nome);
      if (indice == -1)
      {
         std::cout << "\nReferencia nao encontrada (Nome invalido)!\n";
      }
      else
      {
         NoReferencia temp = this->arq->getData(indice);
         std::cout << temp.referencia << "\n";
      }  
   }
   else if(op == 2)
   {
      InvertedIndex inv;
      int ano;
      inv.addfile("entrada.txt");
      std::cout << "\n\nDigite o ano: ";
      std::cin >> ano;
      bool x = inv.search(ano);
   }
   Util::pressRetornar();
}

/* brief: Faz a remoção da referência a partir de um nome buscado
* pre: o usuário ter passado um nome válido para busca
* pos: os dados da referência terem sido removido 
*/
void App::removeReferencia ()
{
   Util::clear();
   std::cout << "[Remover referencia]\n\nInsira o nome: ";
   char nome[STR_SIZE];
   std::cin.getline(nome, sizeof(nome));
   int indice = this->arq2->remove(nome);
   if (indice == -1)
   {
      std::cout << "\nReferencia nao encontrada (Nome invalido)!\n";
   }
   else
   {
      this->arq->remove(indice);
      std::cout << "\nReferencia removido com sucesso!\n";
   }
   Util::pressRetornar();
}

/* brief: mostra na tela o menu de opções para o usuário
* pre: nenhuma
* pos: ter printado na tela as informações necessárias
*/
void App::mostraMenu ()
{
   Util::clear();
   std::cout << "[Cadastramento de Referencias]\n\n"
             << "[1] Carregar arquivo de incializacao\n"
             << "[2] Inserir referencia\n"
             << "[3] Alterar referencia\n"
             << "[4] Buscar dados de referencia\n"
             << "[5] Remover referencia\n"
             << "[6] Imprimir cadastro\n"
             << "[7] Imprimir arvore B\n"
             << "[8] Sair\n\n"
             << ">> ";
}

/* brief: Faz a alteração dos dados já cafastrados do médico
* pre: médico desejado ja ter sido inserido no arquivo
* pos: ter alterado os dados do médico desejado
*/
void App::alteraReferencia ()
{
   Util::clear();
   char nome[STR_SIZE];
   std::cout << "[Alterar referencia]\n\nInsira o nome: ";
   std::cin.getline(nome, sizeof(nome));
   int indice = this->arq2->getIndice(nome);
   if (indice == -1)
   {
      std::cout << "\nReferencia nao encontrada (Nome invalido)!\n";
   }
   else
   {
      NoReferencia dado = this->arq->getData (indice);
      std::cout << dado.referencia << "\n"
                << "Selecione a informacao a ser alterada:\n"
                << "[1] Nome\n"
                << "[2] Autor\n"
                << "[3] Edicao\n"
                << "[4] Local\n"
                << "[5] Editora\n"
                << "[6] Ano\n"
                << "[7] Voltar\n\n"
                << ">> ";
      enum opcoes { NOME = 1, AUTOR, EDICAO, LOCAL, EDITORA, ANO, VOLTAR };
      int escolha;
      std::cin >> escolha;
      Util::flushInput();
      bool erro = false;
      if (escolha >= NOME && escolha <= ANO)
      {
         switch (escolha)
         {
            case NOME:
               std::cout << "\nNovo Nome: ";
               std::cin.getline(dado.referencia.nome, sizeof(dado.referencia.nome));
               if (Util::ehNula(dado.referencia.nome))
               { 
                  std::cout << "\nNome invalido!\n";
                  erro = true;
               }
               break;
            case AUTOR:
               std::cout << "\nNovo autor: ";
               std::cin.getline(dado.referencia.autor, sizeof(dado.referencia.autor));
               if (Util::ehNula(dado.referencia.autor))
               { 
                  std::cout << "\nAutor invalido!\n";
                  erro = true;
               }
               break;
            case EDICAO:
               std::cout << "\nNova edicao: ";
               std::cin  >> dado.referencia.edicao;
               break;
            case LOCAL:
               std::cout << "\nNovo local: ";
               std::cin.getline(dado.referencia.local, sizeof(dado.referencia.local));
               if (!Util::ehNula(dado.referencia.local))
               { 
                  std::cout << "\nLocal invalido!\n";
                  erro = true;
               }
               break;
            case EDITORA:
               std::cout << "\nNova editora: ";
               std::cin.getline(dado.referencia.editora, sizeof(dado.referencia.editora));
               if (!Util::ehNula(dado.referencia.editora))
               { 
                  std::cout << "\nEditora invalida!\n";
                  erro = true;
               }
               break;
            case ANO:
               std::cout << "\nNovo ano: ";
               std::cin  >> dado.referencia.ano;
               break;
         }
         if (erro == false)
         {
            this->arq->insereNo(&dado, indice);
            std::cout << "\nDado alterado com sucesso!\n";
         }
         else
            std::cout << "\nNao foi possivel alterar o dado!\n";
         
      }
      else if (escolha != VOLTAR)
      {
         std::cout << "\nOpcao invalida!\n";
      }
   }
   Util::pressRetornar();
}

/* brief: Carrega o arquivo de dados para a memória
* pre: o Arquivo existir e ser válido
* pos: ter carregado parte do arquivo para a memória
*/
void App::carregaArquivo ()
{
   Util::clear();
   std::cout << "[Carregar arquivo de inicializacao]\n\nInsira o nome do arquivo: ";
   std::string fileName;
   std::cin >> fileName;
   Util::flushInput();

   std::ifstream fBuffer(fileName, std::ios::in);
   if (fBuffer.fail())
   {
      std::cout << "\nArquivo nao encontrado!\n";
   }
   else
   {
      std::string linha;
      while (std::getline(fBuffer, linha))
      {
         std::vector<std::string> info = Util::splitString(linha, ':');
         Referencia elem;
         elem.edicao              = Util::strToInt(info[2]);
         elem.ano                 = Util::strToInt(info[5]);
         // elem.id                  = Util::strToInt(info[0]);
         strcpy(elem.nome,          info[0].c_str());
         strcpy(elem.autor,         info[1].c_str());
         strcpy(elem.local,         info[3].c_str());
         strcpy(elem.editora,       info[4].c_str());   
         int pos = arq->insere(elem);
         arq2->insere(elem.nome, pos);
         arq3->insere(elem.ano, pos);
      }
      std::cout << "\nArquivo carregado com sucesso!\n";
   }
   fBuffer.close();
   Util::pressRetornar();
}

App::~App ()
{
   delete arq;
   delete arq2;
}