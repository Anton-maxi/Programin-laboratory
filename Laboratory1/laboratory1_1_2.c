#include <stdio.h>
#include <math.h>

int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int mas[n];
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
    scanf("%d", &mas[i]);
    }

    // a) Сума парних чисел та їх середнє арифметичне
    int even_sum = 0, even_count = 0;
    for (i = 0; i < n; i++) {
    if (mas[i] % 2 == 0) {
    even_sum += mas[i];
    even_count++;
    }
    }
    float even_avg = (even_count != 0) ? (float)even_sum / even_count : 0;

    // б) Добуток непарних чисел та їх середнє геометричне
    int odd_prod = 1, odd_count = 0;
    for (i = 0; i < n; i++) {
    if (mas[i] % 2 != 0) {
    odd_prod *= mas[i];
    odd_count++;
    }
    }
    float odd_gm = pow((float)odd_prod, 1. / odd_count);

    // в) Максимальне значення і його номер
    int max_val = mas[0], max_index = 0;
    for (i = 1; i < n; i++) {
    if (mas[i] > max_val) {
    max_val = mas[i];
    max_index = i;
    }
    }

    // Виведення результатів
    printf("Sum of even numbers: %d\n", even_sum);
    printf("Average of even numbers: %f\n", even_avg);
    printf("Product of odd numbers: %d\n", odd_prod);
    printf("Geometric mean of odd numbers: %f\n", odd_gm);
    printf("Max value: %d at index %d\n", max_val, max_index);

    return 0;
}
