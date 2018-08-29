#include <stdio.h>
#include <string.h>

char* gets();

char morse[27][5] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","X"};

char alfabet[27] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',' '};

char orden_codif[26][4] = {"...","..-","..X",".-.",".--",".-X",".X.",".X-",".XX","-..","-.-","-.X","--.","---","--X","-X.","-X-","-XX","X..","X.-","X.X","X-.","X--","X-X","XX.","XX-"};

char tipo_key[26];

char alm_str_org[1000]; //..X-.X--.X.X-.X..X.X.-.X..X.-XX-..X.XX...X..X...X-X.X--X.-X...X

char alm_str_mor[1000][5]; //ROUNDTABLECFGHIJKMPQSVWXYZ

void encriptacion(char* alm_str_org, char* tipo_key){
  int h, i = 0, j, k = 0, m = 0;
  while(alm_str_org[i] != '\0'){
    for(j = 0; j < 3; j++){
      alm_str_mor[k][j] = alm_str_org[i];
      i++;
    }
    if(alm_str_mor[k][1] == '\0'){
      alm_str_mor[k][1] = 'X';
    }
    if(alm_str_mor[k][2] == '\0'){
      alm_str_mor[k][2] = 'X';
    }
    k++;
  }
  printf("El texto encriptado es:\n ");
  while(alm_str_mor[m][0] != '\0'){
    for(h = 0; h < 27; h++){
      if(alm_str_mor[m][0] == orden_codif[h][0]){
        if(alm_str_mor[m][1] == orden_codif[h][1]){
          if(alm_str_mor[m][2] == orden_codif[h][2]){
            printf("%c", tipo_key[h]);
          }
        }
      }
    }
    m++;
  }
}

void desmorsificar(char* alm_str_org){
  int h, i = 0, k = 0, l, n, m = 0;
  while(alm_str_org[i] != '\0'){
    int j = 0;
    n = i;
    while(alm_str_org[i] != 'X' && alm_str_org[i] != '\0'){
      i++;
      j++;
    }
    i++;
    if(j == 0){
      alm_str_mor[k][0] = 'X';
    }
    else{
      for(l = 0; l < j; l++){
        alm_str_mor[k][l] = alm_str_org[n];
        n++;
      }
    }
    k++;
  }
  printf("El texto es:\n ");
  while(alm_str_mor[m][0] != '\0'){
    for(h = 0; h < 27; h++){
      if(alm_str_mor[m][0] == morse[h][0]){
        if(alm_str_mor[m][1] == morse[h][1]){
          if(alm_str_mor[m][2] == morse[h][2]){
            if(alm_str_mor[m][3] == morse[h][3]){
              printf("%c", alfabet[h]);
            }
          }
        }
      }
    }
    m++;
  }
}

void morsificar(char* alm_str_org){
  int i = 0, j, k = 0, l = 0,n = 0;
  printf("Texto en morse:\n ");
  while(alm_str_org[i] != '\0'){
    for(j = 0;j < 27;j++){
      if(alm_str_org[i] == alfabet[j]){
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

    /*printf("\nIngrese el texto a convertir a código morse: ");
    gets(alm_str_org);
    morsificar(alm_str_org);
    printf("\nIngrese el código morse a convertir en texto: ");
    gets(alm_str_org);
    desmorsificar(alm_str_org);*/
    printf("\nIngrese el código morse a encriptar: ");
    gets(alm_str_org);
    printf("\nIngrese la clave de encriptación: ");
    gets(tipo_key);
    encriptacion(alm_str_org, tipo_key);
}
