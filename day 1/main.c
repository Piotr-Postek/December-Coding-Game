/*
    In this code you can find first and last number in string
    eg. kjhsdf8sd8cs9sd -> 89
        kjsd8jdk        -> 88
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    FILE *plik;
    char linia[1000];
    int liczba, pierwszaLiczba, ostatniaLiczba;
    int suma = 0;
    int wynik = 0;

    plik = fopen("/Users/piotrpostek/Desktop/December Coding Game/day 1/puzzle.txt", "r");

    if (plik == NULL) {
        perror("Błąd podczas otwierania pliku");
        return 1;
    }

    while (fgets(linia, sizeof(linia), plik) != NULL) {
        pierwszaLiczba = ostatniaLiczba = 0;

        for (int i = 0; linia[i] != '\0'; i++) {
            if (isdigit(linia[i])) {

                liczba = linia[i] - '0';

                if (pierwszaLiczba == 0) {
                    pierwszaLiczba = liczba;
                }

                ostatniaLiczba = liczba;
            }
        }

        wynik = (pierwszaLiczba * 10) + ostatniaLiczba;
        printf("Wynik dla linii: %d\n", wynik);
        suma+=wynik;
    }

    printf("wynik koncowy: %d",suma);

    fclose(plik);

    return 0;
}
