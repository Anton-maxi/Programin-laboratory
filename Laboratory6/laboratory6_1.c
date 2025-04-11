// Знайти максимальний елемент матриці С = (Х + Y) та його індекси, де Х та Y матриці розміром M×N.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int strings = 0, columns= 0;
    system("chcp 65001");
    printf("Напишіть розмір матриць Х та У у форматі: кількість рядків кількість стовпчиків\n");
    scanf("%d %d", &strings, &columns);
    float X[strings][columns];
    float Y[strings][columns];
    printf("Введіть елементи матриці Х:\n");
    for(int i=0; i<strings; i+=1){
        for (int j = 0; j < columns; j+=1)
        {
        printf("X[%d][%d]=", i,j);
        scanf("%f", &X[i][j]);
        } 
    }
    printf("Введіть елементи матриці Y:\n");
    for(int i=0; i<strings; i+=1){
        for (int j = 0; j < columns; j+=1)
        {
        printf("Y[%d][%d]=", i,j);
        scanf("%f", &Y[i][j]);
        }
    }
    float C[strings][columns];
    for(int i=0; i< strings; i+=1){
        for(int j=0;j<columns;j+=1){
            C[i][j]= X[i][j] + Y[i][j];
        }
    }
    printf("Матриця С:\n");
    for(int i=0; i< strings; i+=1){
        for(int j=0;j<columns;j+=1){
            printf("%f\t", C[i][j]);
        }
        printf("\n");
    }
    float max = C[0][0];
    for(int i=1; i< strings; i+=1){
        for(int j=1;j<columns;j+=1){
        if(max<=C[i][j]){
            max = C[i][j];
        }
        }
    }
    printf("Максимальний елемент матриці С: C[%d][%d]=%f", strings, columns, max);
    return 0;
}