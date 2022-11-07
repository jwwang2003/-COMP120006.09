#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

int main(void) {
    srand(time(NULL)); 

    char words[][50] = {
        "abide",
        "extort",
        "hammer",
        "end",
        "trance",
        "cultural",
        "intermediate",
        "consumer",
        "conflict",
        "take",
        "goat",
        "program"
    };

    int size = sizeof(words)/sizeof(words[0]);

    do {
        int counter = 0;
        int wrongs = 0;
        char word[50];
        strcpy(word, words[rand()%size]);
        int wordlen = strlen(word);
        int track[50] = {0};

        while(counter < wordlen) {
            printf("(Guess) Enter a letter in word ");
            for(int i = 0; i < wordlen; ++i) {
                if(track[i]) printf("%c", word[i]);
                else printf("*");
            }
            printf(" >");

            char guess;
            scanf("%c\n", &guess);

            int flag = 0;
            for(int i = 0; i < wordlen; ++i) {
                if(word[i] == guess && track[i] == 0) {
                    track[i] = 1;
                    flag = 1;
                    ++counter;
                } else if(word[i] == guess && track[i] == 1) {
                    printf("%c is already in the word\n", guess);
                    flag = 1;
                }
            }

            if(flag == 0) {
                printf("%c is not the word\n", guess);
                ++wrongs;
            }
        }
        

        printf("The word is %s . You missed %d time\n", word, wrongs);
        printf("Do you want to guess another word? Enter y or n > ");
    } while(getchar() != 'n');

    return 0;
}