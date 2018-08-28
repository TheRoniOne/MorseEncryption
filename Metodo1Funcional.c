#include <stdio.h>
#include <string.h>

char* gets();

char morse[27][5] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","X"};

char alfabet[27] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',' '};

char orden_codif[26][3] = {"...","..-","..X",".-.",".--",".-X",".X.",".X-",".XX","-..","-.-","-.X","--.","---","--X","-X.","-X-","-XX","X..","X.-","X.X","X-.","X--","X-X","XX.","XX-"};

char tipo_key[26];

char alm_str_org[1000];

char alm_str_mor[1000][4];

void desmorsificar(char* alm_str_org){
  //int i = 0;
  while(alm_str_org != '\0'){
    alm_str_org++;
  }
}

void morsificar(char* alm_str_org){
  int i = 0, j, k = 0, l = 0,n = 0;
  printf("Texto en morse:\n ");
  while(alm_str_org[i] != '\0'){
    for(j = 0;j < 27;j++){
      if(alm_str_org[i] == alfabet[j]){
        /*while(morse[j][n] != '\0'){
          alm_str_mor[l][n] = morse[j][n];
          n++;
        }
        n = 0;
        printf("%s\n", alm_str_mor[l]);
        l = i+1;
        alm_str_mor[l][0] = *"X";
        alm_str_mor[l][1] = '\0';
        printf("%s\n", alm_str_mor[l]);
        l++;*/
        printf("%s", morse[j]);
        if(strcmp(morse[j], "X") != 0){
          printf("X");
        }
      }
    }
    i++;
  }
} 

int main(){

    printf("Ingrese el texto a convertir a código morse: ");
    //scanf("%s", alm_str_org);
    gets(alm_str_org);
    morsificar(alm_str_org);
    /*printf("Ingrese el código morse a convertir en texto: ");
    scanf("%s", alm_str_org);
    desmorsificar(alm_str_org);*/

    /*char *a = morse[25];
    char *b = alfabet[25];
    printf("%s %s", a, b);*/
}
