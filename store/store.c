#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

struct pokypatel
{
   int number;
   int need;
};
int store[5];

pthread_mutex_t mutexes[5];
int stores = 5;
int needs=0;


void *thread_store(void*args){
    struct pokypatel *pokyp = (struct pokypatel*) args; 
      
    while (pokyp->need>0)
    {   
        int id= rand()%stores;
        if (store[id]>500)
        {
            sleep(1);
            pthread_mutex_lock(&mutexes[id]);
                pokyp->need-=500;
                store[id]-=500;
                printf("store id%d store have%d number%d need%d\n",id,store[id],pokyp->number,pokyp->need);
            pthread_mutex_unlock(&mutexes[id]);
        }
        
        
    }
    printf("number%d need%d\n",pokyp->number,pokyp->need);
    needs++;
    pthread_exit(0);
}
    
void* pogruz(void*args){
    while (needs<3)
    {
        sleep(2);
        int ind = rand() % 5; 
		pthread_mutex_lock(&mutexes[ind]);
			store[ind] += 500;
			printf("I'm pogruz, dobavil v etot magaz %d, seichas tam %d\n",ind , store[ind]); 
		pthread_mutex_unlock(&mutexes[ind]);
		
    }
    
}

    
    

int main(){
    srand(time(0));
    pthread_t thread[3];
    int* s;
    struct pokypatel pokyp[3];
    for (int i = 0; i < 3; i++)
    {
        pokyp[i].need=10000;
        pokyp[i].number=i+1;
    }
    
    for (int i = 0; i < stores; i++)
    {
        store[i]=1000;
    }
    for (int i = 0; i < stores; i++) {
		pthread_mutex_init(&mutexes[i], NULL);	
	}
    for (int i = 0; i < 3; i++)
    {   
        void *ptr=&pokyp[i];
        pthread_create(&thread[i],NULL,thread_store,ptr); 
    }
    pthread_t loader;
	pthread_create(&loader, NULL, pogruz, NULL);
		
    for (int i = 0; i < 3; i++)
    {
        pthread_join(thread[i],(void**)&s);
    }
	pthread_join(loader, NULL);
	for (int i = 0; i < 3; i++) {
	    pthread_mutex_destroy(&mutexes[i]);
	}
	
	exit(EXIT_SUCCESS);
    
    

}