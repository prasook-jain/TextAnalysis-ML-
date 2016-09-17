#include "Word.hpp"
#include <iostream>

std::vector<class Word *> Word::vocabulary;
int Word :: lastId = 0;

Word::Word( std::string text, WordType type ) : uniId( idGenerator() ), text(text), type(type) {
  this->description = "";
}

void Word::printDetails( int i ){

  std::cout << "ID : " << this->uniId << std::endl;
  std::cout << "Text : " << this->text << std::endl;
  std::cout << "Description : " << this->description << std::endl;
  std::cout << "Type : " << this->type << std::endl;
  std::cout << "Vectorization Details :\t";
  for( auto elem : this->vectorization )
    std::cout << " <" << elem.first << ", " << elem.second << " > ";

}

void Word::shortPrint(){
  std::cout << "ID : " << this->uniId << " ";
  for( auto elem : this->vectorization )
    std::cout << " < " << elem.first << ", " << elem.second << " > ";
}

WordType Word::getType() { return this->type; }

std::string Word::getText() { return this->text; }

int Word::getId() { return this->uniId; }

/*
  newWord function :- create a object save it's value in the static array list.
  The Word Object for each unique id is create once and each time other classes
  uses only its pointer reference. To save the space complexity of the program
*/
class Word * Word::newWord( std::string word, WordType type ){

  for( auto elem : Word::vocabulary ){
    if( elem->getText() == word ) return NULL;
  }
  Word *temp = new Word(word, type);
  temp->vectorization.reserve(10);
  Word::vocabulary.push_back(temp);

  return (Word::vocabulary[ Word::vocabulary.size()-1 ]);
}

std::vector< class Word * > Word::getVocabulary(){
  std::vector< class Word * > temp;
  for( auto elem : Word::vocabulary )
    temp.push_back( elem );
  return temp;
}


/* Return the pointer of word Object if find in vocabulary else NULL
*/
class Word * Word::findVectorPos( std::string & word ){
  for( auto elem : Word::vocabulary )
    if( elem->getText() == word )
      return elem;
  return NULL;
}

std::vector< class Word * > Word::getOnlyInfoVocab(){
  std::vector< class Word * > temp;

  for( auto elem : Word::vocabulary )
    if( elem->getType() == INFORMATIVE )
      temp.push_back( elem );

  return temp;
}
