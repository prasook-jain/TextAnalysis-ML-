/*
It is a Word to Vector algorithm which find relation in between
words in the context with finding the
*/

#ifndef WORD_VECTOR_HEADER
#define WORD_VECTOR_HEADER

#include "ContextWords.hpp"
#include "Eigen/Dense"
#include "Eigen/SVD"
#include <string>
#include <vector>
#include <map>
//#include <cstdarg>

class WordVector{
public:

  WordVector( std::vector< class ContextWords * >  );//Pass the ContextWords parameter
  //WordVector( ContextWords & );
  //WordVector( std::vector< class Word * > & ); //Pass the word present in context
  void inputFill( int );
  void computeSVD();

private:
  Eigen:: MatrixXd co_occurance,U,V,M;
  std::vector< class Word * > getInfoWords;
  std::map< int, int> indexInfo;
  std::vector< class ContextWords * > contextList;
};

#endif
