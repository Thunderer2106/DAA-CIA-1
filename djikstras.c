#include<stdio.h>
#include<conio.h>
#define HIGH 9999
#define MAXI 10

void Djikstra(int G[MAXI][MAXI], int n, int startnode);

int main(){
	int G[MAXI][MAXI], i, j, n, u;
	printf("\nEnter the no. of vertices:: ");
	scanf("%d", &n);
	printf("\nEnter the adjacency matrix::\n");
	for(i=0;i < n;i++)
	{
		for(j=0;j < n;j++)
		{
		    printf("Enter the %d,%d node:",i,j);
			scanf("%d", &G[i][j]);
		}
	}
	printf("\nEnter the starting node:: ");
	scanf("%d", &u);
	Djikstra(G,n,u);
	getch();
}

void Djikstra(int G[MAXI][MAXI], int n, int startnode)
{
	int value[MAXI][MAXI], distance[MAXI], pred[MAXI];
	int vis[MAXI], count, mindistance, nextN, i,j;
	for(i=0;i < n;i++)
		for(j=0;j < n;j++)
			if(G[i][j]==0)
				value[i][j]=HIGH;
			else
				value[i][j]=G[i][j];
	
	for(i=0;i< n;i++)
	{
		distance[i]=value[startnode][i];
		pred[i]=startnode;
		vis[i]=0;
	}
	distance[startnode]=0;
	vis[startnode]=1;
	count=1;
	while(count < n-1){
		mindistance=HIGH;
		for(i=0;i < n;i++)
			if(distance[i] < mindistance&&!vis[i])
			{
				mindistance=distance[i];
				nextN=i;
			}
		vis[nextN]=1;
		for(i=0;i < n;i++)
			if(!vis[i])
				if(mindistance+value[nextN][i] < distance[i])
				{
					distance[i]=mindistance+value[nextN][i];
					pred[i]=nextN;
				}
			count++;
	}

	for(i=0;i < n;i++)
		if(i!=startnode)
		{
			printf("\nDistance of %d = %d", i, distance[i]);
			printf("\nPath = %d", i);
			j=i;
			do
			{
				j=pred[j];
				printf(" <-%d", j);
			}
			while(j!=startnode);
		}
}
