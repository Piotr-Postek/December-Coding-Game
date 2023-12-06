#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>



typedef struct {
    char word[20];
    int number;
} WordNumberPair;



int main() {
    FILE *file;
    char line[10000];

    file = fopen("/Users/piotrpostek/Desktop/December Coding Game/day 1/puzzle.txt", "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    WordNumberPair dictionary[] = {
            {"one",   1},
            {"two",   2},
            {"three", 3},
            {"four",  4},
            {"five",  5},
            {"six",   6},
            {"seven", 7},
            {"eight", 8},
            {"nine",  9},
    };

    int sum = 0;
    int linia = 1;

    while (fgets(line, sizeof(line), file) != NULL) {
    int wynik = 0;
    int first_number = 0;
    int last_number = 0;

    for (int i = 0; line[i] != '\0'; i++) {

        if(isnumber(line[i])){
            if(first_number == 0){
                first_number = line[i] - '0';
                last_number = first_number;
            } else{
                last_number = line[i] - '0';
            }
        }else{

        switch (line[i]) {
            case 'o':
                if (strncmp(line + i, dictionary[0].word, 3) == 0) {
                    if (first_number == 0) {
                        first_number = dictionary[0].number;
                        last_number = first_number;
                    } else {
                        last_number = dictionary[0].number;
                    }
                }

                break;
            case 't':
                for(int j = 0; j < 2; j++){
                    if(strncmp(line+i,dictionary[j+1].word, strlen(dictionary[j+1].word)) == 0){
                        if(first_number == 0){
                            first_number = dictionary[j+1].number;
                            last_number = first_number;
                        } else{
                            last_number = dictionary[j+1].number;
                        }
                    }
                }

                break;
            case 'f':
                for(int j = 0; j < 2; j++){
                    if(strncmp(line+i,dictionary[j+3].word, strlen(dictionary[j+3].word)) == 0){
                        if(first_number == 0){
                            first_number = dictionary[j+3].number;
                            last_number = first_number;
                        } else{
                            last_number = dictionary[j+3].number;
                        }
                    }
                }

                break;
            case 's':
                for(int j = 0; j < 2; j++){
                    if(strncmp(line+i,dictionary[j+5].word, strlen(dictionary[j+5].word)) == 0){
                        if(first_number == 0){
                            first_number = dictionary[j+5].number;
                            last_number = first_number;
                        } else{
                            last_number = dictionary[j+5].number;
                        }
                    }
                }

                break;
            case 'e':
                if (strncmp(line+i,dictionary[7].word, strlen(dictionary[7].word)) == 0){
                    if(first_number == 0){
                        first_number = dictionary[7].number;
                        last_number = first_number;
                    } else{
                        last_number = dictionary[7].number;
                    }
                }

                break;
            case 'n':
                if (strncmp(line+i,dictionary[8].word, strlen(dictionary[8].word)) == 0){
                    if(first_number == 0){
                        first_number = dictionary[8].number;
                        last_number = first_number;
                    } else{
                        last_number = dictionary[8].number;
                    }
                }

                break;
        default:
            break;
        }
        }
}

        wynik = (first_number * 10) + last_number;
        printf("Wynik dla linii %d: %d\n",linia, wynik);
        sum+=wynik;

        linia++;
    }
    printf("Suma: %d",sum);


    fclose(file);

    return 0;
}
