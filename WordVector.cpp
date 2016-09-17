#include "WordVector.hpp"
#include <iostream>

class Word;
WordVector :: WordVector( std::vector< class ContextWords * > contexts ){

  for( auto elem : contexts ){
    this->contextList.push_back(elem);
  }

  int i=0;
  for( auto elem : Word::getOnlyInfoVocab() ){
    //std::cout << elem->getText() << std::endl;
    this->getInfoWords.push_back( elem );
    this->indexInfo[ elem->getId() ] = i;
    i++;
  }

}

void WordVector:: inputFill( int window ){
  int rows, cols;
  cols = rows = this->getInfoWords.size();
  std::cout << cols << std::endl;
  this->co_occurance.resize(rows, cols);
  this->co_occurance << ( Eigen::MatrixXd::Zero(rows, cols) );

  for( auto mele : this->indexInfo ){
    std::cout << mele.first << ":" << mele.second << std::endl;
  }

  for( auto elem : this->contextList ){

    std::vector< class Word * > temp = elem->getInformativeWords();
    rows = cols = temp.size();

    for( auto elem : temp ){
      std::cout << elem->getId() << ":" << elem->getText() << std::endl;
    }
    for( int hotSpot = 0; hotSpot < rows; hotSpot++ ){
      int from, upto, trace;

      trace = from = ( hotSpot - window ) >= 0 ? ( hotSpot - window ) : 0;
      upto = ( hotSpot + window ) < cols ? ( hotSpot + window ) : cols-1;
      while( trace <= upto ){
        if( hotSpot != trace )
          co_occurance( this->indexInfo[temp[ hotSpot ]->getId()], this->indexInfo[temp[ trace ]->getId()] )++;
        trace++;
      }
    }
  }
  //std::cout << "Matrix M is :- " << std::endl << this->co_occurance << std::endl;

}

void WordVector::computeSVD(){
  Eigen::JacobiSVD<Eigen::MatrixXd> svd(this->co_occurance, Eigen::ComputeThinU | Eigen::ComputeThinV );
  std::cout << "Singular Value :- " << std::endl << svd.singularValues() << std::endl;
  if(svd.computeU())
    std::cout << "U matrix :- " << std::endl << svd.matrixU() << std::endl;
  else{
    std::cout << "Enable to compute" << std::endl;
  }
  if(svd.computeV())
    std::cout << "V matrix :- " << std::endl << svd.matrixV() << std::endl;
  else{
    std::cout << "Enable to compute" << std::endl;
  }
}
