#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "02.spoiler_hangman.h"


int wordPicker(char *randWord)
{
        FILE* spoiler = NULL;
        int wordsNumber = 0;
        int randNumber = 0;
        int readChar = 0;
        int i = 0;

        spoiler = fopen("spoiler.txt", "r");

        if (spoiler == NULL)
        {
                printf("\n ! can't load any word !\n");
                return 0;
        }

        do 
        {
                readChar = fgetc(spoiler);
                if (readChar == '\n')
                        wordsNumber++;
        } while (readChar != EOF);

        randNumber = randPicker(wordsNumber);

        rewind(spoiler);
        while (randNumber > 0)
        {
                readChar = fgetc(spoiler);
                if (readChar == '\n')
                        randNumber--;
        }

        fgets(randWord, 100, spoiler);

        randWord[strlen(randWord)-1] = '\0';

        fclose(spoiler);

            return 1;
}

int randPicker(int maxNumber)
{
        srand(time(NULL));
        return (rand() % maxNumber);
}
