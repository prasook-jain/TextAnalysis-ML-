#ifndef WORD_INCLUDE
#define WORD_INCLUDE

#include <vector>
#include <string>
#include <utility>
enum WordType { IGNORABLE, INFORMATIVE };

class Word{

private:

  std::string description;   // brief meaning of the word or text
  WordType type;             // Type of the English word like Object, Subject,
                             // Verb, adjective, adverb...
  const std::string text;    // Text of the Word
  const long long int uniId; //Uniqe Id to each word scaned
  long long int count = 0;
  // Assign Unique Id each time
  static long long int idGenerator(){
    static long long int lastId = 0;
    return lastId++;
  }

public:

  std::vector< std::pair< int , long long int > > vectorization;
  Word( std::string text, WordType = INFORMATIVE );
  int findVectorPos( int value );
  void printDetails( int i = 0 );
  void shortPrint();
  WordType getType();
  std::string getText() const;
  int getId();
};

#endif
