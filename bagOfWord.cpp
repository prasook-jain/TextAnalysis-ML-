#include <iostream>
#include <vector>
#include <string>
#include "ContextWords.hpp"
#include "WordVector.hpp"

int main(int count, char *args[]){

  std::vector< std::string > paraFileName;
  count--;

  //passed fileName using Command line
  if( count >= 1){
    for( int i=1; i <= count; i++){
      paraFileName.push_back(args[i]);
    }
  }

  //If the command line parameter are not Valid
  //Or not passed correctly
  if( paraFileName.size() == 0 ) {

    int num = 0;
    std::string fileName;
    std::cout << "Num the input Files " << std::endl;
    std::cin >> num;

    while( num-- ){

      if( !(std::cin >> fileName) ){
        std::cout << "File Does not Exist" << std::endl;
        break;
      }
      paraFileName.push_back( fileName );
      std::cout << fileName << std::endl;

    }

  }

  //Context Creation
  ContextWords test0( paraFileName );
  test0.printContextDetails(1);
  std::cout << std::endl << std::endl << "The Informative words are ------------ " << std::endl;
  test0.findInformativeWord();
  test0.printInformativeContextDetails(1);

  int windowSize;
  std::cout << std::endl << "Enter windows Size : - " << std::endl;
  std::cin >> windowSize;

  WordVector wordVec( test0 );
  wordVec.inputFill( windowSize );

  return 0;

}
