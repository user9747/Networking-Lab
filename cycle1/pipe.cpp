#include<iostream>
#include <sys/types.h>
#include<unistd.h>
using namespace std;

int main(){
    int pid,pip[2];
    char string[20];
    pipe(pip); 

    pid =fork();
    if(pid==0){
        write(pip[1],"hello from child\0",17);
    }
    else{
        read(pip[0],string,15);
        printf("%s",string);
    }
}