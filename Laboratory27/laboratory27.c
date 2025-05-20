//6. Дана черга заповнена числами. Сформувати з неї 2 черги, в першій з них містяться парні числа, а в другій – непарні.

#include <stdlib.h>
#include <stdio.h>

typedef struct st {          // структура елементу черги
    int info;                // інформаційне поле
    struct st *next;         // вказівник на наступний елемент черги
} QUOTE;

QUOTE *add(QUOTE *s, int item);     // функція для додавання елемента в кінець черги
int shift(QUOTE **tail, QUOTE **head);  // функція для вилучення елемента з початку черги

int main() {
    QUOTE *head = NULL, *tail = NULL;
    system("chcp 65001");
    int value, count;
    printf("Введіть кількість чисел в черзі: ");
    scanf("%d", &count);
    for (int i = 0; i < count; i+=1) {
        printf("Введіть елемент %d: ", i);
        scanf("%d", &value);
        tail = add(tail, value);
        if (head == NULL)
            head = tail;
    }
    
    // Оголошуємо дві нові черги для парних та непарних чисел
    QUOTE *evenHead = NULL, *evenTail = NULL;
    QUOTE *oddHead = NULL, *oddTail = NULL;
    
    // Розподіляємо елементи початкової черги
    while (head) {
        int num = shift(&tail, &head); // вилучаємо елемент з початкової черги
        if (num % 2 == 0) {             // якщо число парне
            evenTail = add(evenTail, num);
            if (evenHead == NULL)
                evenHead = evenTail;
        } else {                        // якщо число непарне
            oddTail = add(oddTail, num);
            if (oddHead == NULL)
                oddHead = oddTail;
        }
    }
    
    // Виведення черги з парними числами
    printf("\nЧерга з парними числами: ");
    while (evenHead) {
        printf("%d ", shift(&evenTail, &evenHead));
    }
    
    // Виведення черги з непарними числами
    printf("\nЧерга з непарними числами: ");
    while (oddHead) {
        printf("%d ", shift(&oddTail, &oddHead));
    }
    
    return 0;
}

// Функція для додавання нового елемента (item) в чергу.
// s – поточний хвіст черги, який може бути NULL (якщо черга порожня).
QUOTE *add(QUOTE *s, int item) {
    QUOTE *new_item = (QUOTE*)malloc(sizeof(QUOTE)); // виділення пам’яті для нового елемента
    new_item->info = item;  // задаємо значення нового елементу
    new_item->next = NULL;  // новий елемент стає останнім, тому його вказівник на наступний елемент — NULL
    
    if (s != NULL) // якщо черга вже містить елементи,
        s->next = new_item; // встановлюємо зв'язок між попереднім хвостом і новим елементом
    
    return new_item; // повертаємо новий хвіст черги
}

// Функція вилучення елемента з початку черги.
// Повертає значення вилученого елемента.
int shift(QUOTE **tail, QUOTE **head) {
    QUOTE *element = *head;   // отримуємо перший елемент черги
    int value = element->info; // зберігаємо його значення
    *head = element->next;     // пересуваємо голову на наступний елемент
    free(element);             // звільняємо пам’ять вилученого елемента
    
    if (*head == NULL) {       // якщо черга стала порожньою після вилучення
        *tail = NULL;          // скидаємо вказівник хвоста
    }
    
    return value;
}