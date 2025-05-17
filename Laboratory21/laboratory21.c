//Описати відповідні дані у вигляді структури. Для обчислень написати функцію, що використовує параметр типу структура.
//6. Перевірити, чи вектори ортогональні.

#include <stdio.h>
#include <stdlib.h>

struct vectors
{
   double x, y;
};

void inputVector( struct vectors *v, char *str){
    printf("Введіть координати для %s вектора:\n", str);
    printf("x= ");
    scanf("%lf", &v->x);
    printf("y= ");
    scanf("%lf", &v->y);

}

double scalar_product(struct vectors *v1, struct vectors *v2){
    return (v1->x) * (v2->x)+ (v1->y) * (v2->y);
}

int main() {
    system("chcp 65001");
    struct vectors vector1, vector2;
    inputVector(&vector1, "першого");
    inputVector(&vector2, "другого");
    //double scalar_product;
    //scalar_product = vector1.x * vector2.x + vector1.y * vector2.y;
    if(!(scalar_product(&vector1, &vector2)))
        printf("Вектори - ортогональні\n");
    else  printf("Вектори - НЕ ортогональні\n");


    printf("%lf", scalar_product(&vector1, &vector2));
    return 0;
}

 

