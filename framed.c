/*
 * Framed
 *
 * Programista
 * by Joel Enriquez
 *
 */

#include <cs50.h>
#include <string.h>
#include <stdio.h>

int get_max_word(string s);
void print_frame(string s, int max);

int main(void)
{
    string s = get_string();
    if( s != NULL ){
        int max_word = get_max_word(s);
        if(max_word > 0){
            print_frame(s, max_word + 4);
        }
    }
}

int get_max_word(string s){
    int max_word = 0;
    char temp[strlen(s)];
    strcpy(temp, s); //to be safe not destroying our string
    char *token = strtok(temp, " ");
    while( token != NULL ) {
        int n = strlen(token);
        if(n > max_word){
            max_word = n;
        }
        token = strtok(NULL, " ");
    }
    return max_word;
}

void print_frame(string s, int max){
    for(int i=0; i<max; i++){
        printf("#");
    }

    char *token = strtok(s, " ");
    while( token != NULL ) {
        printf("\n# %-*s#", max-3, token);
        token = strtok(NULL, " ");
    }

    printf("\n");
    for(int i=0; i<max; i++){
        printf("#");
    }

    printf("\n");
}
