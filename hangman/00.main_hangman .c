#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "00.main_hangman.h"
#include "01.fct_hangman.h"
#include "02.spoiler_hangman.h"

int main(int argc, char *argv[])
{
        char letter = 0;
        char word[100] = {0};
        int *stars = NULL;
        long counter = 10;
        long wordSize = 0;
        long i = 0;

        printf("====================\n");
        printf("Hangman --- Welcome!\n");
        printf("====================\n");
        printf("      _______\n");
        printf("      |/    |\n");
        printf("      |     o\n");
        printf("      |    -|-\n");
        printf("      |    | | \n");
        printf("      |_______\n\n");
        printf("====================\n");
        printf("    ... or not\n");
        printf("====================\n");

//        printf("%d", wordPicker(word));

        if (!wordPicker(word))
                exit(0);
        
        wordSize = strlen(word);
//        printf("%d\n", wordSize);
        
        stars = malloc(wordSize * sizeof(int));

        if (stars == NULL)
                exit(0); 
        
        for (i = 0; i <  wordSize; i++)
        {
                stars[i] = 0;
        }

        

        while (counter > 0 && !win(stars, wordSize))
        {
                switch(counter)
                {
                case 10:        
                printf("\n %d shot left",counter);
                printf("\n A word is wanted...\n");
                break;
                case 9:
                hangman01();
                printf("\n %d shot left",counter);
                printf("\n A word is wanted...\n");
                break;
                case 8:
                hangman02();
                printf("\n %d shot left",counter);
                printf("\n A word is wanted...\n");
                break;
                case 7:
                hangman03();
                printf("\n %d shot left",counter);
                printf("\n A word is wanted...\n");
                break;
                case 6:
                hangman04();
                printf("\n %d shot left",counter);
                printf("\n A word is wanted...\n");
                break;
                case 5:
                hangman05();
                printf("\n %d shot left",counter);
                printf("\n A word is wanted...\n");
                break;
                case 4:
                hangman06();
                printf("\n %d shot left",counter);
                printf("\n A word is wanted...\n");
                break;
                case 3:
                hangman07();
                printf("\n %d shot left",counter);
                printf("\n A word is wanted...\n");
                break;
                case 2:
                hangman08();
                printf("\n %d shot left",counter);
                printf("\n A word is wanted...\n");
                break;
                case 1:
                hangman09();
                printf("\n %d shot left",counter);
                printf("\n A word is wanted...\n");
                break;
                }

                for (i = 0 ; i < wordSize ; i++)
                    {
                            if (stars[i])
                                printf("%c", word[i]);
                            else
                                printf("*");
                    }

                printf("\nplease, give a shot\n");
                letter = readChar();

                if (!searchLetter(letter, word, stars))
                {
                        counter--;
                }
        }
        if (win(stars, wordSize))
                printf("\n you win... da word is : %s \n", word);
        else
                hangman10();
                printf("\n you loser, da word is : %s \n", word); 
        
        free(stars);

        return 0;
}

char readChar()
{
        char character = 0;

        character = getchar();
        character = toupper(character);

        while (getchar() != '\n');

        return character;
}


int win(int stars[], long wordSize)
{
        int i = 0;
        int victory = 1;

        for (i = 0; i < wordSize; i++)
        {
                if (stars[i] == 0)
                        victory = 0;
        }

        return victory;
}

int searchLetter(char letter, char word[], int stars[])
{
        int i = 0;
        int goodShot = 0;

        for (i = 0; word[i] != '\0' ; i++)
        {
                if (letter == word[i])
                {
                        goodShot = 1;
                        stars[i] = 1;
                }
        }

        return goodShot;
}
