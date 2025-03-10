#include <stdio.h>
#include <math.h>

int main() {
    int numberElements, i;
    printf("Enter the number of elements: ");
    scanf("%d", &numberElements);

    float mas[numberElements];
    printf("Enter %d integers:\n", numberElements);
    for (i = 0; i < numberElements; i++) {
    scanf("%f", &mas[i]);
    }
  
    // a) Сума парних чисел та їх середнє арифметичне
    int even_sum = 0, even_count = 0;
    for (i = 0; i < numberElements; i++) {
    if (!fmod(mas[i], 2)) {
    even_sum += mas[i];
    even_count++;
    }
    }
    float even_avg = (float)even_sum / even_count;

    // б) Добуток непарних чисел та їх середнє геометричне
    int odd_prod = 1, odd_count = 0;
    for (i = 0; i < numberElements; i++) {
    if (fmod(mas[i], 2)) {
    odd_prod *= mas[i];
    odd_count++;
    }
    }
    float odd_gm = pow((float)odd_prod, 1. / odd_count);

    // в) Максимальне значення і його номер
    int max_val = mas[0], max_index = 0;
    for (i = 1; i < numberElements; i++) {
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
