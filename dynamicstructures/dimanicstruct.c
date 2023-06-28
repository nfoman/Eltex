#include<malloc.h>
#include<stdlib.h>
#include<stdio.h>
#include <string.h>



#define NAME_SIZE 10
#define SIZE 10
int dynamicsize = 0;

struct contact
{
   
   char name[NAME_SIZE];
   long int phonenumber;

};


int deletecontact(struct contact **person){
    int number;
    printf("Введите индекс контакта");
    scanf("%d",&number);
    struct contact *copy=malloc(sizeof(struct contact));
    if (number<=dynamicsize&&dynamicsize!=0)
    {
         dynamicsize--;
    copy=realloc(copy,sizeof(struct contact) * dynamicsize);

    
    for (int i = 0; i < dynamicsize+1; i++)
    {   
        if(number<i){
            (copy)[i-1]=(*person)[i];
        }
         if(number>i){
            (copy)[i]=(*person)[i];
        }
    }
    printf("Контакт удален");
    free(*person);
    *person=copy;
   

    }
    else{
        printf("Неверный индекс контакта\n");
    }
    
   
}


int findcontact(struct contact *person){
    char arr[NAME_SIZE];
    long int phonenumber;
    int b=0;
    printf("Введите Имя: ");
    scanf("%s",arr);
    printf("Введите номер: ");
    scanf("%ld",&phonenumber);
    
    for (int i = 0; i < SIZE; i++)
    {
        if(strcmp(person[i].name,arr)==0||person[i].phonenumber==phonenumber){
            printf("%s\t%ld\n", person[i].name, person[i].phonenumber );
            b++;
        }
       
    }
    if(b==0){
        printf("не найдено\n");
    }
        
            
}


int addcontact(struct contact **person){
    dynamicsize++; // прибавилось и стало равно 1
    *person=realloc(*person,sizeof(struct contact) * dynamicsize);   
    char arr[NAME_SIZE];
    long int phonenumber;
    printf("\n Введите Имя ");
    scanf("%s",arr);
    strcpy((*person)[dynamicsize-1].name,arr);
    printf("\n Введите номер ");
    scanf("%ld",&phonenumber);
    (*person)[dynamicsize-1].phonenumber=phonenumber;
    printf("Запись удалась\n");
    return 0;
}


int printall(struct contact *person){
    if(dynamicsize!=0){
        for (int i = 0; i < dynamicsize; i++)
        {     
            printf("Индекс %d Имя: %s",i, person[i].name);
            printf(" Номер: %ld\n",person[i].phonenumber);
        }
    }
    else{
        printf("Контактов нету\n");
    }
}


int main(){
    
    struct contact *person=malloc(sizeof(struct contact));
    
    
    int b=0;

    while(b==0){

        int enter;
        printf("1-Добавить Контакт\n2-Удалить Контакт\n3-Поиск\n4-Выход\n5-Вывести справочник \n");
        scanf("%d", &enter);
        switch (enter)
        {
            case 1:
                addcontact(&person);
                
                break;
            case 2:
                deletecontact(&person);
                break;
            case 3:
                findcontact(person);
                break;
            case 4:
                b++;
                free(person);

                
                break;
            case 5:
                printall(person);
                break;

            default:
            
                break;
        }


    }


}












