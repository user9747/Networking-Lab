#include<iostream>
#include <sys/ipc.h> 
#include <sys/msg.h> 
#include<pthread.h>
#include<sys/types.h>
#include<unistd.h>
using namespace std;

struct mesg_buffer{
    long mesg_type;
    int mesg;
}message;

void *NUM(void *msgid){
    message.mesg_type=1;
    for(int i=0;i<10;i++){
        message.mesg=i+1;
        msgsnd((long)msgid,&message,sizeof(message),0);
    }

}
void *READ(void *msgid){
    message.mesg_type=1;
    for(int i=0;i<10;i++){
        msgrcv((long)msgid,&message,sizeof(message),1,0);
        cout<<message.mesg<<endl;
    }

}
int main(){
    key_t key;
    pthread_t thread;
    int rc,msgid;
    key = ftok("test",65);

    msgid = msgget(key,0666 | IPC_CREAT);

    rc = pthread_create(&thread,NULL,NUM,(void *)msgid);
    if(rc){
        cout<<"ERROR";
    }
    rc = pthread_create(&thread,NULL,READ,(void *)msgid);
    if(rc){
        cout<<"ERROR";
    }
pthread_join(thread,NULL);
}