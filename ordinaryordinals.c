/*
 * Ordinary Ordinals
 *
 * Programista
 * by Joel Enriquez
 *
 */

#include <cs50.h>
#include <string.h>
#include <stdio.h>

string get_suffix(int value);

int main(void)
{
    string s = get_string();
    if(s != NULL && strlen(s) > 0){
        char *token = strtok(s, " ");
        int count = 0;
        bool found = false;
        while(token != NULL){
            count++;
            if(strcmp(token, "cat") == 0){
                found = true;
                break;
            }
            token = strtok(NULL, " ");
        }
        if(count > 0 && found) {
            printf("The cat is the %i%s item in the box\n", count, get_suffix(count));
        }else if(count > 0){
            printf("No cat yet\n");
        }else{
            printf("There is no box\n");
        }
    }else{
        printf("There is no box\n");
    }
    return 0;
}

string get_suffix(int value){
    int last2_digits = value % 100; //Last 2-digits only
    int last_digit = last2_digits % 10; //Last digit
    last_digit = ((last2_digits - last_digit) == 10) ? 0 : last_digit;
    switch(last_digit){
        case 1:
            return "st";
        case 2:
            return "nd";
        case 3:
            return "rd";
        default:
            return "th";
    }
}
