#include <stdio.h>

#include <conio.h>

#define n 10

int main(){ 
int mas [n], i, k, s; //оголошуємо масив із 10 цілих чисел
float sa;

puts (" Enter elements of massive \n"); // запрошення

for ( i = 0; i < n; i ++)

scanf ("%i", &mas[i]); // вводимо mas[i]

k=0; s=0; // обнуляємо суму та лічильник

for ( i = 0; i < n; i ++)

// у циклі обчислюємо суму та кількість елементів < 0

if ( mas[i]<0 )

{ s += mas[i];

k++;
}
// кінець циклу

if( k){ // перевіряємо наявність від’ємних елементів

sa= (float)s/k;
// виводимо результат на екран

printf ("Arithmetic mean of negative elements of an array %f \n", sa);

}

else

printf ("Number of elements < 0= %i \n", k);

return 0;
}