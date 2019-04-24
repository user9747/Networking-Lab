#include<stdio.h>
struct node
{
    unsigned distance[20];
    unsigned via[20];
}router[10];
int main()
{
    int costmatrix[20][20];
    int nodes,i,j,k,count=0;
    printf("Enter the number of nodes - ");
    scanf("%d",&nodes);//Enter the nodes
    printf("Enter the cost matrix -\n");
    for(i=0;i<nodes;i++)
    {
        for(j=0;j<nodes;j++)
        {
            printf("Enter costmatrix[%d][%d] - ",i,j);
            scanf("%d",&costmatrix[i][j]);
            costmatrix[i][i]=0;
            router[i].distance[j]=costmatrix[i][j];//initialising the distance equal to cost matrix
            router[i].via[j]=j;//initialising the via part
        }
    }
        do
        {
            count=0;
            for(i=0;i<nodes;i++)
            for(j=0;j<nodes;j++)
            for(k=0;k<nodes;k++)
                if(router[i].distance[j]>costmatrix[i][k]+router[k].distance[j])
                {//Calculating the minimum distance
                    router[i].distance[j]=router[i].distance[k]+router[k].distance[j];
                    router[i].via[j]=k;
                    count++;
                }
        }while(count!=0);
        for(i=0;i<nodes;i++)
        {
            printf("\nFor router %d\n",i+1);
            for(j=0;j<nodes;j++)
            {
                printf("\t\nnode %d via %d - Distance: %d ",j+1,router[i].via[j]+1,router[i].distance[j]);
            }
        }
    printf("\n\n");
   
}