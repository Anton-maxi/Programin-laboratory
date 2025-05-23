//6. Скласти масив структур для опису країн з полями : назва, кількість населення, площа, на якому материку перебуває.
//Вивести в окремий файл всі дані по країнах, що перебувають на заданому із клавіатури материку й площа яких вище заданого значення.

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#define N 4

int main ( )

{
system("chcp 65001");
struct county
{
char name[15];
int population_size;
double area;
char continent[20];

}x[N];
FILE *f1;
int i;
char filter[20];
double filter_area=0;
f1=fopen("result.txt","w");
printf("Введіть інформацію про країни на англійській і без пробілів:\n");
for (i=0;i<N; i++)
{
printf("Країна Номер %d:\n", i+1);
printf("Назва- ");
scanf("%s",&x[i].name);
printf("Кількість населення- ");
scanf("%d",&x[i].population_size);
printf("Площа- ");
scanf("%lf",&x[i].area);
printf("Материк, де вона знаходиться- ");
scanf("%s",&x[i].continent);
}
printf("Введіть материк для вибірки країн (наприклад: Europe):\n");
scanf("%s",&filter);
printf("Введіть площу для вибірки країн:\n");
scanf("%lf",&filter_area);
printf("Результат пошуку:\n");
for (i=0;i<N;i++)
if((strcmp(x[i].continent, filter)==0)&& (x[i].area>filter_area))
{
fprintf(f1, "Назва= %s\nКількість населення= %d\nПлоща= %lg\nМатерик- %d\n", x[i].name, x[i].population_size, x[i].area, x[i].continent);
printf("Назва= %s\nКількість населення= %d\nПлоща= %lg\nМатерик- %d\n", x[i].name, x[i].population_size, x[i].area, x[i].continent);
}
fclose(f1);
return 0;

}