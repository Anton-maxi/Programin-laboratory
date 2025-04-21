//Знайти максимальний елемент матриці Z=(W+R) та його індекси. Розміри матриць задавати за допомогою директив Сі-препроцесора.


#include <stdio.h>
#include <stdlib.h>
#define STRINGS 2
#define COLUMNS 3


int main()
{
    system("chcp 65001");
    printf("Розмір матриць W та R у форматі: кількість рядків кількість стовпчиків\n");
    printf("W[%d][%d]       R[%d][%d]\n", STRINGS, COLUMNS, STRINGS, COLUMNS);
    float W[STRINGS][COLUMNS];
    float R[STRINGS][COLUMNS];
    printf("Введіть елементи матриці Х:\n");
    for(int i=0; i<STRINGS; i+=1){
        for (int j = 0; j < COLUMNS; j+=1)
        {
        printf("W[%d][%d]=", i,j);
        scanf("%f", &W[i][j]);
        } 
    }
    printf("Введіть елементи матриці R:\n");
    for(int i=0; i<STRINGS; i+=1){
        for (int j = 0; j < COLUMNS; j+=1)
        {
        printf("R[%d][%d]=", i,j);
        scanf("%f", &R[i][j]);
        }
    }
    float Z[STRINGS][COLUMNS];
    for(int i=0; i< STRINGS; i+=1){
        for(int j=0;j<COLUMNS;j+=1){
            Z[i][j]= W[i][j] + R[i][j];
        }
    }
    printf("Матриця Z:\n");
    for(int i=0; i< STRINGS; i+=1){
        for(int j=0;j<COLUMNS;j+=1){
            printf("%f\t", Z[i][j]);
        }
        printf("\n");
    }
    float max = Z[0][0];
    int string_max_elements, column_max_elements;
    for(int i=0; i< STRINGS; i+=1){
        for(int j=0;j<COLUMNS;j+=1){
        if(max<=Z[i][j]){
            max = Z[i][j];
            string_max_elements=i+1;
            column_max_elements=j+1;
        }
        }
    }
    printf("Максимальний елемент матриці Z: Z[%d][%d]=%f", string_max_elements, column_max_elements, max);
    return 0;
}