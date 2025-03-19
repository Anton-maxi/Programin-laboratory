// Заданий вектор A[N]. Знайти в ньому найдовшу послідовність підряд розміщених від’ємних елементів.
#include <stdio.h>

int main() {
    int numberElements;
    printf("Enter the number of elements: ");
    scanf("%d", &numberElements);

    float A[numberElements];
    printf("Enter the values of the array elements:\n");
    for (int i = 0; i < numberElements; i++) {
        scanf("%f", &A[i]);
    }

    int maxLength = 0, currentLength = 0;
    int startIndex = -1, maxStartIndex = -1;

    for (int i = 0; i < numberElements; i++) {
        if (A[i] < 0) {
            currentLength+=1;
            if (currentLength > maxLength) {
                maxLength = currentLength;
                if(startIndex == -1){
                    maxStartIndex = i; 
                }
                else {
                    maxStartIndex = startIndex; 
                }
                
            }
        } 
        else {
            currentLength = 0;
            startIndex = -1;
        }

        if (currentLength == 1) {
            startIndex = i;
        }
    }

    printf("The longest sequence of consecutive negative elements has length: %d\n", maxLength);
    if (maxLength > 0) {
        printf("Its initial index: %d\n", maxStartIndex);
        printf("Consistency: ");
        for (int i = maxStartIndex; i < maxStartIndex + maxLength; i++) {
            printf("%.2f;  ", A[i]);
        }
    } 
    else {
        printf("There are no negative sequences in the vector.\n");
    }

    return 0;
}