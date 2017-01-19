/*
* Be Our Guest
*
* Programista
* by Joel Enriquez
*
*/

#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int main(void) {
    string s = get_string();
    if(s != NULL){
        int floor = atoi(strtok(s, " "));
        int rooms = atoi(strtok(NULL, " "));
        bool group_checkin = false;
        int avail_max = 0;
        for(int i=0; i<floor; i++){
            string room_info = get_string();
            int avail_count = 0;
            for( int j=0, n = strlen(room_info); j<n && j<rooms; j++){
                if(room_info[j] == '0'){
                    avail_count++;
                }else{
                    if( avail_count > avail_max){
                        avail_max = avail_count;
                    }
                    avail_count = 0;
                }
            }
            if( avail_count > avail_max){
                avail_max = avail_count;
            }
        }
        string group_count = get_string();
        printf("%i\n", atoi(group_count) <= avail_max ? 1 : 0);
    }
}

