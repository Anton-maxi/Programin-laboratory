#include <stdio.h>

int main()
{ int arr[10];

int *p, *pmax; // оголошення покажчиків цілого типу

int i, n;

printf (" n="); scanf("%d",&n);

printf (" input value arr \n");

for (i=0;i<n; i++) // цикл для введення цілих значень у масив

scanf("%d",&arr[i]);

pmax = arr; //присвоюємо вказівнику pmax значення першого елемента масива arr[]

for ( p = arr+1; p < arr+n; p++) // покажчик р це друий елемент масива arr[]. Так як нумарація в масиві починається з 0 то arr + n це умова до поки буде виконуватись цикл враховуючи останнє значення в масиві 

if ( *p > *pmax ) pmax = p ; // // якщо значення, на яке вказує поточний вказівник p, більше ніж значення,
// на яке вказує pmax то оновлюємо pmax для збереження адреси нового максимального елемента.


printf ("Max element =% d \n",*pmax); // виводимо максимальне значення, яке знайдено.

printf("its number =%d \n", pmax-arr+1); // обчислюємо позицію максимального елемента.
// Вираз (pmax - arr) обчислює інтервал (кількість елементів), яке відділяє pmax від початку масиву.
// Додавання 1 дозволяє позицію рахувати з 1 замість 0.


}