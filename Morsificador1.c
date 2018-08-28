#include <stdio.h>
#include <string.h>
/*
 * 
 */
char morse[27][4] = {".-","-...","-.-.","-..",".","..-.","--.","....",
"..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-",
"...-",".--","-..-","-.--","--..","X"};

char alfabet[27][1] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N",
"O","P","Q","R","S","T","U","V","W","X","Y","Z"," "};

char almPalabras[1000];

char palabra[10] = ".-";

int main() {
    printf("%s\n", morse[0]);
    int i=0;
    while (strcmp(palabra,morse[i]) !=0)
    {
        i++;
    }
    
    almPalabras[0] = *alfabet[i];
    
    printf("%c\n", almPalabras[0]);
}
