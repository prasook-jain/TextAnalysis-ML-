/*
It is a Word to Vector algorithm which find relation in between
words in the context with finding the
*/

#ifndef WORD_VECTOR_HEADE
#define WORD_VECTOR_HEADE

#include "Eigen/Dense"
#include "ContextWords.hpp"
#include <string>
#include <vector>
//#include <cstdarg>

class WordVector{
public:

  WordVector( ContextWords &, ContextWords &... );//Pass the ContextWords parameter
  WordVector( ContextWords & );
  WordVector( std::vector< class Word * > &); //Pass the word present in context
  std::vector< std::string > getVocabulary();
  void printVocab();
  void inputFill( int );

private:

  std::vector< std::string > vocabulary;
  std::vector< class Word * > bagOfWords;
  Eigen:: MatrixXd co_occurance;

};

#endif
