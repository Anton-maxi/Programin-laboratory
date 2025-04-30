#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Функція для введення елементів масиву
void inputArray(double arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Введіть елемент %d: ", i + 1);
        scanf("%lf", &arr[i]);
    }
}

// Функція для обчислення виразу
double calcExpr(double arr[], int n, double (*f)(double), double (*g)(double)) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += arr[i] * f(arr[i]) + (arr[i] * arr[i]) * g(arr[i]);
    }
    return sum;
}

int main() {
    system("chcp 65001");
    int nx, ny, nz, nq;
    double A, B, C, D;

    // Обчислення виразу A 
    printf("Введіть кількість елементів масиву x: ");
    scanf("%d", &nx);
    double x[nx];

    inputArray(x, nx);
    A = calcExpr(x, nx, sin, cos);

    // Обчислення виразу B 
    printf("\nВведіть кількість елементів масиву y: ");
    scanf("%d", &ny);
    double y[ny];

    inputArray(y, ny);
    B = calcExpr(y, ny, cos, sin);

    // Обчислення виразу C
    // Примітка: Другий множник задано як sin(z), оскільки у завданні, ймовірно, є помилка.
    printf("\nВведіть кількість елементів масиву z: ");
    scanf("%d", &nz);
    double z[nz];
    inputArray(z, nz);
    C = calcExpr(z, nz, sin, sin);

    // Обчислення виразу D
    printf("\nВведіть кількість елементів масиву q: ");
    scanf("%d", &nq);
    double q[nq];
    inputArray(q, nq);
    D = calcExpr(q, nq, cos, cos);

    // Виведення результатів
    printf("\nРезультати обчислень:\n");
    printf("A = %lf\n", A);
    printf("B = %lf\n", B);
    printf("C = %lf\n", C);
    printf("D = %lf\n", D);

    return 0;
}