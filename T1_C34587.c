#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANO 10

int encontrar_diagonal_mas_larga(int matriz[TAMANO][TAMANO], int tamano) {
    int maximo1 = 0;
    int diagonal = 0;

    for (int k = 1; k <= 2 * tamano - 1; k++) {
        int inicio_fila = (k <= tamano) ? tamano - k : 0;
        int inicio_col = (k <= tamano) ? tamano - 1 : 2 * tamano - k - 1;
        int pasos = (k <= tamano) ? k : 2 * tamano - k;

        for (int paso = 0; paso < pasos; paso++) {
            int fila = inicio_fila + paso;
            int col = inicio_col - paso;
            
            if (matriz[fila][col] == 1) {
                diagonal++;
                if (diagonal > maximo1) {
                    maximo1 = diagonal;
                }
            } else {
                diagonal = 0;
            }
        }
    }

    return maximo1;
}

int main() {
    char nombre_archivo[100];
    int matriz[TAMANO][TAMANO];
    int tamano = 0;
    FILE *archivo;

    printf("Ingrese el nombre del archivo: ");
    scanf("%99s", nombre_archivo);

    archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    char linea[100];
    int filas = 0;
    int columnas = 0;
    
    while (fgets(linea, sizeof(linea), archivo) != NULL && filas < TAMANO) {
        columnas = 0;
        char *valor = strtok(linea, " \t\n");
        
        while (valor != NULL && columnas < TAMANO) {
            if (strcmp(valor, "0") != 0 && strcmp(valor, "1") != 0) {
                printf("Error:Hay un Valor no binario.\n");
                fclose(archivo);
                return 1;
            }
            matriz[filas][columnas] = atoi(valor);
            columnas++;
            valor = strtok(NULL, " \t\n");
        }

        if (columnas == 0) continue; 

        if (filas == 0) {
            tamano = columnas; 
        } else if (columnas != tamano) {
            printf("Error: La matriz no es cuadrada.\n");
            fclose(archivo);
            return 1;
        }
        filas++;
    }

    fclose(archivo);

    if (filas != tamano) {
        printf("Error: La matriz no es cuadrada.\n");
        return 1;
    }

    printf("Matriz leída:\n");
    for (int i = 0; i < tamano; i++) {
        for (int j = 0; j < tamano; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    int secuencia_mas_larga = encontrar_diagonal_mas_larga(matriz, tamano);
    printf("La secuencia de 1s más larga es: %d\n", secuencia_mas_larga);

    return 0;
}