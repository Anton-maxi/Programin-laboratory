//6. Задана матриця А (n, m). Визначити номери тих рядків, які збігаються з одновимірним масивом B (m). 
//Якщо таких рядків немає, видати відповідне повідомлення.

#include <stdlib.h>
#include <stdio.h>

void input_array(double **array, int rows, int columns);

int main(){
    system("chcp 65001");
double **A, *B;
int n, m;
printf("Введіть розміри для матриці А:\n");
printf("Рядків: ");
scanf("%d", &n);
printf("Стовпців: ");
scanf("%d", &m);
A=(double**)calloc(n, sizeof(double*));
/* виділяється пам’ять для масиву вказівників, кількістью nrows і типом int */

if (A == NULL){ /* перевіряє чи виділилась
пам’ять*/
printf("Помилка виділення пам'яті для матриці A.\n");
return 1;
}
for (int i=0;i<n;i++){
A[i]=(double*)calloc(m, sizeof(double));
/* для кожного елементу з вже виділеного масиву виділяється пам’ять для ncolums елементів типу int */
if (A[i] == NULL){
printf("Помилка виділення пам'яті для матриці A.\n");
return 2;
}
}
B=(double*)calloc(m, sizeof(double));
    if (B == NULL) {
        printf("Помилка виділення пам'яті для масиву B.\n");
        for (int i=0;i<n;i++)
        free(A[i]); // звільняється пам’ять
        free(A); // двовимірного масиву
        exit(1);
    }
printf("Введіть значення для матриці А:\n");
input_array(A, n,m);
printf("\nВведіть елементи масиву B:\n");
    for(int i =0; i<m; i+=1){
        printf("B[%d] = ", i);
        scanf("%lf", &B[i]);
    }
int *result;
result=(int*)calloc(n, sizeof(int));
if (result == NULL) {
    printf("Помилка виділення пам'яті для масиву result.\n");
    for (int i=0;i<n;i++)
    free(A[i]); // звільняється пам’ять
    free(A); // двовимірного масиву
    free(B);
    exit(1);
}
int g=0;
for (int i = 0; i < n; i++){
    int row_match = 1;
    for (int j = 0; j < m; j++){
        if (A[i][j] != B[j]){
            row_match = 0;
            break;
        }
    }
    if (row_match) {
        result[g] = i;
        g+=1;
    }
}

puts("Результат:");
if (g > 0) {
    for (int i = 0; i < g; i+=1){
        printf("Рядок %d співпадає з масивом B.\n", result[i]);
    }
} else {
    printf("Рядків, що збігаються з масивом B, не знайдено.\n");
}

for (int i=0;i<n;i++)
free(A[i]); // звільняється пам’ять
free(A); // двовимірного масиву
free(B);
free(result);
return 0;
}

void input_array(double **array, int rows, int columns){
for (int i=0;i<rows;i++){
for (int j=0;j<columns;j++){
printf("A[%d][%d]= ", i, j); 
scanf("%lf",&array[i][j]);
}
}
}