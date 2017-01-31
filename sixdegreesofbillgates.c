/*
 * Six Degrees of Bill Gates
 *
 * Programista
 * by Joel Enriquez
 *
 */

#include <cs50.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
    int n = get_int();
    string s[n];

    char matrix[n][n];
    for(int i=0; i<n; i++){
        s[i] = get_string();
        for(int j=0, k=0, nn=strlen(s[i]); j<nn; j++){
            if(s[i][j] == '\0'){
                break;
            }else if(s[i][j] == ' '){
                continue;
            }else{
                matrix[i][k] = s[i][j];
                k++;
            }
        }
    }

    int x = get_int();
    int y = get_int();
    int connection_step = 0;
    bool found = false;
    for(int i=x, j=y; j<n; j++){
        connection_step++;
        if(matrix[i][j] == '1'){
            found = true;
            break;
        }
    }

    if(!found){
        printf("%i", -1);
    }else{
        printf("%i", connection_step);
    }

    return 0;
}
