#ifndef WORD_INCLUDE
#define WORD_INCLUDE

#include <vector>
#include <string>
#include <utility>
enum WordType { IGNORABLE, INFORMATIVE };

class Word{
  static std::vector< class Word *> vocabulary;
private:

  //Changing the structure of program to be more useful of Word.hpp
  //  Adding the static vocabulary for all words find out in a all context Passed
  //  From Context class only sa1ve the Pointers information,
  //  Add the time of initialization the pointer became more powerful

  const int uniId;           //Uniqe Id to each word scaned
  const std::string text;    // Text of the Word
  std::string description;   // brief meaning of the word or text
  WordType type;             // Type of the English word like Object, Subject,
                             // Verb, adjective, adverb...
  static int lastId; 

  // Assign Unique Id each time
  static int idGenerator(){
    return lastId++;
  }

public:
  static class Word * newWord( std::string , WordType );
  static std::vector< class Word * > getVocabulary();
  static std::vector< class Word * > getOnlyInfoVocab();
  static class Word * findVectorPos( std::string &word );

  int getId();
  WordType getType();
  std::string getText();
  std::vector< std::pair< int , long long int > > vectorization;
  Word( std::string text, WordType = INFORMATIVE );
  void printDetails( int i = 0 );
  void shortPrint();

};

#endif
