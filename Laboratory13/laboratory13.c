#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double sum(int n){
    return (n>0)?pow(2*n-1,2)+ sum(n-1):printf("Помилка");
}

int main(){
system("chcp 65001");
double s;
int n;

printf("Введіть до якого n елемента ряду знайти сума цього ряду: ");
scanf("%d", &n);
if(n<1){
printf("Помилка!");
return 0;
}


s= sum(n);
printf("s = %lg", s);
return 0;
}


