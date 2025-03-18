#include <stdio.h>
#include <math.h>
int main() {
int numderpoints, i,n=1;
float coordinates [numderpoints];
float mass[numderpoints];
printf("Enter the number of points: ");
scanf("%d", numderpoints);
for( i = 0; i < numderpoints; i++){
printf("Enter the mass of %d point:  ", n);
scanf("%f", mass[i]);
n++;
}


return 0;

}