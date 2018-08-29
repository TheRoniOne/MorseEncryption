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

char alm_str_org[100] = "...XX---XX...X";

char alm_str_mor[100];


int main() {
  int p=0;
  int i = 0;
  int j, k=0;
  int cont;

  while(alm_str_org[p] != '\0'){
    // Si a lo que esta apuntando es distinto de X almacena el valor en un array de codigo morse
    if (alm_str_org[p] != *"X")
    {
      alm_str_mor[i] = alm_str_org[p];
      i++;
      cont++;
    }
    else
    {
      // Si encuentra una X ahi acaba la letra y lo almacenado en el array de morse se procesa y elimina
      j=0;
      while (strcmp(alm_str_mor,morse[j]) !=0)
      {
        //Mientras sean distintos cambia de letra
        j++;
      }
      //almacena la letra en el almacen de letras
      almPalabras[k] = *alfabet[j];
      //printf("%c", almPalabras[k]);
      k++;
      //Reiniciar alm_mor
      for (cont =0;cont<i;cont++)
      {
          alm_str_mor[cont] = '\0';
      }
      i=0;
      //Si encuentra 2 X juntas debe poner un espacio
      if (alm_str_org[p+1] == *"X")
      {
        almPalabras[k] = *" ";
        k++;
        p++;
      }
    }
    // Pasa a la siguiente posicion del array
    p++;
  }
  int f =0;
  //Imprimir resultado
  while (almPalabras[f] != '\0')
  {
    printf("%c", almPalabras[f]);
    f++;
  }
}
