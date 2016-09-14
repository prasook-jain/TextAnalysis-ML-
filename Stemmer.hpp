#ifndef STEMMER_HEADER
#define STEMMER_HEADER

#include "Word.hpp"
#include "ContextWords.hpp"
class ContextWords;

class Stemmer{

public:
  Stemmer( std::vector< class Word * > & );
  Stemmer( ContextWords & );
private:
  std::vector< class Word * > words;
};

#endif
