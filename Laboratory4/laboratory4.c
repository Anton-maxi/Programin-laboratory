// //Завдання
// 1) Ввести елементи масиву Х (15).
// 2) Ввести значення цільового елемента (А).
// 3) Знайдіть А за допомогою алгоритму лінійного пошуку.
// 4) Відсортуйте Х за спаданням.
// 5) Знайдіть А за допомогою бінарного пошуку.
// 6) Намалюйте, як відбувається сортування і пошук для Вашого масиву.


#include<stdio.h>
int main() {

int numberElements=15;
float A;
float X[15];
// 1)
printf("Enter the values of the array elements:\n");
for (int i = 0; i < numberElements; i++) {
scanf("%f", &X[i]);
}
// 2)
printf("Enter the value of the target element A = ");
scanf("%f", &A);
int flag=0;
// 3)
for(int i=0;i<numberElements;i++) {
if (A==X[i]) {
    printf("Number of the item found by this search key: %d\n",i+1);
    flag=1;
}
}
if(!flag)
printf("No item found for this search key!");
// 4)
int sort;
for(int i=1; i<numberElements; i++) 
for(int j=0; j<numberElements-i; j++)
if(X[j]<X[j+1]) 
{
sort = X[j]; 
X[j] = X[j+1]; 
X[j+1] = sort; 

}
printf("\nAfter sorting:");
for(int i=0; i<numberElements; i++)
printf(" %.1f ", X[i] );
// 5)
for(int i=1; i<numberElements; i++)   // сотртування для бінарного пошуку
for(int j=0; j<numberElements-i; j++)
if(X[j]>X[j+1]) 
{
sort = X[j]; 
X[j] = X[j+1]; 
X[j+1] = sort; 

}
printf("\nAfter sorting for for searching:");
for(int i=0; i<numberElements; i++)
printf(" %.1f ", X[i] );
int Left = 0, Right = numberElements - 1, Middle, i; 
flag=0;
printf("\nEnter the value of the target element A = ");
scanf("%.1f", &A );
while ( Left <= Right ) {
Middle = (int)((Left + Right)/ 2);
if ( X[Middle] == A ) {
flag = 1;
break;
}
if ( A > X[Middle] ) Left = Middle+1;
else Right = Middle -1;
}
if ( flag )

printf ( "Number of the item found by this search key: %d", Middle+1 );

else printf ( "Not found" );

return 0;

}