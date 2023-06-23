#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print(int num)
{
    printf("num = %08X\n", num);
    int temp=0xFF;
    for(int i=0; i<4;i++){
    
        printf("bite =%X\n", num&temp);
    num=num>>8;
}

}

void null(int num, int newbite)
{

    printf("num = %08X\n", num);
    int temp=0xFF00FFFF;
    num=num&temp;
    newbite=newbite<<16;
    printf("new num bite = %X\n", num|newbite);



}


void printp(unsigned char*p){   // вывод одного байта 

    for(int i=0;i<4;i++){
        printf("bite = %X\n", *p);
        p++;
    }
}
void nullp(unsigned char*p,int newbite,unsigned int*p1){ // замена байта 3
    p=p+2;
    
    printf("bite = %0X\n", *p1);
    *p=newbite;
    printf("bite = %X\n", *p);
    
printf("bite = %0X\n", *p1);
}


int main()
{

int num =0xDDCCBBAA;
 char* p;
 int *p1;
 p1=&num;
 p=&num;
// printp(p);


// print(num);
int newbite = 0xEE;
nullp(p, newbite,p1);
// null(num,newbite);
}