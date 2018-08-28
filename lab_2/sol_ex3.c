#include <stdio.h>
char *obtenerSubcadena(char *array, int index);

int main(void) {
    char *p1 = malloc(256);
    char *p2;
    int i,j;
    printf("Ingrese el parrafo que desea cortar\n");
    fgets(p1, 256, stdin);
    /* Eliminar nueva lC-nea final, si existe. */
    if ((strlen(p1) > 0) && (p1[strlen (p1) - 1] == '\n')){
        p1[strlen (p1) - 1] = '\0';
    }
     j = 1;
    while(j == 1){
        printf("Ingrese el indice desde donde desea cortar\n");
        scanf("%d", &i);
        if(strlen (p1)>i){
            j = 2;
        }else{
            printf("El indice ingresado sobrepasa el tamano del parrafo, ingreselo de nuevo\n");
            printf("tamano del parrafo: %d\n", strlen (p1));
            printf("numero ingresado: %d\n", i);
        }
        
    }
    printf("Parrafo ingresado: %s\n", p1);
    p2 = obtenerSubcadena(p1, i);
    printf("Parrafo cortado: %s\n", p2);
    free (p1);
  return 0;
}

char *obtenerSubcadena(char *array, int index) {
  char *p = malloc(256);
  memcpy(p, array + index + 1, 256);
  return p;
}