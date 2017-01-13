#include <cs50.h>
#include <string.h>
#include <stdio.h>

int converter(char let){
  int countNum;
  switch(let){
           case 'I':
               countNum=1;
           break;

           case 'V':
               countNum=5;
           break;

           case 'X':
               countNum=10;
           break;

           case 'L':
               countNum=50;
           break;

           case 'C':
               countNum=100;
           break;

           case 'D':
               countNum=500;
           break;

           case 'M':
               countNum=1000;
           break;

           default:
           countNum=0;
           break;
         }

      return countNum;
}


int main(void)
{
    
    string roman = get_string(); 

    int final=0;
    for(int i = 0; i < strlen(roman); i++){  

     int finalCount=0;
        
     int counter=  converter(roman[i]); 
    int  counterj = converter(roman[i+1]);  
        
      
        if(counterj>counter){ 
            finalCount-=counter; 
        }else{
            finalCount+=counter; 
        }
        
        final+=finalCount;
         
    }
    printf("%i", final);
   
}
