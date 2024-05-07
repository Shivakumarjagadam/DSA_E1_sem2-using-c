#include<stdio.h>
#define max 5

void dfs(int adj[][max],int visited[],int start){
int stack[max],top=-1,i;

stack[++top]=start;
while(top>=0){
    start=stack[top--];
    if(visited[start]==0){
     printf("%c->",start+65);
    visited[start]=i;

    for(i=0;i<max;i++){
        if(adj[start][i]==1  && visited[i]==0){
           
            stack[++top]=i;
            
        }

    }
    }
}

}
int main(){
    int adj[max][max];
    int visited[max]={0};
    int i,j;
    printf("entre the elements:\n");
    for(i=0;i<max;i++){
        for(j=0;j<max;j++){
            scanf("%d",&adj[i][j]);
        }
    }
    dfs(adj,visited,0);
    return 0;
}