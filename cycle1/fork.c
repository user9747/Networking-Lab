#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    int x=fork();
    int y=fork();
    wait();
    if(x==0){
      printf("Child fork Value : %d \t pid : %d\n",x,getpid());
    }
    else{
      printf("In Parent");
      sleep(5);
      printf("Parent fork Value : %d \t pid : %d\n",x,getpid());
    }
    exit(0);
    printf("Hello World");
    return 0;
}
