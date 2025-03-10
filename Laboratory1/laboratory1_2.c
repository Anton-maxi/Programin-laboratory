#include <stdio.h>
#include <math.h>

int main() {
    int numberElements, i;
    printf("Enter the number of elements: ");
    scanf("%d", &numberElements);

    int mas[numberElements];
    printf("Enter %d integers:\n", numberElements);
    for (i = 0; i < numberElements; i++) {
    scanf("%d", &mas[i]);
    }
// 1) мінімальний за модулем елемент масиву
float min= fabs((float) mas[0]); // початкове значення для порівняння
for (i=1; i<numberElements; i++){               // цикл для порівняння 
if (fabs((float) mas[i]) < min){
min = fabs((float) mas[i]);
}
}
printf("Minimal: %f\n", min); // вивід результату
// 2) суму модулів елементів масиву, розміщених після першого елемента, що дорівнює нулю.
float sum=0;
int zero=0;
for (i=0; i<numberElements; i++) {
if(zero==1)
sum += fabs((float) mas[i]); //додавання модуля елемента, який знаходиться після першого нуля

else if (mas[i]==0) // перевірка чи має масив елемент який дорівнює нулю
zero = 1;


}
// виведення результату
if(zero == 1)
printf("The sum of the element modules after the first zero: %f\n", sum);
else
printf("There are no elements equal to zero in the array.\n");

}