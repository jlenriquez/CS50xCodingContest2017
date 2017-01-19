/*
 * Cat Eats Fish
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
    int fish = get_int();
    int days = get_int();
    int run_out = -1;
    for(int i=0; i<days; i++){
        fish -= get_int();
        if(fish <= 0 && run_out < 0){
            run_out = i;
        }
    }

    if(days > 0){
        if(run_out > -1){
            printf("%i\n", run_out);
        }else{
            printf("Happy Cat!\n");
        }
    }

    return 0;
}
