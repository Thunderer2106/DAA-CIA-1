#include<stdio.h>
#include<stdlib.h>

struct node{
int n1;
int n2;
int weight;
}*N;

int NextNode(struct node*arr[],int n){
  int min=0,minInd=0;
  for(int i=1;i<n+1;i++){
    if(arr[i]!=NULL){
      if(min==0){
        min=arr[i]->weight;
        minInd=i;
      }
      else if(min>arr[i]->weight){
        min=arr[i]->weight;
        minInd=i;
      }
    
    }
    
  }
  return minInd;
}

int main(){
  int n,min=0,minInd;
  printf("enter no of vertices: ");
  scanf("%d",&n);
  int arr1[n+1],arr2[n+1];
  for(int i=0;i<n+1;i++)
  arr1[i]=0;
  int edges,cost=0,n1,n2,w,ind=0;
  printf("enter no of edges: ");
  scanf("%d",&edges);
  struct node*arr[edges+1];
  arr[0]=0;
  for(int i=1;i<edges+1;i++){
    printf("enter two nodes to establish edge and enter weightght : ");
    scanf("%d %d %d",&n1,&n2,&w);
    N=malloc(sizeof(struct node));
    N->n1=n1;
    N->n2=n2;
    N->weight=w;
    arr[i]=N;
    if(w<0)w+=1000;
    if(min==0){
      min=w;
      minInd=i;
    }
    else if(min>w){
      min=w;
      minInd=i;
    }
  }
  arr2[ind++]=arr[minInd]->n1;
  arr2[ind++]=arr[minInd]->n2;
  arr1[arr[minInd]->n1]=1;
  arr1[arr[minInd]->n2]=1;
  cost+=arr[minInd]->weight;
  arr[minInd]=NULL;
  while(ind!=n){
    minInd=NextNode(arr,edges);
    if(arr1[arr[minInd]->n1]!=1||arr1[arr[minInd]->n2]!=1){
      if(arr1[arr[minInd]->n1]!=1)arr2[ind++]=arr[minInd]->n1;
      if(arr1[arr[minInd]->n2]!=1)arr2[ind++]=arr[minInd]->n2;
      arr1[arr[minInd]->n1]=1;
      arr1[arr[minInd]->n2]=1;
      cost+=arr[minInd]->weight;
    }
    arr[minInd]=NULL;
  }
  printf(" cost is:%d\n",cost);
  for(int i=0;i<ind;i++)printf(" %d",arr2[i]);

}
