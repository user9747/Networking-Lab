#include <stdio.h>
#include <string.h>
int main()
{
    int count,source,i,j,k,w,v,min;
    int cost_matrix[100][100],distance[100],last[100];
    int flag[100];
    printf("Enter the no of routers : ");
    scanf("%d",&count); 
    printf("Enter the cost matrix\n");
    for(i=0;i<count;i++)
    {
        for(j=0;j<count;j++)
        {
            printf("cost_matrix[%d][%d] : ",i,j);
            scanf("%d",&cost_matrix[i][j]);
            if(cost_matrix[i][j]<0)cost_matrix[i][j]=1000;
        }
    }
    printf("Enter the source router:");
    scanf("%d",&source);
    for(v=0;v<count;v++)
    {
        flag[v]=0;
        last[v]=source;
        distance[v]=cost_matrix[source][v];
    }
    flag[source]=1;
    for(i=0;i<count;i++)
    {
        min=1000;
        for(w=0;w<count;w++)
        {
            if(!flag[w])
                if(distance[w]<min)
                {
                    v=w;
                    min=distance[w];
                }
            }
            flag[v]=1;
            for(w=0;w<count;w++)
            {
                if(!flag[w])
                    if(min+cost_matrix[v][w]<distance[w])
                    {
                        distance[w]=min+cost_matrix[v][w];
                        last[w]=v;
                    }
                }
            }
            for(i=0;i<count;i++)
            {
                printf("\n%d==>%d---Path taken:%d",source,i,i);
                w=i;
                while(w!=source)
                {
                    printf("<--%d",last[w]);w=last[w];
                }
                printf("\n Shortest path cost:%d",distance[i]);
            }
        }