#include "WordVector.hpp"
#include <iostream>

WordVector :: WordVector( ContextWords & context ){

  for( auto elem : context.getInformativeWords() ){
    this->bagOfWords.push_back( elem );
    this->vocabulary.push_back( elem->getText() );
  }

}

WordVector :: WordVector( std::vector< class Word * > &words ){

  for( auto elem : words ){
    this->bagOfWords.push_back( elem );
    this->vocabulary.push_back( elem->getText() );
  }

}

void WordVector :: printVocab(){

  for( auto elem : this->vocabulary )
    std::cout << elem << " " ;
  std::cout << std::endl;

}

std::vector< std::string > WordVector:: getVocabulary(){
  std::vector< std::string > vocab;

  for( auto elem : this->vocabulary )
    vocab.push_back(elem);
  return vocab;
}

void WordVector:: inputFill( int window ){
  int rows, cols;
  cols = rows = this->vocabulary.size();
  std::cout << cols << std::endl;
  this->co_occurance.resize(rows, cols);
  this->co_occurance << ( Eigen::MatrixXd::Zero(rows, cols));

  for( int hotSpot = 0; hotSpot < rows; hotSpot++ ){
    int from, upto, trace;

    trace = from = ( hotSpot - window ) >= 0 ? ( hotSpot - window ) : 0;
    upto = ( hotSpot + window ) < cols ? ( hotSpot + window ) : cols-1;

    while( trace <= upto ){
      if( hotSpot != trace ) co_occurance( hotSpot, trace )++;
      trace++;
    }

  }

  std::cout << "Matrix M is :- " << std::endl << this->co_occurance << std::endl;

}
