#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char *string_reader(){
int index = 0;
    char c;
    char * priklad = malloc(sizeof(char) * 2);
    while((c = getchar()) != '\n'){
        priklad = realloc(priklad, (index + 2) * sizeof(char));
        priklad[index] = c;
        index++;
    }
    priklad[index] = '\0';
    return priklad;
}
int vypocet(char* znaky, int* cisla, int delka){
    int vysledek = cisla[0];
    for (int i = 0; i < delka; ++i) {

        if(znaky[i]=='+'){
            vysledek += cisla[i+1];
        }
       else if(znaky[i]=='-'){
            vysledek -= cisla[i+1];
        }

    }
    return vysledek;
}

int main() {
    printf("Hello, World!\n");

    char *equation = string_reader();

    int cisla[100];
    char znaky[100];
    int index_cisla = 0;
    int index_znaky = 0;
    char current = 'a';
    int current_cislo = 0;
    int index = 0;
    while(current != '\0'){
        current = equation[index];

        if(isdigit(current)){
            current_cislo = current_cislo * 10 + (current - '0');
        }
        else if(current == '+' || current == '-'){
            znaky[index_znaky] = current;
            index_znaky++;
            cisla[index_cisla] = current_cislo;
            index_cisla++;
            current_cislo = 0;
        }
        index++;
    }
    cisla[index_cisla] = current_cislo;


    printf("Cisla:\n");
    for (int i = 0; i <= index_cisla; ++i) {
        printf("%i ",cisla[i]);
    }

    printf("\nZnaky:\n");
    for (int i = 0; i<index_znaky; ++i) {
        printf("%c ",znaky[i]);
    }

    int vysledek = vypocet(znaky,cisla,index_znaky);


    printf("\n%i", vysledek);
    return 0;
}
