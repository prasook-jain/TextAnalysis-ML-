#ifndef CONTEXT_WORDS_INCLUDE
#define CONTEXT_WORDS_INCLUDE

#include "Word.hpp"
#include <vector>
#include <utility>
#include <fstream>

/*Modified these class as each object file contain context of
  one input file or sample.
*/


class ContextWords{

private:

  //static int lastId;

  static long long int idGenerator(){
    static long long int lastId = 0;
    return lastId++;
  }

  const long long int id;
  std::string fileName;
  std::vector< class Word * > dictionary;

  void scanFile( std::ifstream & );
  void updateContext( std::string );
  std::string parseText( std::string & );
  class Word* findTextInVocab( std::string & );
  //void sortVectorization();

  //Static functions
  static const std::vector< std::string > ignoreWord;

public:

  //ContextWords( std::initializer_list< std::string > );
  void addContext( std::string );
  ContextWords( std::string & );
  void printContextDetails( int option );
  void printInformativeContextDetails( int option );
  std::vector< class Word * > getInformativeWords();

};

#endif
