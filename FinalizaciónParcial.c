#include <stdio.h>
#include <string.h>

/* Valores para prueba
Texto: INGENIERIA DE SISTEMAS
Morse: ..X-.X--.X.X-.X..X.X.-.X..X.-XX-..X.XX...X..X...X-X.X--X.-X...X
Encriptado: UFGSFUAFUTVAYUURXBJJU
Clave:  ROUNDTABLECFGHIJKMPQSVWXYZ
*/

char* gets(); //Declaración para poder usar la función gets

char morse[27][5] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","X"};

char alfabet[27] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',' '};

char orden_codif[26][4] = {"...","..-","..X",".-.",".--",".-X",".X.",".X-",".XX","-..","-.-","-.X","--.","---","--X","-X.","-X-","-XX","X..","X.-","X.X","X-.","X--","X-X","XX.","XX-"};  //Almacena el orden de codificación, sincroniza sus posiciones con los valores capturados en el array tipo_key

char tipo_key[26]; //Almacena la clave de encriptación

char alm_str_org[1000]; //Almacena los strings ingresados por consola, utilizado por todas las funciones 

char alm_str_mor[1000][5]; //

char string_encriptado[1000]; //Almacena los resultados de la encriptación

char string_desencriptado[1000];  //Almacena los resultados de la desencriptación

char string_morse[1000];  //Almacena los resultados de la conversión a morse

char string_desmorse[1000]; //Almacena los resultados de la conversión a texto

void vaciar_array(){  //Limpia los espacios de memoria de las listas que almacenan datos ingresados para que no haya conflicto si se sigue ejecutando el programa constantemente
  memset(alm_str_org, 0, sizeof(alm_str_org));
  memset(alm_str_mor, 0, sizeof(alm_str_mor));
  memset(tipo_key, 0, sizeof(tipo_key));
  memset(string_encriptado, 0, sizeof(string_encriptado));
  memset(string_morse, 0, sizeof(string_morse));
  memset(string_desencriptado, 0, sizeof(string_desencriptado));
  memset(string_desmorse, 0, sizeof(string_desmorse));
}

char desencriptacion(char* alm_str_org, char* tipo_key){  //Función que recibe un array de texto encriptado y lo convierte en código morse
  int i = 0, j, k, l = 0; //Variables
  while(alm_str_org[i] != '\0'){  //Ejecuta el bucle hasta que encuentre una posición vacía en el array  
    for(j = 0; j < 26; j++){  //Recorrido para hacer la comparación del elemento en la posición "i" del array que captura datos del usuario con el array que contiene las letras de la clave de encriptación
      if(alm_str_org[i] == tipo_key[j]){  //Si los valores concuerdan, se conoce ahora la posición de la letra codificada en morse a utilizar
        for(k = 0; k < 3; k++){ //Se hace el recorrido del tamaño de la palabra en morse para agregarla al array del resultado
          string_desencriptado[l] = orden_codif[j][k];
          l++;
        }
      }
    }
    i++;
  }
  if(string_desencriptado[l-1] == 'X' && string_desencriptado[l-2] == 'X'){ //En caso se haya rellenado con "X" al final del código morse para que cumpla con el proceso de encriptación, aquí se le retira
    string_desencriptado[l-1] = '\0';
  }
  printf("El código morse es:\n");
  return 0;
}

char encriptacion(char* alm_str_org, char* tipo_key){ //Por optimizar
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
  printf("El texto encriptado es:\n");
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

char desmorsificar(char* alm_str_org){  //Función que recibe un array de código morse y lo convierte a texto
  int h, i = 0, k = 0, l, n, m = 0, y, z = 1; //Variables
  printf("El texto es:\n ");
  while(alm_str_org[i] != '\0'){  //Ejecuta el bucle hasta que encuentre una posición vacía en el array
    int j = 0;  //Variable que se reinicia, cuenta el tamaño de cada palabra en morse
    y = i;
    while(alm_str_org[i] != 'X' && alm_str_org[i] != '\0'){ //Ejecuta el bucle hasta que encuentre una "X" o una posición vacía en el array
      i++; //Siguiente posición del array de datos capturados
      j++;
    }
    i++;  //Está fuera del bucle para que cuando encuentre la "X" del espacio entre palabras no se quede atrapado allí
    if(j == 0){ //Si j no avanzó, es porque se topó con una "X" del espacio entre palabras
      string_desmorse[k] = ' '; //Se añade el respectivo espacio vacío en el array de resultado
    }
    else{ //En caso si haya habido un avance, se hace un recorrido para comparar la cantidad de caracteres en morse conocidos por j con el array que almacena el código morse
      for(h = 0; h < 27; h++){
        n = y;  //Se toma el valor que i tenía antes de hacer el recorrido hasta la siguiente "X"
        for(l = 0; l < j; l++){ //Se hace la comparación de cada caracter de una letra en morse para verificar que sea la que se desea
          if(alm_str_org[n] != morse[h][l]){ //En caso un caracter no concuerde, se rompe este ciclo de comparación para ir hacia la siguiente letra en morse
            z = 0; //Actúa como boolean, le da a conocer al condicional de abajo que esta no es la letra en morse que está buscando
            break;
          }
          m = l;  //Almacena el tamaño máximo de cada letra en morse
          n++;
        }
        if(z && morse[h][m+1] == '\0'){ //Se pregunta si los valores comparados han sido iguales y se ha hecho la evaluación hasta el tamaño máximo de la palabra en morse (porque puede pasar esto: Valor ingresado = ... , Valor comparado = .... --> cumplió con los tres primeros caracteres pero no analizó el último y por ello guarda una letra errónea en el array de respuesta) 
          string_desmorse[k] = alfabet[h]; //Se guarda la letra en el array de respuesta
          break;
        }
        z = 1;  //Reinicia el boolean
      }
    }
    k++;  //Avanza la posición en el array del resultado para almacenar las letras
  }
  return 0;
}

char morsificar(char* alm_str_org){ //Función que recibe un array de texto y lo convierte a código morse
  int i = 0, j, k, l = 0; //Contadores
  printf("Texto en morse:\n");
  while(alm_str_org[i] != '\0'){  //Ejecuta el bucle hasta que encuentre una posición vacía en el array
    for(j = 0;j < 27;j++){  //Recorrido para hacer la comparación del elemento en la posición "i" del array que captura datos del usuario con el array que contiene las letras del alfabeto
      if(alm_str_org[i] == alfabet[j]){ //Si los valores concuerdan, se conoce ahora la posición de la letra en morse a utilizar
        for(k = 0; k < 4 && morse[j][k] != '\0'; k++){  //Se hace el recorrido del tamaño de la palabra en morse para agregarla al array del resultado
          string_morse[l] = morse[j][k];
          l++;
        }
        if(strcmp(morse[j], "X") != 0){ //Agrega un "X" al final de cada letra de morse, hace la comparación para que no agregue una "X" en caso de que ya haya una porque representa un espacio entre palabras
            string_morse[l] = 'X';
            l++;
        }
      }
    }
    i++;
  }
  return 0;
} 

int main(){
  int opcion, opcion2;
  char aux = '\0';  //Variable auxiliar, como su nombre lo dice
  int verif = 1;  //Variable que funciona como boolean para que se ejecute constantemente el programa hasta que cambie su valor
  while(verif){ //Bucle que se ejecuta constantemente hasta que cambie su valor
    printf("\nBienvenido \nIngrese el valor de la operación: \nConvertir texto a código morse (Opción 1) \nConvertir código morse a texto (Opción 2) \nEncriptar código morse (Opción 3) \nDesencriptar un texto (Opción 4) \nSalir del programa (Opción 5)\n");
    scanf("%i", &opcion); //Captura el valor ingresado para que se ejecute la función solicitada
    scanf("%c", &aux); //Si no está esta línea no se ejecuta correctamente la captura de datos por alguna razón
    if(opcion <= 5 && opcion > 0){  //Se ejecuta si se ingresa alguno de los valores mostrados en consola
      switch(opcion){
        case 1: //Realiza la operación de conversión de texto a código morse
          printf("\nIngrese el texto a convertir a código morse:\n");
          gets(alm_str_org);  //Captura el texto ingresado por consola
          morsificar(alm_str_org);  //Ejecuta la función de conversión
          printf("%s", string_morse); //Imprime el resultado         
          break;
        case 2: //Realiza la operación de conversión de código morse a texto
          printf("\nIngrese el código morse a convertir en texto:\n");
          gets(alm_str_org);  //Captura el código ingresado por consola
          desmorsificar(alm_str_org); //Ejecuta la función de conversión
          printf("%s", string_desmorse);  //Imprime el resultado
          break;
        case 3: //Realiza la operación de encriptación del código morse
          printf("\nIngrese el código morse a encriptar:\n");
          gets(alm_str_org);  //Captura el código ingresado por consola
          printf("\nIngrese la clave de encriptación:\n");
          gets(tipo_key); //Captura la clave de encriptación ingresada por consola
          encriptacion(alm_str_org, tipo_key);  //Ejecuta la función de conversión
          printf("%s", string_encriptado);  //Imprime el resultado
          break;
        case 4: //Realiza la operación de desencriptación del código a morse
          printf("\nIngrese el texto encriptado a convertir a código morse:\n");
          gets(alm_str_org);  //Captura de texto encriptado ingresado por consola
          printf("\nIngrese la clave de encriptación:\n");
          gets(tipo_key); //Captura la clave de encriptación ingresada por consola
          desencriptacion(alm_str_org, tipo_key); //Ejecuta la función de conversión
          printf("%s", string_desencriptado); //Imprime el resultado        
          break;
        case 5: //Finaliza el programa
          printf("¡Hasta pronto!");
          verif=0;  //Cambia el valor de la variable que funciona como boolean para que finalice con el bucle y finalice el programa
          break;
      }
      if(opcion != 5){  //Se ejecuta después de realizar cualquiera de las funciones, consulta al usuario si es que se quiere seguir utilizando el programa o lo termina  
        printf("\n¿Desea realizar más operaciones? \nSí: Marque 1 \nNo: Marque otro número\n");
        scanf("%i", &opcion2);  //Captura el valor ingresado por consola
        if(opcion2 != 1){ //Cualquier valor ingresado diferente de "1" va a finalizar el programa
          printf("¡Hasta pronto!");
          verif = 0;  //Cambia el valor de la variable que funciona como boolean para que finalice con el bucle y finalice el programa
        }
      }
      vaciar_array(); //Limpia los espacios de memoria de las listas que almacenan datos ingresados para que no haya conflicto si se sigue ejecutando el programa constantemente
    }
    else{ //Funciona como un Exception por si se ingresa un valor no disponible
      printf("\nOpción incorrecta, inténtelo nuevamente");
    }
  }
}
