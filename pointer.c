#include <stdio.h>
#include <stdlib.h>

void matric(int size){
   int arr[size][size]; //вывод матрицы
    int num =1;
    for(int i=0; i<size;i++){
        for(int j=0; j<size;j++){
            arr[i][j]=num;
            printf("%d\t", arr[i][j]);
            num++;
        }
    printf("\n");
    }
   

}


void reverse(int arr[], int size){ // меняет местами значения в массиве
for(int i=size-1;i>=0;i--){
    printf("%d\t", arr[i]);
}
    
}


void nullmatric(int size){
int check= size -1;
int arr[size][size];
for(int i=0; i<size;i++){
    
        check=size-1-i;
        for(int j=0; j<size;j++){
            
            if(check>0){
                arr[i][j]=0;
            check--;
            }
            else{
                arr[i][j]=1;
            }
            
            // arr[i][j]=1;
            printf("%d\t", arr[i][j]);
            
        }
        
        
    printf("\n");
    }

}


void harry(int size){ // матрица N^2 в центре улитка
    int arr[size][size];
    int num =1;
    
    int i2=0;
    int j2=size;
    int b=size-1;
    int a=0;


     
   while(num<=(size*size)){


    for(int i =i2; i<size-i2;i++){
        
        arr[i2][i]=num;
        num++;

    }
    i2++;
    
    
    for(int j =i2;j<j2;j++){
        arr[j][j2-1]=num;
        num++;
    }
    j2--;
    for(int i=size-2-a;i>=a;i--){
        arr[b][i]=num;
        num++;
    }
    b--;

    for(int j=size-1-i2;j>a;j--){
        arr[j][a]=num;
        num++;
    }
    a++;

   }


for(int i=0; i<size;i++){
        for(int j=0; j<size;j++){
            
            printf("%d\t", arr[i][j]);
            
        }
    printf("\n");
    }
}


void pull(int arr[], int size){
    for(int i=0; i<size;i++){   //dlya zadania 2
    arr[i]=1;
    printf("%d\t", arr[i]);
} 
printf("\n");
}




int main(){
// int arr[5];
int size =5;
harry(5);
   
   



// reverse(arr,10);



// int size =6;
// matric(size);

}
