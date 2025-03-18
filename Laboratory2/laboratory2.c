#include <stdio.h>
#include <math.h>
int main() {
int numberpoints, i;
printf("Enter the number of points: ");
scanf("%d", &numberpoints);
float xcoordinates [numberpoints];
float ycoordinates [numberpoints];
float zcoordinates [numberpoints];
float mass[numberpoints];
for( i = 0; i < numberpoints; i++){
printf("Enter the mass of %d point:  ",i+1);
scanf("%f", &mass[i]);
printf("Enter the x coordinate of this point:  ");
scanf("%f", &xcoordinates[i]);
printf("Enter the y coordinate of this point:  ");
scanf("%f", &ycoordinates[i]);
printf("Enter the z coordinate of this point:  ");
scanf("%f", &zcoordinates[i]);
}
float summass;
float product_numerator_x = 0, product_numerator_y=0, product_numerator_z=0;
for( i = 0; i < numberpoints; i++){
summass += mass[i];
product_numerator_x += mass[i]*xcoordinates [i];
product_numerator_y += mass[i]*ycoordinates [i];
product_numerator_z += mass[i]*zcoordinates [i];
}
float x= product_numerator_x/summass;
float y= product_numerator_y/summass;
float z= product_numerator_z/summass;
printf("%4.2f\n",x);
printf("%4.2f\n",y);
printf("%4.2f\n",z);
return 0;

}