#ifndef HANGMAN_FCT
#define HANGMAN_FCT

char readChar();

int win(int stars[], long wordSize);

int searchLetter(char letter, char word[], int stars[]);

#endif
