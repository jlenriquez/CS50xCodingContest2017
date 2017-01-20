/*
 * Feeding Garfield
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
    int l = get_int(); //initial hunger level
    int n = get_int(); //number of food items bought
    int s[n];
    int h[n];
    for(int i=0; i<n; i++){
        string food_item = get_string();
        char *token = strtok(food_item, ", ");
        int j = 0;
        while( token != NULL ) {
            if(j == 0){
                s[i] = atoi(token); //food
            }else{
                h[i] = atoi(token); //happiness
            }
            token = strtok(NULL, ", ");
            j++;
        }
    }

    //TODO: offset of overfed or underfed condition (inaccurate)
    int level = 0;
    bool is_fed_well = false;

    int matrix[n][l];
    for (int i = 0; i < n; i++)
    {
        level += s[i];
        for (int j = 0; j < l; j++)
        {
            if (i == 0)
            {
                matrix[i][j] = s[i] > (j + 1) ? 0 : h[i];
            }
            else if (s[i] == (j + 1))
            {
                matrix[i][j] = h[i] > matrix[i - 1][j] ? h[i] : matrix[i - 1][j];
            }
            else if (s[i] < (j + 1))
            {
                matrix[i][j] = matrix[i - 1][j] >  h[i] + matrix[i - 1][((j + 1) - s[i]) - 1] ?
                    matrix[i - 1][j] : h[i] + matrix[i - 1][((j + 1) - s[i]) - 1];
            }
            else if (s[i] > (j + 1))
            {
                matrix[i][j] = matrix[i - 1][j];
            }
        }
    }

    if( level < l)
    {
        //underfed
         matrix[n-1][l-1] += (l-level) * -10;
    }
    else
    {
        //overfed
        //matrix[n-1][l-1] += (level-l) * -20;
    }

    printf("%i\n", matrix[n-1][l-1]);
}
