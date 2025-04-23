//Варіант 6


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calculate_omega (double x, double y, double c, double alfa, double betta){
    double denominator, numerator, additive, omega;
    denominator= fabs(alfa*pow(y,2)+betta*y+7);
    numerator=fabs(2*pow(x,2)-3*x+c);
    additive= fabs(3*x-100);
    omega=(pow(numerator,1/2.0)/pow(denominator,1/3.0))+pow(additive,1/5.0);
    return omega;
}


int main() {
    double x, y, c, alfa, betta, omega;
    system("chcp 65001");
    printf("Введіть значення x: ");
    scanf("%lf", &x);
    printf("Введіть значення y: ");
    scanf("%lf", &y);
    printf("Введіть значення c: ");
    scanf("%lf", &c);
    printf("Введіть значення alfa: ");
    scanf("%lf", &alfa);
    printf("Введіть значення beta: ");
    scanf("%lf", &betta);
    omega = calculate_omega(x, y, c, alfa, betta);


    printf("Значення ω: %lf\n", omega);
    return 0;
}


