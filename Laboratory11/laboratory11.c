// Обчислити z=(xm1+xm2)/2, де xm1,xm2 - найменші елементи масивів x1(70), x2(80). Найменші елементи масивів обчислювати за допомогою функції.
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

// Функція для вводу елементів масиву
void inputArray(int x[], int *size) {
    for (int i = 0; i < *size; i++) {
        printf("Введіть елемент [%d]: ", i);
        scanf("%d", &x[i]);
    }
}

void analyzeArray(const int x[], int n, int *min, int *minIndex) {
    // Ініціалізуємо змінні першими елементом масиву
    *min = x[0];
    *minIndex = 0;
    
    for (int i = 1; i < n; i++) {
        if (x[i] < *min) {
            *min = x[i];
            *minIndex = i;
        }
    }
}

int main(void) {
    system("chcp 65001");
    int size1=70, size2=80;
    int x1[size1], x2[size2];
    int min1, minIndex1, min2, minIndex2;
    double z;
    
    // Працюємо з першим масивом
    printf("Введіть дані для першого масиву:\n");
    inputArray(x1, &size1);
    analyzeArray(x1, size1, &min1, &minIndex1);
    printf("Перший масив: мінімальне значення %d на позиції %d\n\n", min1, minIndex1);
    
    // Працюємо з другим масивом
    printf("Введіть дані для другого масиву:\n");
    inputArray(x2, &size2);
    analyzeArray(x2, size2, &min2, &minIndex2);
    printf("Другий масив: мінімальне значення %d на позиції %d\n\n", min2, minIndex2);

    z= (min1+min2)/2.0;
    printf("z=%lf", z);

    return 0;
}
