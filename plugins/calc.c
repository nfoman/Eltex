#include<stdlib.h>
#include<stdio.h>
#include <dlfcn.h>
struct function
{
   char namefunc[30];
   char namelib[30];
   int (*func)(int,int); 

};


int main(){
    int *handle;
    struct function *arrfunc=NULL;
    int count = 0;
    char tmp;
    int c;
    while (1)
    {
        arrfunc=realloc(arrfunc,sizeof(struct function)*(count+1));  
        printf("Введите библиотеку ");
        scanf("%s",arrfunc[count].namelib);
        handle=dlopen(arrfunc[count].namelib,RTLD_LAZY);
        if(!handle){
            printf("sosi");
            return -1;
        }
        printf("Введите функцию\n");
        scanf("%s",arrfunc[count].namefunc);
        arrfunc[count].func = (int (*)(int,int)) dlsym(handle, arrfunc[count].namefunc);
        
        printf("Продолжить? 1-да q-нет\n");
        scanf("%c",&tmp);
        if(tmp=='n'){
            
            break;
        }
       count++;
    }
    

    while (1)
    {
         char arr[30];
        for (int i = 0; i <= count; i++)
    {
        printf("%d. %s -> %s\n",i, arrfunc[i].namelib,arrfunc[i].namefunc);
    }
        printf("Введите нужную функцию\t");
        scanf("%d",&c);
        int a , b;
        printf("Введите переменные\t");
        scanf("%d %d", &a, &b);
        printf("%d\n", arrfunc[c].func(a,b));
        printf("Продолжить? 1-да q-нет\n");
        scanf("%c",&tmp);
        if(tmp=='n'){
            
            break;
        }


    }


    
    

}




