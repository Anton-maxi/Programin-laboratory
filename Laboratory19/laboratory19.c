//Дано масиви  x  (n  елементів) та y (m  елементів). Обчислити
//Передбачити дві функції. Одна для введення значень елементів одного масиву.
//Інша - для обробки одного масиву з метою обчислити два результати. Кількістю елементів задаватися самостійно.

#include<stdio.h>
#include<math.h>
#include <stdlib.h>
void inputArray (double array[], int n, char q);
void calcul (double array[], int n, double *s1, double *s2, double f1(double), double f2(double), double *s, double *p, int option_module);

int main(){
    system("chcp 65001");
    int n, m;
    double nu, A, B,C,D,s=0, p=1, option_module=1;
    printf("Введіть кількість елементів масиву x: ");
    scanf("%d", &n);
    printf("Введіть кількість елементів масиву y: ");
    scanf("%d", &m);
    double x[n], y[m]; 
    printf("Введіть елементи масиву x:\n");
    char a='x';
    inputArray (x,n, a);
    printf("Введіть елементи масиву y:\n");
    char b= 'x';
    inputArray(y, m, b);
    
    calcul(y, m, &D, &C, tan, sin, &s, &p, option_module);
    double znam = sin(D) + fabs(cos(D));
    if (znam)
	{
        option_module=0;
        calcul(x, n, &A, &B, sin, cos, &s, &p, option_module);
		nu = (A+B*cos(C))/znam ;
		printf("Результат nu=%lg\n", nu);
	}
	else
		printf("Вибачте! Ділення на нуль ");
	puts("Кінець");

   

}

void inputArray (double array[], int n, char q){
    for (int i=0; i<n; i+=1){
        printf("Введіть %c[%d]= ", q, i+1);
        scanf("%lf", &array[i]);
    }

}
void calcul (double array[], int n, double *s1, double *s2, double f1(double), double f2(double), double *s, double *p, int option_module){
    *s1=0;
    *s2=0;
    *s=0;
    *p=1;
    if(option_module){
        for(int i=0; i<n; i+=1){
            *s1+=array[i]*f1(array[i]);
            *s2 +=array[i]*fabs(f2(array[i]));
            *s+=array[i];
            *p *= array[i];
        }
        *s1 *= *p;
        *s2 *= *s;
    }
    else {
        for(int i=0; i<n; i+=1){
            *s1+=array[i]*f1(array[i]);
            *s2 +=array[i]*f2(array[i]);
            *s+=array[i];
            *p *= array[i];
        }
        *s1 *= *p;
        *s2 *= *s;
    }


}