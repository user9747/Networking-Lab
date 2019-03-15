#include<iostream>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h> 
#include<string.h>
#include<unistd.h>

using namespace std;
int main(){
    int fd;
    mkfifo("fifo",0666);
    char arr[10],arr1[10];
    while(1){
        fd=open("fifo",O_RDONLY);
        read(fd,arr,10);
        printf("%s",arr);
        close(fd);
    }
}