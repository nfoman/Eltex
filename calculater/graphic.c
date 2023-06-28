#include<stdlib.h>
#include<stdio.h>
#include"calculater.h"
void graphic(){

int e= 1;
int a, b;



while (e==1)
{  printf("Введите два аргумента ");
   scanf("%d %d",&a, &b);
   printf("1-плюс, 2-минус, 3-умножение, 4-деление, 5-выход\n");
   int r;
   scanf("%d",&r);
   
switch (r)
{
    case 1:
    printf("\nрезультат = %d \n", plus(a, b));
        break;
    case 2:
    printf("\nрезультат = %d \n", minus(a, b));
        break;
    case 3:
    printf("\nрезультат = %d \n", multi(a, b));
        break;
    case 4:
    printf("\nрезультат = %d \n", delenie(a, b));
        break;
    case 5:
    e=0;
        break;
    default:
    printf("Вы Вввели некоректное значение");
        break;
}

}




}