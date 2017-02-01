/*
 * Title Case
 *
 * Programista
 * by Joel Enriquez
 *
 */

#include "cs50.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int main(void){
    string s = get_string();
    if(s != NULL){
        string keywords[4] = {"the", "of", "and", "but"};
        char *token;
        char title[strlen(s)];

        token = strtok(s, " ");
        bool start = true;
        bool end = false;
        while(token != NULL){
            //make sure that word is lowercase
            char word[strlen(token)];
            strcpy(word, token);

            token = strtok(NULL, " ");
            end = (token == NULL);

            //skip special keywords
            bool skip_upper = false;
            for(int i=0; i<4; i++){
                if(strcmp(word, keywords[i]) == 0){
                    skip_upper = (start || end) ? false : true;
                    break;
                }
            }

            if(!skip_upper){
                word[0] = toupper(word[0]);
            }else{
                word[0] = tolower(word[0]);
            }

            if(!start){
                strcat(title, " ");
            }else{
                strcpy(title, ""); //just to make sure initial string is not garbage
            }

            strcat(title, word);
            start = false;
        }
        printf("%s\n", title);
    }
}
