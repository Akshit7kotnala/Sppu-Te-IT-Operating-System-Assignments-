#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h> 
#include<semaphore.h> 

int buff[10];
pthread_t pt, ct; 
pthread_mutex_t m;
sem_t empty, full; 

void *producer( void *args)
{
int key, i=0;
    while(1)
    {
    sem_wait(&full); // 
    pthread_mutex_lock(&m);
    key=random() % 10 ; 
    buff[i]=key;  
    printf("\n %d element is added at %d location", key, i);  
    i++;
    if(i==10) i=0;
    pthread_mutex_unlock(&m);
    sem_post(&empty);
    sleep(10);
    }
}

void *consumer( void *args)
{
int key, i=0;
    while(1)
    {
    sem_wait(&empty); 
    pthread_mutex_lock(&m);
    key = buff[i];
    printf("\n %d element is extracted from %d location", key, i);  
    i++;
    if(i==10) i=0;
    pthread_mutex_unlock(&m);
    sem_post(&full); 
    sleep(1);
    }
}
int main()
{
pthread_mutex_init (&m, NULL);
sem_init(&empty, 0, 0);
sem_init(&full, 0, 10);  
pthread_create(&pt, NULL, producer, NULL);
pthread_create(&ct, NULL, consumer, NULL);

pthread_join(pt, NULL);
pthread_join(ct, NULL);

return 0;
}
