// 6) Визначити кількість ненульових елементів у кожному рядку матриці В[M×N] та сформувати із цих елементів вектор С.

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int count_non_zero_elements = 0;
    int number_Elements_stack, number_Elements_string;
    system("chcp 65001");
    printf("Введіть кількість рядків матриці: ");
    scanf("%d", &number_Elements_string);
    printf("Введіть кількість стовпчиків матриці: ");
    scanf("%d", &number_Elements_stack);
    float* data = (float*)malloc(number_Elements_stack * number_Elements_string * sizeof(float));
    float** B = (float**)malloc(number_Elements_string * sizeof(float*));
    for (int i = 0; i < number_Elements_string; ++i) {
        B[i] = data + number_Elements_stack * i; 
    }
    printf("Введіть елементи масиву a[%d][%d]:\n", number_Elements_string, number_Elements_stack);
    for (int i = 0; i < number_Elements_string; i++) {
        for (int j = 0; j < number_Elements_stack; j++) {
            printf("a[%d][%d] = ", i + 1, j + 1);
            scanf("%f", &B[i][j]);
        }
    }
    for (int i = 0; i < number_Elements_string; i++) {
        int count_non_zero_elements = 0;
        for (int j = 0; j < number_Elements_stack; j++) {
            if (B[i][j] !=0) {
                count_non_zero_elements += 1;
            }
        }
        printf("Кількість ненульових елементів в рядку %d : %d\n", i+1, count_non_zero_elements);
    }
 
    free(data); 
    free(B); 
}

