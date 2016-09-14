#include <iostream>
#include "Word.hpp"

Word :: Word( std::string text, WordType type ) : type(type), text(text), uniId( idGenerator() ) {
  this->description = "";
}

int Word :: findVectorPos( int value ){
  int count = -1;
  for( auto elem : this->vectorization ){
    count++;
    if( value == elem.first ) return count++;
  }
  return -1;
}

void Word :: printDetails( int i ){

  std::cout << "ID : " << this->uniId << std::endl;
  std::cout << "Text : " << this->text << std::endl;
  std::cout << "Description : " << this->description << std::endl;
  std::cout << "Type : " << this->type << std::endl;
  std::cout << "Vectorization Details :\t";
  for( auto elem : this->vectorization )
    std::cout << " <" << elem.first << ", " << elem.second << " > ";

}

void Word :: shortPrint(){
  std::cout << "ID : " << this->uniId << " ";
  for( auto elem : this->vectorization )
    std::cout << " < " << elem.first << ", " << elem.second << " > ";
}

WordType Word:: getType(){ return this->type; }

std::string Word :: getText() const { return this->text; }
