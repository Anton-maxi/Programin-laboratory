//6. Скласти масив структур для опису плаваючих засобів з полями : назва, водотоннажність, матеріал, з якого виготовлений корпус, кількість членів екіпажу, швидкість руху. 
//Занести дані про плаваючі засоби в файл. Потім кожному засобові призначити нову швидкість руху і обновити дані в файлі. 
//Кількість плаваючих засобів ввести із клавіатури.

#include<stdio.h>

#include<conio.h>

#include<malloc.h>

int main()
{
struct sotrudnic
{
char name[30];
char dolgnost[20];
double age;
double zarplata;
};

int i, n; // n - кількість співробітників
FILE*p1;
p1=fopen("file_sotr.txt","w+");
puts("Enter n=");
scanf("%d",&n);
struct sotrudnic *x;
x=(struct sotrudnic*)malloc(n*sizeof(struct sotrudnic));
for(i=0;i<n;i++)
{
printf("Enter x[%i].name\n", i+1);
scanf("%s",x[i].name);
printf("Enter dolgnost\n");
scanf("%s",x[i].dolgnost);
printf("Enter age\n");
scanf("%lf",&x[i].age);
printf("Enter zarplata\n");
scanf("%lf",&x[i].zarplata);
fwrite(&x[i],sizeof(struct sotrudnic),1,p1);
}
rewind(p1);
for(i=0;i<n;i++)
{
fread(&x[i],sizeof(struct sotrudnic),1,p1);
printf("x[%d].name=%s \nx[%d].dolgnost=%s \nx[%d].age=%lf \nzarplata=%lf\n", i+1, x[i].name, i+1, x[i].dolgnost, i+1, x[i].age, x[i].zarplata);
printf("Enter new zarplata for %s \n",x[i].name);
scanf("%lf",&x[i].zarplata);
fseek(p1, -(long)sizeof(struct sotrudnic),1);
fwrite(&x[i],sizeof(struct sotrudnic),1,p1);
fseek(p1, -(long)sizeof(struct sotrudnic),1);
fread(&x[i],sizeof(struct sotrudnic),1,p1);
printf("new data for %s dolgnost=%s age=%lf zarplata=%lf\n",x[i].name,x[i].dolgnost,x[i].age,x[i].zarplata);
}
puts("FINISH!");
fclose(p1);
getch();
return 0;

}