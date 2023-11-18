//Example Graph text input
/*
7
0 1 1 0 0 0 0
0 0 0 1 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 1 0 0 0 0 0
0 0 1 0 0 0 1
1 0 0 0 1 0 0
*/
#include<stdio.h>
#include<stdlib.h>
 int x= 0;
 

int graph[7][7];
int visited[7];
int n; 


void DFS(int i)
{
    int j;
    visited[i]=1;
    for(j=0;j<n;j++){
       if(!visited[j]&&graph[i][j]==1){
            DFS(j);
       }
    }
}

int mothVex(){
    for(int i =0;i<n;i++){
        visited[i] = 0;
    }


    for(int i =0;i<n;i++){
        if(visited[i] == 0){
            DFS(i);
            x=i;
        }
    }
    for(int i =0;i<n;i++){
        visited[i] = 0;
    }
    DFS(x);
    for (int i = 0; i < n; i++){
        if (visited[i] == 0){
            x= -1;
        }
    }
    return x;
}

void main()
{
    int i,j;
    printf("Enter number of vertices:");

    scanf("%d",&n);
    printf("\nEnter adjecency matrix of the graph:");

    for(i=0;i<n;i++){
       for(j=0;j<n;j++){
        scanf("%d",&graph[i][j]);
       }
    }
 
   for(i=0;i<n;i++){
        visited[i]=0;
   }
   
    DFS(0);

     mothVex();
     if (x>0){
        printf("\nThe mother vertex is %d\n",x); 
     }
     else{
         printf("\n%d No mother vertex",x);
     }
    
}