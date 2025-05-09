// 6. Написати функцію порівняння двох рядків, використовуючи покажчики на них.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Функція порівняння двох рядків за допомогою покажчиків
int compareStrings(const char *s1, const char *s2) {
    // Порівнюємо символи, поки вони не закінчаться або не знайдемо різницю
    while (*s1 !='\0' && *s2 !='\0') {
        if (*s1 != *s2) {
            return (*s1 - *s2);
        }
        s1++;
        s2++;
    }

    // Якщо один із рядків закінчився, повертаємо різницю
}

int main() {
    system("chcp 65001");
    printf("Максимальна кількість елементів для порівняних рядків за замовчуванням: 100\n");
    char str1[100];
    char str2[100];

    printf("Введіть перший рядок:\n");
    fgets(str1, sizeof(str1), stdin);
    printf("Введіть другий рядок:\n");
    fgets(str2, sizeof(str2), stdin);

    // Видаляємо символ нового рядка, якщо він є
    int i= strcspn(str1, "\n");
    str1[i] = '\0';
    int g= strcspn(str2, "\n");
    str2[g] = '\0';

    int result = compareStrings(str1, str2);

    if (result < 0) 
        printf("Перший рядок менший за другий.\n");
    else if (result > 0) 
        printf("Перший рядок більший за другий.\n");
    else 
        printf("Рядки рівні.\n");
    
    return 0;
}