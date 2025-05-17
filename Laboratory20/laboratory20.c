// Варіант №6
// В одновимірному масиві, елементами якого є записи з наступною структурою:
// Прізвище студента, оцінка 1, оцінка 2, середній бал (підраховується автоматично).
// Знайти та вивести на екран прізвища студентів, у яких середній бал менше 4,0.

#include <stdio.h>
#include <stdlib.h>



int main() {
    int n;
    system("chcp 65001");
    // Введення кількості студентів
    printf("Введіть кількість студентів: ");
    scanf("%d", &n);

    
    struct Student {
        char surname[50];
        int grade1;
        int grade2;
        float avg; // середній бал
    } Student[n], *students=Student;

    // Зчитування даних для кожного студента та обчислення середнього бала
    for (int i = 0; i < n; i++) {
        printf("\nСтудент %d\n", i + 1);
        printf("Введіть прізвище: ");
        scanf("%s", students[i].surname);
        printf("Введіть оцінку 1: ");
        scanf("%d", &students[i].grade1);
        printf("Введіть оцінку 2: ");
        scanf("%d", &students[i].grade2);
        
        // Обчислення середнього бала як середнє арифметичне двох оцінок
        students[i].avg = (students[i].grade1 + students[i].grade2) / 2.0;
    }

    // Вивід прізвищ студентів, у яких середній бал менше 4.0
    printf("\nСтуденти з середнім балом менше 4.0:\n");
    for (int i = 0; i < n; i++) {
        if (students[i].avg < 4.0) {
            printf("%s\n", students[i].surname);
        }
    }
    
    return 0;
}