//Значення N>2 M<20 визначати випадковим чином на початку програми, або вводити з клавіатури. Масиви пам'яті для масивів A і B виділяти динамічно.
//Задані два масиви A(N) і B(M) . Підрахувати в них кількість елементів, які перевищують задане значення T і першим на друк вивести масив, що має найменшу їхню кількість.
#include<stdio.h>
#include <stdlib.h>

int countT( double array[], int n, double t){
    int count=0;
    for(int i=0;i<n;i+=1){
        if(array[i]>t)
        count+=1;
    }
    return count;
} 



int main(){
    system("chcp 65001");
    double *A, *B, T;
    int N, M;
     // Перевірка введених значень для N (N > 2)
     do {
        printf("Введіть кількість елементів для масиву A (N > 2): ");
        scanf("%d", &N);
        if (N < 2)
            printf("Помилка: N має бути більше 2. Спробуйте ще раз.\n");
    } while (N < 2);

    // Перевірка введених значень для M (M < 20)
    do {
        printf("Введіть кількість елементів для масиву B (M < 20): ");
        scanf("%d", &M);
        if (M > 20)
            printf("Помилка: M має бути менше 20. Спробуйте ще раз.\n");
    } while (M > 20);
    printf("Введіть значення T: ");
    scanf("%lf", &T);
    A=(double*)calloc(N, sizeof(double));
    if (A == NULL) {
        printf("Помилка виділення пам'яті для масиву A.\n");
        exit(1);
    }
    B=(double*)calloc(M, sizeof(double));
    if (B == NULL) {
        printf("Помилка виділення пам'яті для масиву B.\n");
        free(A);
        exit(1);
    }

    puts("Введіть елементи масиву А:");
    for(int i =0; i<N; i+=1){
        printf("A[%d] = ", i);
        scanf("%lf", &A[i]);
    }
    puts("Введіть елементи масиву B:");
    for(int i =0; i<M; i+=1){
        printf("B[%d] = ", i);
        scanf("%lf", &B[i]);
    }
    int count_A= countT(A, N, T);
    int count_B= countT(B, M, T);
    printf("Результат:\n");
    if(count_A<count_B){
        for(int i=0;i<N;i+=1)
        printf("A[%d]= %lg\n", i, A[i]);
        for(int i=0;i<M;i+=1)
        printf("\nB[%d]= %lg", i, B[i]);
    }
    else {
        for(int i=0;i<M;i+=1)
        printf("B[%d]= %lg\n", i, B[i]);
        for(int i=0;i<N;i+=1)
        printf("\nA[%d]= %lg", i, A[i]);
    }
    free(A);
    free(B);
    return 0;
}











