#include <stdio.h>
#include <string.h>

char morse[27][4] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","X"};

char alfabet[27][1] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"," "};

char orden_codif[26][3] = {"...","..-","..X",".-.",".--",".-X",".X.",".X-",".XX","-..","-.-","-.X","--.","---","--X","-X.","-X-","-XX","X..","X.-","X.X","X-.","X--","X-X","XX.","XX-"};

char tipo_key[26];

char alm_str_org[1000];

char alm_str_mor[1000][4];

void morsificar(){
  printf("%s\n", orden_codif[25]);
  int i = 0, j, k = 0, l=0;
  char a,b;
  printf("Ingrese el texto a convertir a código morse: ");
  scanf("%s", alm_str_org);
  while(alm_str_org[i] != '\0'){
    for(j = 0;j < 27;j++){
      if(alm_str_org[i] == *alfabet[j]){
        *alm_str_mor[k] = *morse[j];
        printf("%s\n", alm_str_mor[k]);
        i++;
        k++;
        *alm_str_mor[k] = *"X";
        printf("%s\n", alm_str_mor[k]);
        k++;
        
      }
    }
  }
  printf("Texto en morse:\n ");
  while(*alm_str_mor[l] != '\0'){
    printf("%s", alm_str_mor[l]);
    l++;
  }
} 

int main(){

    morsificar();
    /*char *a = morse[25];
    char *b = alfabet[25];
    printf("%s %s", a, b);*/
}
