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
        scanf("%d", &X[i][j]);
        } 
    }
    printf("Введіть елементи матриці Y:\n");
    for(int i=0; i<strings; i+=1){
        for (int j = 0; j < columns; j+=1)
        {
        printf("Y[%d][%d]=", i,j);
        scanf("%d", &Y[i][j]);
        }
    }
    for(int i=0; i< strings; i+=1){
            for(int j=0;j<columns;j+=1){
                printf("%f\n", X[i][j]);
                if(j>=columns)
                printf("\n");
            }
        }

    // float C[strings][columns];
    // for(int i=0; i< strings; i+=1){
    //     for(int j=0;j<columns;j+=1){
    //         C[i][j]= X[i][j] + Y[i][j];
    //     }
    // }
    // for(int i=0; i< strings; i+=1){
    //     for(int j=0;j<columns;j+=1){
    //         printf("%f\t", C[i][j]);
    //         // if(j>=columns)
    //         // printf("\n");
    //     }
    // }



    return 0;
}