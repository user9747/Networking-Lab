#include<iostream>
#include<cstdlib>
#include<pthread.h>
#include<sys/types.h>
#include<unistd.h>
using namespace std;

#define NUM_THREAD 4

void *Printer(void *threadId){
	printf("Thread %d of process %d\n",threadId,getpid());
    	pthread_exit(NULL);
}

int main(){
    pthread_t thread;
    int rc;
    int f=fork();
    if(f==0){
	printf("cHilD is %d \n",getpid());
    	for(int i=0;i<NUM_THREAD;i++){
        	rc = pthread_create(&thread,NULL,Printer,(void *)i);
      		if(rc){
        	    	cout<<"ErrOR";
        	}
    	}
    }
    else{
	printf("pAreNt is %d \n",getpid());
    	for(int i=0;i<NUM_THREAD;i++){
        	rc = pthread_create(&thread,NULL,Printer,(void *)i);
      		if(rc){
        		cout<<"ErrOR";
        	}
    	}

    }
    pthread_exit(NULL);

}
