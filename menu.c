#include <stdio.h>
#include "/home/emilio/Documentos/archivo.h"

int main (){
 int opcion; 
  printf ("Escoga una opcion \n");
  printf("1) crear un un archivo y llenar el archivo\n");
  printf("2) leer archivo y dar resultado \n");
  scanf ("%d",&opcion);
  switch(opcion){
            case 1:
  		printf("Usted seleccionó la opcion 1\n");
 		llenar_archivo();
 break;
  case 2:
   printf("Usted seleccionó la opcion 2\n");
   leer_archivo();
 break;}
 return (1);
 }
