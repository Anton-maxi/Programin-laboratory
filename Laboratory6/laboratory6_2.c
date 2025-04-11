//Сформувати вектор d із найбільших негативних елементів відповідних стовпців матриці s[3×5].
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int strings = 3, columns= 5;
    system("chcp 65001");
    float s[strings][columns];
    printf("Введіть елементи матриці Х:\n");
    for(int i=0; i<strings; i+=1){
        for (int j = 0; j < columns; j+=1)
        {
        printf("s[%d][%d]=", i,j);
        scanf("%f", &s[i][j]);
        } 
    }
    printf("Матриця s:\n");
    for(int i=0; i< strings; i+=1){
        for(int j=0;j<columns;j+=1){
            printf("%f\t", s[i][j]);
        }
        printf("\n");
    }
    float d[5];
    float negetive_element;
    for(int i=0; i< columns; i+=1){
        negetive_element=s[0][i];
        for(int j=0;j<strings;j+=1){
            if(negetive_element>=s[j][i]){
                negetive_element=s[j][i];
                d[i]=negetive_element;
            }
        }
    }
    printf("Вектор d:\n");
    for (int i=0;i<columns; i+=1){
        printf("%f\t", d[i]);
    }
}