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
        fd=open("fifo",O_WRONLY);
        fgets(arr, 10, stdin); 
        write(fd,arr,strlen(arr));
        close(fd);

    }
}