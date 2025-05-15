//Переписати позитивні елементи масиву x(100) і y(80) у масив z підряд. Запис у масив z здійснювати в функції.
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void inputArray (float arr[], int n){
    for(int i=0; i<n; i+=1){
        printf("Введіть елемент %d: ", i + 1);
        scanf("%f", &arr[i]);
    }
}
int ArrayZ (float arr1[], int n1, float arr2[], int n2, float z[]){
    int g=0;
    for (int i=0; i<n1; i+=1){
        if (arr1[i]>0){
            z[g]=arr1[i];
            g+=1;
        }
    }

    for (int i=0; i<n2; i+=1){
        if (arr2[i]>0){
            z[g]=arr2[i];
            g+=1;
        }
    }
    return g;
}

int main() {

    system("chcp 65001");
    int nx=5, ny=3, nz=8, g;
    float x[nx], y[ny], z[nz];
    printf("Введіть елементи масиву х:\n");
    inputArray(x, nx);
    printf("Введіть елементи масиву y:\n");
    inputArray(y, ny);
    g= ArrayZ (x, nx, y, ny, z);
    printf("Масив z:\n");
    for (int i = 0; i<g; i+=1){
        printf("z[%d]=%f\n", i, z[i]);
    }
}

