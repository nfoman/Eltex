#include<stdlib.h>
#include<stdio.h>
#include <string.h>


#define NAME_SIZE 10
#define SIZE 10


struct contact
{
   
   char name[NAME_SIZE];
   long int phonenumber;

};


typedef struct contact contact; 


int deletecontact(contact person[]){
    int number;
    printf("Введите индекс контакта");
    scanf("%d",&number);
    strcpy(person[number].name,"0");
    person[number].phonenumber=0;


}









int findcontact(contact person[]){
    char arr[NAME_SIZE];
    long int phonenumber;
    int b=0;
    printf("input name: ");
    scanf("%s",arr);
    printf("input number: ");
    scanf("%d",&phonenumber);
    
    for (int i = 0; i < SIZE; i++)
    {
        if(strcmp(person[i].name,arr)==0||person[i].phonenumber==phonenumber){
            printf("%s\t%ld\n", person[i].name, person[i].phonenumber );
            b++;
        }
       
    }
    if(b==0){
        printf("не найдено");
    }
        
            
}





int fillingbook(contact person[]){
    for (int i = 0; i < SIZE; i++)
    {
        strcpy(person[i].name,"0");
        person[i].phonenumber=0;
    }

    strcpy(person[0].name,"sosalo");
    person[0].phonenumber=12;
    strcpy(person[1].name,"sisa");
    person[1].phonenumber=10;
    strcpy(person[2].name,"sisa");
    person[2].phonenumber=10;
    strcpy(person[3].name,"sisa");
    person[3].phonenumber=10;
   
   
   
    
    
}

int addcontact(contact person[]){
    for (int i = 0; i < SIZE; i++)
    {
        if(person[i].phonenumber==0){
        char arr[NAME_SIZE];
        long int phonenumber;
        printf("\n input name ");
        scanf("%s",arr);
        strcpy(person[i].name,arr);
        printf("\n input phonenumber ");
        scanf("%ld",&phonenumber);
        person[i].phonenumber=phonenumber;
        return 0;
        }
    }
    
    printf("Справочник заполнен");
   

}

int printall(contact person[]){
    for (int i = 0; i < SIZE; i++)
    {   
       
        if(person[i].phonenumber!=0){
        printf("%d %s",i, person[i].name);
        printf("\t%ld\n",person[i].phonenumber);
        }

    }
    
}




int main(){

    contact person[SIZE];
    fillingbook(person);
    
    int b=0;

    while(b==0){

        int enter;
        printf("1-add, 2-delete, 3-find, 4-exit, 5-print\n");
        scanf("%d", &enter);
        switch (enter)
        {
            case 1:
                addcontact(person);
                break;
            case 2:
                deletecontact(person);
                break;
            case 3:
                findcontact(person);
                break;
            case 4:
                b++;
                break;
            case 5:
                printall(person);
                break;

            default:
            
                break;
        }


    }


}












