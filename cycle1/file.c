#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<errno.h>
extern int errno;
int main()
{
        int fd = open("in.txt", O_RDWR | O_CREAT);

        int fd1 = open("out.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
        int sz;
        if (fd ==-1)
        {
                printf("Error Number % d\n", errno);
        }
        else {
                char *c = (char *) calloc(100, sizeof(char));
                sz = read(fd, c,10 );
                c[sz] = '\0';
                sz = write(fd1,c, 8);
                if(close(fd) == 0 && close(fd1)==0) {
                        printf("File closed\n");
                }
        }
        return 0;
}
