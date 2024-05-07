#include<stdio.h>
#define max 10
int i=0,a[max];
void insert_node(int n);
void inorder(int index);
void getleftchild(int i);
void getrightchild(int i);

void insert_node(int n){
    if(i>max-1){
        printf("binary tree is full\n");
        return ;
    }
    a[i]=n;
    i++;
}
void getleftchild(int i){
    return (2*i)+1;
}
void getrightchild(int i){
    return (2*i)+1;
}
 void inorder(int index){
    inorder(getleftchild(index));
    printf("%d",a[index]);
    inorder(getrightchild(index));

}

void main(){
    int n,index;
    insert_node( n);
    insert_node( n);
    insert_node( n);
    inorder(index);
}
