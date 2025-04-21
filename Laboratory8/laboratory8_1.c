//Знайти мінімальний елемент матриці Z=(X+Y) та його індекси. Розміри матриць задавати за допомогою директив Сі-препроцесора.


#include <stdio.h>
#include <stdlib.h>
#define STRINGS 2
#define COLUMNS 3


int main()
{
    system("chcp 65001");
    printf("Розмір матриць Х та У у форматі: кількість рядків кількість стовпчиків\n");
    printf("Х[%d][%d]       Y[%d][%d]\n", STRINGS, COLUMNS, STRINGS, COLUMNS);
    float X[STRINGS][COLUMNS];
    float Y[STRINGS][COLUMNS];
    printf("Введіть елементи матриці Х:\n");
    for(int i=0; i<STRINGS; i+=1){
        for (int j = 0; j < COLUMNS; j+=1)
        {
        printf("X[%d][%d]=", i,j);
        scanf("%f", &X[i][j]);
        } 
    }
    printf("Введіть елементи матриці Y:\n");
    for(int i=0; i<STRINGS; i+=1){
        for (int j = 0; j < COLUMNS; j+=1)
        {
        printf("Y[%d][%d]=", i,j);
        scanf("%f", &Y[i][j]);
        }
    }
    float Z[STRINGS][COLUMNS];
    for(int i=0; i< STRINGS; i+=1){
        for(int j=0;j<COLUMNS;j+=1){
            Z[i][j]= X[i][j] + Y[i][j];
        }
    }
    printf("Матриця Z:\n");
    for(int i=0; i< STRINGS; i+=1){
        for(int j=0;j<COLUMNS;j+=1){
            printf("%f\t", Z[i][j]);
        }
        printf("\n");
    }
    float min = Z[0][0];
    int string_min_elements, column_min_elements;
    for(int i=0; i< STRINGS; i+=1){
        for(int j=0;j<COLUMNS;j+=1){
        if(min>=Z[i][j]){
            min = Z[i][j];
            string_min_elements=i+1;
            column_min_elements=j+1;
        }
        }
    }
    printf("Мінімальний елемент матриці Z: Z[%d][%d]=%f", string_min_elements, column_min_elements, min);
    return 0;
}