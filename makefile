CC=g++
CFLAGS = -std=c++14 -g
all = bagOfWord.o Word.o ContextWords.o WordVector.o

bagOfWord : $(all)
	$(CC) $(CFLAGS) $(all) -o bagOfWord

bagOfWord.o : bagOfWord.cpp
	$(CC) $(CFLAGS) -c bagOfWord.cpp

Word.o : Word.hpp Word.cpp
	$(CC) $(CFLAGS) -c Word.hpp Word.cpp

ContextWords.o : ContextWords.hpp ContextWords.cpp
	$(CC) $(CFLAGS) -c ContextWords.hpp ContextWords.cpp

WordVector.o : WordVector.hpp WordVector.cpp
	$(CC) $(CFLAGS) -c WordVector.hpp WordVector.cpp


clean :
	rm *.o *.gch bagOfWord
