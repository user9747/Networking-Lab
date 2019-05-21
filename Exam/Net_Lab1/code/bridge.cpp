//AUTHOR : Albin Antony
//         Roll No:10

#include<iostream>
#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>
#include<time.h>
using namespace std;

pthread_mutex_t b_mutex; //bridge mutex
pthread_mutex_t t_mutex; //trafiic mutex
int traffic=0; 
//positive value means number of traffic to left.
//Negative means number of traffic to right

void *left(void *arg){
  long carid = (long)arg;
  printf("Car %d arrived for left\n",carid);//Car arrived
  if(traffic<0){
    printf("Car %d waiting for left\n",carid);//If car 
  }                                           //if moving left

  pthread_mutex_lock(&t_mutex); //locking traffic
  traffic++; 											
  pthread_mutex_unlock(&t_mutex);//unlocking traffic

  pthread_mutex_lock(&b_mutex);
    printf("Car %d passing\n",carid);
    sleep(3);
  pthread_mutex_unlock(&b_mutex);

  pthread_mutex_lock(&t_mutex);//locking traffic
  traffic--;
  pthread_mutex_unlock(&t_mutex);//unlocking traffic
  pthread_exit(NULL);
}

void *right(void *arg){
 long carid = (long)arg;
  printf("Car %d arrived for right\n",carid);//Car arrived
  if(traffic>0){
    printf("Car %d waiting for right\n",carid);//If car is 
  }                                            //moving right

  pthread_mutex_lock(&t_mutex);	//locking traffic
  traffic--;
  pthread_mutex_unlock(&t_mutex);//unlocking traffic

  pthread_mutex_lock(&b_mutex);
    printf("Car %d passing\n",carid);
    sleep(3);
  pthread_mutex_unlock(&b_mutex);

  pthread_mutex_lock(&t_mutex);	//locking traffic
  traffic++;
  pthread_mutex_unlock(&t_mutex);	//unlocking traffic
  pthread_exit(NULL);

}
int main(){
  pthread_t thread;

  pthread_create(&thread,NULL,left,(void *)1);
  pthread_create(&thread,NULL,left,(void *)2);
  pthread_create(&thread,NULL,right,(void *)3);
  pthread_create(&thread,NULL,left,(void *)4);
  pthread_create(&thread,NULL,left,(void *)5);
  pthread_create(&thread,NULL,left,(void *)6);
  pthread_create(&thread,NULL,right,(void *)7);

  pthread_exit(NULL);
  return 0;
}
