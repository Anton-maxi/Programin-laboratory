//6. Скласти масив структур для опису плаваючих засобів з полями : назва, водотоннажність, матеріал, з якого виготовлений корпус, кількість членів екіпажу, швидкість руху. 
//Занести дані про плаваючі засоби в файл. Потім кожному засобові призначити нову швидкість руху і обновити дані в файлі. 
//Кількість плаваючих засобів ввести із клавіатури.

#include<stdio.h>
#include <stdlib.h>
#include<conio.h>

#include<malloc.h>

int main()
{
    system("chcp 65001");
struct ships
{
    char name[15];
    char material[15];
    double water_tonnage, speed;
    int number_crew;
};

int n; // n - кількість кораблів
FILE*p1;
p1=fopen("file_sotr.txt","w+");
printf("Введіть кількість кораблів = ");
scanf("%d",&n);
struct ships *x;
x=(struct ships*)malloc(n*sizeof(struct ships));
printf("Введіть інформацію про плавуючий засіб на англійській і без пробілів:\n");
for (int i=0;i<n; i+=1)
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
fwrite(&x[i],sizeof(struct ships),1,p1);
}
for(int i=0;i<n;i+=1)
{
fread(&x[i],sizeof(struct ships),0,p1);
printf("Введіть нову швидкість для %s \n", x[i].name);
scanf("%lf",&x[i].speed);
fseek(p1, -(long)sizeof(struct ships),1);
fwrite(&x[i],sizeof(struct ships),1,p1);
fseek(p1, -(long)sizeof(struct ships),1);
fread(&x[i],sizeof(struct ships),0,p1);
printf("Нові дані для %s:\nВодотоннажність - %lg\nМатеріал -  %s\nКількість членів екіпажу -  %d\nШвидкість - %lg\n", x[i].name, x[i].water_tonnage, x[i].material, x[i].number_crew, x[i].speed);
}
puts("FINISH!");
fclose(p1);
return 0;

}