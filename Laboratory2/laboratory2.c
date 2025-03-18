#include <stdio.h>
#include <math.h>
int main() {
int numberElements, i,n;
printf("Enter the number of elements: ");
scanf("%d", &numberElements);
float A[numberElements];
printf("Enter the values of the array elements:\n");
for(i=0;i<numberElements; i++){
scanf("%f", &A[i]);
}
float min[numberElements];
int r; 
for(i=0;i<numberElements; i++){
    r=(numberElements-1)-i;
        min[i]=fabs(A[r]-A[i]);
        if(r<=i){
            break;
        }
}

printf("Result:\n");
for (i = 0; i < numberElements; i++) {
    if (i >= (numberElements + 1) / 2) {
        break; 
    }
    printf("%4.2f\n", min[i]);
}
return 0;

}