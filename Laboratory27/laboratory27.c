//6. Реалізуйте перевірку балансу скобок виду '(' , ' [' , ')' , '] ' в арифметичному вираженні.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct st {
    char info;
    struct st *next;
} STACK;

void push(STACK **s, char item);   // Помістити item (символ) у стек *s
char pop(STACK **s);               // Дістати елемент з верху стеку

int main(void) {
    system("chcp 65001");
    STACK *head = NULL;
    char expression[256];
    
    printf("Введіть арифметичний вираз: ");
    if(fgets(expression, sizeof(expression), stdin) == NULL) {
        printf("Помилка зчитування виразу.\n");
        return 1;
    }
    
    // Проходимо по кожному символу виразу
    for (int i = 0; i < strlen(expression); i++) {
        char ch = expression[i];
        
        // Якщо зустрічаємо відкриваючу дужку, заносимо її в стек
        if (ch == '(' || ch == '[') {
            push(&head, ch);
        }
        // Обробка закриваючих дужок
        else if (ch == ')' || ch == ']') {
            // Якщо стек порожній, немає відкриваючої відповідної дужки
            if (head == NULL) {
                printf("Несбалансовано: для символу '%c' немає відкритої дужки\n", ch);
                return 1;
            }
            char top = pop(&head);
            // Перевіряємо відповідність: ')' має відповідати '('; ']' має відповідати '['
            if ((ch == ')' && top != '(') || (ch == ']' && top != '[')) {
                printf("Несбалансовано: символ '%c' не відповідає символу '%c'\n", ch, top);
                return 1;
            }
        }
    }
    
    // Якщо після обробки виразу стек не порожній, це означає, що є невикористані відкриваючі дужки
    if (head != NULL) {
        printf("Несбалансовано: залишились відкриваючі дужки\n");
        return 1;
    }
    
    printf("Вираз збалансований!\n");
    return 0;
}

void push(STACK **s, char item) {
    STACK *new_item = (STACK *)malloc(sizeof(STACK));
    new_item->info = item;
    new_item->next = *s;
    *s = new_item;
}

char pop(STACK **s) {
    STACK *remove_it = *s;
    char value = remove_it->info;
    *s = remove_it->next;
    free(remove_it);
    return value;
}