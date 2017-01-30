/*
 * Parsum
 *
 * Programista
 * by Joel Enriquez
 *
 */

#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    string s = get_string();
    int n = strlen(s);
    int total = 0;
    char temp[n];

    //Remove white spaces
    for(int i=0, j=0; i<n; i++){
        if(s[i] != ' '){
            temp[j++] = s[i];
        }
        temp[j] = '\0';
    }

    //Get actual values
    int n2 = strlen(temp);
    char digits[n2];
    for(int i=0,j=0; i<n2; i++){
        if(temp[i] != '+'){
            digits[j++] = temp[i];
        }
        if((i+1 < n2 && (temp[i+1] == '+' || temp[i+1] == '-')) || (i+1 == n2)){
            digits[j] = '\0';
            j = 0;
            total += atoi(digits);
        }
    }

    printf("%i", total);
}

