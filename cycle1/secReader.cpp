#include<iostream>
#include<semaphore.h>
#include<cstdlib>
#include<pthread.h>
#include<unistd.h>
#include<time.h>

using namespace std;
pthread_mutex_t rmutex;
pthread_mutex_t wmutex;
pthread_mutex_t readTry;
pthread_mutex_t resources;
int readcount=0;
int writecount=0;

void *Writer(void* arg){
    long t=(long)arg;
    pthread_mutex_lock(&wmutex);
    writecount++;
    if (writecount==1)
        pthread_mutex_lock(&readTry);
    pthread_mutex_unlock(&wmutex);
    pthread_mutex_lock(&resources);
    printf("Thread %d writing....\n",t);
    printf("Thread %d finished writing\n",t);
    sleep(2);
    pthread_mutex_unlock(&resources);
    pthread_mutex_lock(&wmutex);
    writecount--;
    if(writecount==0)
        pthread_mutex_unlock(&readTry);
    pthread_mutex_unlock(&wmutex);
    pthread_exit(NULL);
}

void *Reader(void* arg){
    long t=(long)arg;
    pthread_mutex_lock(&readTry);
    pthread_mutex_lock(&rmutex);
    readcount++;
    if(readcount==1){
        pthread_mutex_lock(&resources);
    }
    pthread_mutex_unlock(&rmutex);
    pthread_mutex_unlock(&readTry);
    printf("Thread %d reading.....\n",t);
    sleep(3);
    printf("Thread %d finished reading\n",t);
    pthread_mutex_lock(&rmutex);
    readcount--;
    if(readcount==0){
        pthread_mutex_unlock(&resources);
    }
    pthread_mutex_unlock(&rmutex);
    pthread_exit(NULL);
}


int main(){
    pthread_t t1,t2,t3,t4;
    int rc;
    srand(time(0));
    for(int i=1;i<10;i++){
        if(rand()%2==0)
            rc=pthread_create(&t1,NULL,Reader,(void *)i);
        else
             rc=pthread_create(&t1,NULL,Writer,(void *)i);
    }
   
    pthread_exit(NULL);
}