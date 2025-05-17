//№3 
//Дано масиви  α  (n  елементів) та β (m  елементів). Обчислити
// Передбачити дві функції. Одна для введення значень елементів одного масиву.
// Інша - для обробки одного масиву з метою обчислити три результати. Кількістю елементів задаватися самостійно.

#include<stdio.h>
#include<math.h>
#include <stdlib.h>
void inputArray (double array[], int n, char q);
void calcul (double array[], int n, double *s1, double *s2, double *s3, double f1(double), double f2(double), double *s);

int main(){
    system("chcp 65001");
    int n, m;
    double omega, A, B,C,D,F,E,s=0, s1=222;
    printf("Введіть кількість елементів масиву a: ");
    scanf("%d", &n);
    printf("Введіть кількість елементів масиву b: ");
    scanf("%d", &m);
    double alfa[n], betta[m]; 
    printf("Введіть елементи масиву a:\n");
    char a='a';
    inputArray (alfa,n, a);
    printf("Введіть елементи масиву b:\n");
    char b= 'b';
    inputArray(betta, m, b);
    
    calcul(betta, m, &D, &E, &F, cos, fabs, &s1);
    double znam = D + E*sin(F);
    if (znam)
	{
	calcul(alfa, n, &A, &B, &C, tan, sin, &s);
		omega = (A * cos(B)+C) /znam ;
		printf("Результат omega=%lg\n", omega);
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
void calcul (double array[], int n, double *s1, double *s2, double *s3, double f1(double), double f2(double), double *s){
    *s1=0;
    *s2=1;
    *s3=0;
    if(*s!=222.0){
        *s=0;
        for(int i=0; i<n; i+=1){
            *s1+=array[i]*f1(array[i]);
            *s2 *=array[i];
            *s3+= array[i]* f2(array[i]);
            *s+=array[i];
        }
        *s1 *= *s;
        *s3 *= *s;
    }
    else{
        for(int i=0; i<n; i+=1){
            *s1+=array[i]*f1(array[i]);
            *s2 *=array[i];
            *s3+= array[i]* f2(array[i]);
        }
}

}