#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define XY 2
#define N 3

int main()
{
	float coordinates[N][XY]; //N - к-сть точок, XY - координати по х та у
    system("chcp 65001");
	for (int i = 0; i < N; i++) {

		printf("Введіть координати точки [%d]\n", i);
		for (int j = 0; j < XY; j++) {

			if (j == 0) {
				printf("X = ");
			}
			else printf("Y = ");

				scanf("%f", &coordinates[i][j]);

		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < XY; j++) {

			printf("coordinates[%d][%d] = %f    ", i, j, coordinates[i][j]);

		}
        printf("\n");
	}

	printf("\n");

	for (int i = 0; i+1 < N; i++) {

			float distance = 0;
			#include "vidstan.txt"
			printf("Відстань від точки [%d] до точки [%d] = %f\n", i, i+1, distance);

	}





}
