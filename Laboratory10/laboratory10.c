// Дано три одновимірні масиви, кожний із яких має довільну кількість елементів. Для кожного із них знайти найменший та найбільший елементи та їхні номери. 
// Окрім функції main() застосувати дві функції. Одна – для введення елементів окремого масиву із клавіатури, 
// а інша – для його аналізу з метою отримати потрібні результати.

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

#define MAX_SIZE 100  // Максимальна кількість елементів у масиві

// Функція для вводу елементів масиву
void inputArray(int mas[], int *size) {
    printf("Введіть розмір масиву: ");
    scanf("%d", size);
    for (int i = 0; i < *size; i++) {
        printf("Введіть елемент [%d]: ", i);
        scanf("%d", &mas[i]);
    }
}

void analyzeArray(const int mas[], int n, int *min, int *minIndex, int *max, int *maxIndex) {
    // Ініціалізуємо змінні першими елементом масиву
    *min = mas[0];
    *max = mas[0];
    *minIndex = 0;
    *maxIndex = 0;
    
    for (int i = 1; i < n; i++) {
        if (mas[i] < *min) {
            *min = mas[i];
            *minIndex = i;
        }
        if (mas[i] > *max) {
            *max = mas[i];
            *maxIndex = i;
        }
    }
}

int main(void) {
    system("chcp 65001");
    int mas1[MAX_SIZE], mas2[MAX_SIZE], mas3[MAX_SIZE];
    int size1, size2, size3;
    int min, minIndex, max, maxIndex;
    
    // Працюємо з першим масивом
    printf("Введіть дані для першого масиву:\n");
    inputArray(mas1, &size1);
    analyzeArray(mas1, size1, &min, &minIndex, &max, &maxIndex);
    printf("Перший масив: мінімальне значення %d на позиції %d, максимальне значення %d на позиції %d\n\n", min, minIndex, max, maxIndex);
    
    // Працюємо з другим масивом
    printf("Введіть дані для другого масиву:\n");
    inputArray(mas2, &size2);
    analyzeArray(mas2, size2, &min, &minIndex, &max, &maxIndex);
    printf("Другий масив: мінімальне значення %d на позиції %d, максимальне значення %d на позиції %d\n\n", min, minIndex, max, maxIndex);
    
    // Працюємо з третім масивом
    printf("Введіть дані для третього масиву:\n");
    inputArray(mas3, &size3);
    analyzeArray(mas3, size3, &min, &minIndex, &max, &maxIndex);
    printf("Третій масив: мінімальне значення %d на позиції %d, максимальне значення %d на позиції %d\n", min, minIndex, max, maxIndex);
    
    return 0;
}
