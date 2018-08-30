#include <stdio.h>
#include <string.h>

char* gets();

char morse[27][5] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","X"};

char alfabet[27] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',' '};

char orden_codif[26][4] = {"...","..-","..X",".-.",".--",".-X",".X.",".X-",".XX","-..","-.-","-.X","--.","---","--X","-X.","-X-","-XX","X..","X.-","X.X","X-.","X--","X-X","XX.","XX-"};

char tipo_key[26]; //UFGSFUAFUTVAYUURXBJJU

char alm_str_org[1000]; //..X-.X--.X.X-.X..X.X.-.X..X.-XX-..X.XX...X..X...X-X.X--X.-X...X

char alm_str_mor[1000][5]; //ROUNDTABLECFGHIJKMPQSVWXYZ

char string_encriptado[1000];

char string_desencriptado[1000];

char string_morse[1000];

char string_desmorse[1000];

void vaciar_array(){
  memset(alm_str_org, 0, sizeof(alm_str_org));
  memset(alm_str_mor, 0, sizeof(alm_str_mor));
  memset(tipo_key, 0, sizeof(tipo_key));
  memset(string_encriptado, 0, sizeof(string_encriptado));
  memset(string_morse, 0, sizeof(string_morse));
  memset(string_desencriptado, 0, sizeof(string_desencriptado));
  memset(string_desmorse, 0, sizeof(string_desmorse));
}

char desencriptacion(char* alm_str_org, char* tipo_key){
  int i = 0, j, k, l = 0;
  while(alm_str_org[i] != '\0'){
    for(j = 0; j < 26; j++){
      if(alm_str_org[i] == tipo_key[j]){
        for(k = 0; k < 3; k++){
          string_desencriptado[l] = orden_codif[j][k];
          l++;
        }
      }
    }
    i++;
  }
  if(string_desencriptado[l-1] == 'X' && string_desencriptado[l-2] == 'X'){
    string_desencriptado[l-1] = '\0';
  }
  printf("El código morse es:\n ");
  return 0;
}

char encriptacion(char* alm_str_org, char* tipo_key){
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
            string_encriptado[m] = tipo_key[h];
            //printf("%c", tipo_key[h]);
          }
        }
      }
    }
    m++;
  }
  return 0;
}

char desmorsificar(char* alm_str_org){
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
              string_desmorse[m] = alfabet[h];
              //printf("%c", alfabet[h]);
            }
          }
        }
      }
    }
    m++;
  }
  return 0;
}

char morsificar(char* alm_str_org){
  int i = 0, j, k, l = 0;
  printf("Texto en morse:\n ");
  while(alm_str_org[i] != '\0'){
    for(j = 0;j < 27;j++){
      if(alm_str_org[i] == alfabet[j]){
        for(k = 0; k < 4 && morse[j][k] != '\0'; k++){
          string_morse[l] = morse[j][k];
          l++;
          //printf("%s", morse[j]);
        }
        if(strcmp(morse[j], "X") != 0){
            string_morse[l] = 'X';
            l++;
            //printf("X");
        }
      }
    }
    i++;
  }
  return 0;
} 

int main(){

  int opcion, opcion2;
  char aux = '\0';
  int verif = 1;
  while(verif){
    printf("\nBienvenido \nIngrese el valor de la operación: \nConvertir texto a código morse (Opción 1) \nConvertir código morse a texto (Opción 2) \nEncriptar código morse (Opción 3) \nDesencriptar un texto (Opción 4) \nSalir del programa (Opción 5)\n");
    scanf("%i", &opcion);
    scanf("%c", &aux);
    if(opcion <= 5 && opcion > 0){
      switch(opcion){
        case 1:
          printf("\nIngrese el texto a convertir a código morse:\n ");
          gets(alm_str_org);
          morsificar(alm_str_org);
          printf("%s", string_morse);         
          break;
        case 2:
          printf("\nIngrese el código morse a convertir en texto:\n ");
          gets(alm_str_org);
          desmorsificar(alm_str_org);
          printf("%s", string_desmorse);
          break;
        case 3:
          printf("\nIngrese el código morse a encriptar:\n ");
          gets(alm_str_org);
          printf("\nIngrese la clave de encriptación:\n ");
          gets(tipo_key);
          encriptacion(alm_str_org, tipo_key);
          printf("%s", string_encriptado);
          break;
        case 4:
          printf("\nIngrese el texto encriptado a convertir a código morse:\n ");
          gets(alm_str_org);
          printf("\nIngrese la clave de encriptación:\n ");
          gets(tipo_key);
          desencriptacion(alm_str_org, tipo_key);
          printf("%s", string_desencriptado);        
          break;
        case 5:
          printf("¡Hasta pronto!");
          verif=0;
          break;
      }
      if(opcion != 5){
        printf("\n¿Desea realizar más operaciones? \nSí: Marque 1 \nNo: Marque otro número\n");
        scanf("%i", &opcion2);
        if(opcion2 != 1){
          printf("¡Hasta pronto!");
          verif = 0;
        }
      }
      vaciar_array();
    }
    else{
      printf("\nOpción incorrecta, intentelo nuevamente");
    }
  }
}
