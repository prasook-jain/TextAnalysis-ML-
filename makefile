CC=g++
CFLAGS = -std=c++14 -I.
all = bagOfWord.o Word.o ContextWords.o WordVector.o

bagOfWord : $(all)
	$(CC) $(CFLAGS) -g -o bagOfWord $(all)

ContextWords.o : ContextWords.cpp ContextWords.hpp
	$(CC) $(CFLAGS) -c ContextWords.cpp ContextWords.hpp

Word.o : Word.cpp Word.hpp
	$(CC) $(CFLAGS) -c Word.cpp Word.hpp

WordVector.o : WordVector.cpp WordVector.hpp
	$(CC) $(CFLAGS) -c WordVector.cpp WordVector.hpp


clean :
	rm *.o *.gch bagOfWord
