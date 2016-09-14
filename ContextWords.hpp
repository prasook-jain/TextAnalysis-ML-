#ifndef CONTEXT_WORDS_INCLUDE
#define CONTEXT_WORDS_INCLUDE

#include "Word.hpp"
#include <vector>
#include <utility>
#include <fstream>
#include <initializer_list>

class ContextWords{

private:

  int numOfFiles = 0;
  std::vector< std::string > files;
  std::vector< class Word * > dictionary;
  std::vector< class Word * > informativeDict;

  static const std::vector< std::string > ignoreWord;

  void scanFile( std::ifstream & );
  void updateContext( std::string );
  std::string parseText( std::string & );
  void sortVectorization();
  void addContext( std::string );
  class Word* findPos( std::string & );

public:

  //ContextWords( std::initializer_list< std::string > );
  void findInformativeWord();
  ContextWords( std::vector< std::string > & );
  void printContextDetails( int option );
  void printInformativeContextDetails( int option );
  std::vector < class Word * > getInformativeWords();

};

#endif
