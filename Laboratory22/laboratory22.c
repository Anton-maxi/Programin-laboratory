// 6. Із файлу «vhid.txt» прочитати матрицю цілого типу (3*3) . Замінити цифрою 3 всі елементи, які діляться на неї. Отриману матрицю записати у файл «exit.txt».


#include<stdio.h>
#include<stdlib.h>
void main()
{
system("chcp 65001");
FILE *p1, *p2;
p1 =fopen ("vhid.txt", "r");
p2 =fopen ("exit.txt", "w");
if(p1==0 || p2==0)
{
puts("Файл vhid.txt та exit.txt не відкрилися");
fclose(p1); 
fclose(p2);
exit(1);
}
int matrix[3][3];
for (int i= 0; i<3; i+=1){
    for(int j=0; j<3; j+=1){
        fscanf(p1, "%d", &matrix[i][j]);
    }
}
for (int i= 0; i<3; i+=1){
    for(int j=0; j<3; j+=1){
        if(matrix[i][j]%3==0)
        matrix[i][j]=3;
        fprintf(p2, "%d ", matrix[i][j]);
    }
    fprintf(p2,"\n");
}
fclose(p1); 
fclose(p2);
}
