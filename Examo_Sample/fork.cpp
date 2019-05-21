#include<iostream>
#include <sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
using namespace std;

int main(){
    int pid,pip1[2],pip2[2];
    int n,num,i=1;
    pipe(pip1);
    pipe(pip2); 

    pid =fork();
    if(pid==0){
        while(1){
            num=i++;
            write(pip1[1],&num,sizeof(num));
            if(i==1000)
            break;
        }
        num=0;
        write(pip1[1],&num,sizeof(num));      
    }
    else{
        int pid2=fork();
        if(pid2==0){
            while(1){
                read(pip1[0],&n,sizeof(n));
                if (n == 0) 
                    break;
                if(n%2!=0)
                    write(pip2[1],&n,sizeof(n));
            } 
            n=0;
             write(pip2[1],&n,sizeof(n));
        }
        else{
             while(1){
                read(pip2[0],&n,sizeof(n));
                if (n == 0)
                    break;
                if(n%3 != 0)
                    cout<<n<<" ";
                
            }
        }
        
    }
}