#include "ContextWords.hpp"
#include <iostream>
#include <sstream>

void ContextWords :: addContext(  std::string fileName ){
  //std::cout << fileName << std::endl;
  this->files.push_back(fileName);
  this->numOfFiles = this->numOfFiles + 1;
}


ContextWords :: ContextWords( std::vector< std::string > &paraFileName ){

  for( auto fileName : paraFileName ){

    std::ifstream file(fileName);
    if( file.fail() ){
      std::cout << fileName << " file not exist... :( " << std::endl;
      continue;
    }
    this->addContext( fileName );
    this->scanFile(file);
    //std::cout << "file scaned after each scanfile call" << std::endl;

  }

}


void ContextWords :: scanFile( std::ifstream & file ){

  //std::cout << "New File :- " << std::endl << std::endl;
  std::string parsedString = "";
  std::string text;

  while( file >> text ){
    //std::cout << text << std::endl;
    parsedString = parsedString + ' ' + parseText( text );
  }

  std::stringstream *s = new std::stringstream(parsedString);
  while (*s >> text)
    updateContext(text);

}

/*Print the vectorized data
*/
void ContextWords:: printContextDetails( int option = 0 ){
  for( auto elem : dictionary ){
    if( option == 1 )elem->printDetails();
    else elem->shortPrint();
    std::cout << std::endl;
  }
}

/*Find the text in ContextWords and return the position if present
*/
class Word * ContextWords :: findPos( std::string & text ){
  for( auto word : this->dictionary ){
    if( word->getText() == text ) return word;
  }
  return NULL;
}

/*
These function basically update the ContextWords
  * Take each parsed word as input
  * Check if alredy present in the ContextWords,
    If present then increment it
    else create new pair.
  * In both cases it would be vecotrized and tracking count for each file passed
    in context.
*/
void ContextWords :: updateContext( std::string word ){


  class Word *pos = findPos(word);

  if( pos == NULL) {
    //std::cout << "New Word : " << word << std::endl;
    bool isInformative = true;
    //Find if word alredy exist in context
    for( int i=0; i<this->ignoreWord.size(); i++ ){
      if( word == this->ignoreWord[i] ){
        isInformative = false;
      }
    }
    class Word *temp = new Word( word, isInformative?INFORMATIVE:IGNORABLE );
    temp->vectorization.push_back( std::make_pair(this->numOfFiles, 1LL) );

    this->dictionary.push_back(temp);
  }
  else{
    //std::cout << "Existing Word : " << word << std::endl;
    if( pos->vectorization.back().first == this->numOfFiles ){
      //std::cout << "find in current file twice" << std::endl;
      pos->vectorization.back().second++;
    }
    else{
      //std::cout << "find in current file first time" << std::endl;
      pos->vectorization.push_back( std::make_pair(this->numOfFiles, 1LL) );
    }
  }
}


/*Parse The Coming from the file into simple Lower case word form
*/
std::string ContextWords:: parseText( std::string &text ){

  std::string parsed = "";
  std::string temp = "";

  int i=0;
  while( i < text.size() ){
    while( i < text.size() &&
      ((text[i] <= '9' && text[i] >= '0')
      || (text[i] >= 'a' && text[i] <= 'z')
      || (text[i] >= 'A' && text[i] <= 'Z'))
    ){
      temp = temp + (char)tolower(text[i]);
      i++;
    }
    if( temp != "" ){
      parsed = parsed + " " + temp;
      temp = "";
    }
    i++;
  }

  //std::cout << std::endl << text << " -> " << parsed << std::endl;
  return parsed;
}

/* The stopwards which has to be ignored is define in the static string array
*/
const std::vector< std::string > ContextWords::ignoreWord = { "i","me","my","myself","we","our","ours","ourselves","you","your","yours","yourself","yourselves","he","him","his","himself","she","her","hers","herself","it","its","itself","they","them","their","theirs","themselves","what","which","who","whom","this","that","these","those","am","is","are","was","were","be","been","being","have","has","had","having","do","does","did","doing","a","an","the","and","but","if","or","because","as","until","while","of","at","by","for","with","about","against","between","into","through","during","before","after","above","below","to","from","up","down","in","out","on","off","over","under","again","further","then","once","here","there","when","where","why","how","all","any","both","each","few","more","most","other","some","such","no","nor","not","only","own","same","so","than","too","very","s","t","can","will","just","don","should","now"};


/*Print the vectorized data for only infomative words
*/
void ContextWords:: printInformativeContextDetails( int option = 0 ){
  for( auto elem : informativeDict ){
    if( option == 1 )elem->printDetails();
    else elem->shortPrint();
    std::cout << std::endl;
  }
}

void ContextWords:: findInformativeWord(){
  for( auto elem : this->dictionary )
    if(elem->getType() == INFORMATIVE)
      this->informativeDict.push_back(elem);

  //the sort bad functionality as it will remove the context information
  //sort( informativeDict.begin(), informativeDict.end(), cmpare );

}


/*Return an copy vector of informative word class pointer to use publicly
*/
std::vector< class Word * > ContextWords:: getInformativeWords(){

  std::vector< class Word * > temp;

  for( auto elem : this->informativeDict )
    temp.push_back(elem);

  return temp;
}


/*ContextWords :: ContextWords( std::initializer_list< std::string > fileList ){

for( auto fileName : fileList )
this->addContext(fileName);

}*/

//the sort bad functionality as it will remove the context information
/*
auto cmpare = [](const class Word *left,const class Word *right){
  int lCount =0,rCount = 0;
  for( auto elem : left->vectorization)
  lCount += elem.second;
  for( auto elem : right->vectorization)
  rCount += elem.second;
  return lCount > rCount;
};*/
