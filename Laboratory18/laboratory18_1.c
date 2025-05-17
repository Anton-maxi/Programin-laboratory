//Самостійно придумати приклад застосування масиву покажчиків на  5 функцій  з двома аргументами. Запрограмувати їхній циклічний  виклик із поверненням результатів в функцію main().

#include <stdio.h>
#include <stdlib.h>

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);
int mod(int a, int b);


int main() {
    system("chcp 65001");
    // Масив покажчиків на функції, які приймають два аргументи типу int
    int (*functions[5])(int, int) = { add, subtract, multiply, divide, mod };

    int a, b, n;
	printf ("Введіть а: ");
	scanf("%d", &a);
	printf ("Введіть b: ");
	scanf("%d", &b);
	printf ("Введіть кількість ітерацій n: ");
	scanf("%d", &n);

    
    printf("Виклик функцій в порядку їх розташування в масиві:\n");
    for (int i = 0; i < 5; i++) {
        int result = functions[i](a, b);
        printf("Функція %d повернула результат: %d\n", i + 1, result);
    }

    // Додатково: демонстрація циклічного виклику функцій (наприклад, n разів по кругу)
    printf("\nЦиклічний виклик функцій (%d ітерацій):\n", n);
	
    for (int i = 0; i < n; i++) {
        int index = i % 5; // Визначення індексу функції в масиві за модулем
        int result = functions[index](a, b);
        printf("Ітерація %d: функція %d повернула %d\n", i + 1, index + 1, result);
    }

    return 0;
}


// Функція для додавання
int add(int a, int b) {
    return a + b;
}

// Функція для віднімання
int subtract(int a, int b) {
    return a - b;
}

// Функція для множення
int multiply(int a, int b) {
    return a * b;
}

// Функція для ділення (з обробкою ділення на нуль)
int divide(int a, int b) {
    if (b != 0)
        return a / b;
    else {
        printf("Помилка: ділення на нуль!\n");
        return 0;
    }
}

// Функція для знаходження остачі від ділення (з обробкою ділення на нуль)
int mod(int a, int b) {
    if (b != 0)
        return a % b;
    else {
        printf("Помилка: ділення на нуль при обчисленні остачі!\n");
        return 0;
    }
}