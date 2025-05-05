//Даний рядок S і символ c. Підрахувати в ньому кількість входжень c у рядок S.
#include <stdio.h>

#include <conio.h>
#include <stdlib.h>
#include <string.h>


int main( void ){
    system("chcp 65001");
    char S[100];  // буфер для введення рядка
    char c;
    int count = 0;
    
    printf("Введіть рядок S: ");
    gets(S);
    // Видаляємо символ нового рядка, якщо він є
    int i= strcspn(S, "\n");
    S[i] = '\0';

    printf("Введіть символ c: ");
    scanf("%c", &c);

    for (int i = 0; S[i] != '\0'; i+=1) {
        if (S[i] == c) {
            count+=1;
        }
    }

    printf("Символ '%c' зустрічається %d раз(и) у рядку: %s", c, count, S);

    return 0;


}
