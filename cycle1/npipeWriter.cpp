#include<iostream>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h> 
#include<string.h>
#include<unistd.h>
#include<stdio.h>

using namespace std;
int main(){
    int fd;
    char *s ="fifo";
    mkfifo(s,0666);
    char arr[90],arr1[90];  
    while(1){
        fd=open(s,O_WRONLY);
        fgets(arr, 80, stdin); 
        write(fd,arr,strlen(arr)+1);
        close(fd);

    }
}