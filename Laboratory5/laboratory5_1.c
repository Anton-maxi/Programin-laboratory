//Задана квадратна матриця А розміром N х N (N<=10), що складається з дійсних елементів.
//6) Знайти, скільки додатних елементів містить ця матриця в кожному стовпці.

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int count_positive_elements = 0;
    int number_Elements;
    system("chcp 65001");
    printf("Введіть кількість рядків і стовпців квадратної матриці матриці: ");
    scanf("%d", &number_Elements);
    if (number_Elements > 10) {
        printf("Введіть меншу кількість стовпчиків та рядків, щоб кількість Рядків та Стовпчиків <10");
        return 0;
    }
    float* data = (float*) malloc(number_Elements * number_Elements * sizeof(float)); 
    float** A = (float**) malloc(number_Elements * sizeof(float*)); 
    for (int i = 0; i < number_Elements; ++i) {
        A[i] = data + number_Elements * i; 
    }
    printf("Введіть елементи масиву a[%d][%d]:\n", number_Elements,number_Elements);
    for (int i = 0; i < number_Elements; i++) {
        for (int j = 0; j < number_Elements; j++) {
            printf("a[%d][%d] = ", i + 1, j + 1);
            scanf("%f", &A[i][j]);
        }
    }
    for (int j = 0; j < number_Elements; j++) {
        int count_positive_elements = 0;
        for (int i = 0; i < number_Elements; i++) {
            if (A[i][j] > 0) {
                count_positive_elements += 1;
            }
        }
        printf("Кількість позитивних елементів в стовпчику %d : %d\n", j, count_positive_elements);
    }
 
    free(data);
    free(A); 
}
