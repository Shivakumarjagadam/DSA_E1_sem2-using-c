//BREADTH FIRST SEARCH...
#include<stdio.h>
#define max1 5
#define max2 5
void breadth_1st_search(int adj[5][5],int visited[],int start)
{
    int queue[5],rear=-1,front=-1,i;
    queue[++rear]=start;
    visited[start]=1;
    while(rear!=front)
    {
        start=queue[++front];
        printf("%c\t",start+65);
        for(i=0;i<max1;i++){
            if(adj[start][i]==1 && visited[i]==0){
                queue[++rear]=i;
                visited[i]=1;
            }
        }
    }
}
int main(){
    int visited[5]={0};
    int adj[max1][max2],i,j;
    printf("enter the adjacent matrix:\n");
    for(i=0;i<max1;i++){
        for(j=0;j<max2;j++){
            scanf("%d",&adj[i][j]);
        }
    }
    breadth_1st_search(adj,visited,0);
    printf("\n");
    return 0;

}