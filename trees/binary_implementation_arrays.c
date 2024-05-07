#include<stdio.h>//binary tree implementation with arrays...
#define max 50
int arr[max];
int i=0;
void create();
int left(int index);
int right(int index);
void inorder(int index);
void preorder(int index);
void postorder(int index);

void main(){
int choice;
do{
    printf("\n\n---MAIN--MENU---\n1.create\n2.inorder traversal\n3.preorder traversal\n4.post ordre traversal\n");
printf("enter choice\n");
scanf("%d",&choice);
switch(choice){
    case 1:create();
    break;
    case 2:
            printf("inorder traversal::");
            inorder(0);
            break;
    case 3: printf("inorder traversal::");
             preorder(0);
             break;
    case 4: printf("inorder traversal::");
             postorder(0);
             break;
    default:printf("exit\n");
}
}while(choice!=0);
}
void create(){
    int val;
    printf("enter to create, -1 to stop: ");
    scanf("%d",&val);
    while(val!=-1)
    { 
    if(i<max){
        arr[i++]=val;
    }
    else{
        printf("array is fulled\n");
    }
    printf("enter to create, -1 to stop: ");
    scanf("%d",&val);

    }

}
void inorder(int index){
    if(index<i){
        inorder(left(index));
        printf("%d ",arr[index]);
        inorder(right(index));
    }
}
void preorder(int index){
    if(index<i){
        printf("%d ",arr[index]);
        preorder(left(index));
        preorder(right(index));
    }
}
void postorder(int index){
    if(index<i){
        postorder(left(index));
        postorder(right(index));
        printf("%d ",arr[index]);
    }
}
int left(int index){
    return (2*index)+1;
}
int right(int index){
    return (2*index)+2;
}