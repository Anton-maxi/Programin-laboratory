//6. Скласти масив структур для опису плаваючих засобів з полями : назва, водотоннажність, матеріал, з якого виготовлений корпус, кількість членів екіпажу, швидкість руху. 
//Вивести на екран і в окремий файл всі дані про плаваючі засоби, у яких корпус виготовлений із введеного із клавіатури матеріалу.


#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#define N 4

int main ( )

{
system("chcp 65001");
struct ships
{
char name[15];
char material[15];
double water_tonnage, speed;
int number_crew;

}x[N];
FILE *f1;
int i;
char filter[20];
f1=fopen("result.txt","w");
printf("Введіть матеріал для вибірки кораблів (наприклад: zalizo):\n");
scanf("%s",&filter);
printf("Введіть інформацію про плавуючий засіб на англійській і без пробілів:\n");
for (i=0;i<N; i++)
{
printf("Корабль Номер %d:\n", i+1);
printf("Назва- ");
scanf("%s",&x[i].name);
printf("Водотоннажність- ");
scanf("%lf",&x[i].water_tonnage);
printf("Матеріал, з якого виготовлений корпус- ");
scanf("%s",&x[i].material);
printf("Кількість членів екіпажу- ");
scanf("%d",&x[i].number_crew);
printf("Швидкість руху- ");
scanf("%lf",&x[i].speed);
}
printf("Результат пошуку:\n");
for (i=0;i<N;i++)
if((strcmp(x[i].material, filter)==0))
{
fprintf(f1, "Назва= %s\nВодотоннажність= %lg\nМатеріал= %s\nКількість членів екіпажу= %d\nШвидкість= %lg", x[i].name, x[i].water_tonnage, x[i].material, x[i].number_crew, x[i].speed);
printf("Назва= %s\nВодотоннажність= %lg\nМатеріал= %s\nКількість членів екіпажу= %d\nШвидкість= %lg", x[i].name, x[i].water_tonnage, x[i].material, x[i].number_crew, x[i].speed);
}
fclose(f1);
return 0;

}