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
    char arr[90],arr1[90];
    while(1){
        fd=open("fifo",O_RDONLY);
        read(fd,arr,80);
        printf("%s",arr);
        close(fd);
    }
}