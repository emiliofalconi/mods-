#include <stdio.h>
#include <stdlib.h>

void llenar_archivo(char *nombre_archivo, char *contenido) {
    FILE *archivo = fopen(nombre_archivo, "w");

    if (archivo == NULL) {
        printf("Error al abrir el archivo\n");
        return;
    }

    fprintf(archivo, "%s", contenido);
    fclose(archivo);
}


void leer_archivo() {
    FILE *archivo;
    char nombreArchivo[50];
    char info[4];
    
    printf("Introduzca el nombre del archivo: ");
    scanf("%s", nombreArchivo);
    
    archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.");
        return ;
    }
    
    fscanf(archivo, "%4s", info);
    printf("Los primeros 4 caracteres del archivo son: %s", info);
    
    fclose(archivo);
//    return 0;
}
