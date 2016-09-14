#include <iostream>
#include "Stemmer.hpp"

/*Constructor to take informative Vectorized word form the ContextWords.
*/

Stemmer :: Stemmer( std::vector< class Word * > &infoWords ){
  for( auto elem : infoWords )
  this->words.push_back(elem);
}

Stemmer :: Stemmer( ContextWords & context ){
  for( auto elem : context.getInformativeWords() ){
    this->words.push_back(elem);
  }
}
