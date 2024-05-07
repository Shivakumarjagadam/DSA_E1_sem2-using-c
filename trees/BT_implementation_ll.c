#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *left,*right;
};
struct node *create();
void inorder(struct node *root);
void preorder(struct node *root);
void postorder(struct node *root);
struct node *create(){
int x;
struct node *newnode;
newnode=(struct node *)malloc(sizeof(struct node));
printf("enter X and -1 to stop\n");
scanf("%d",&x);
if(x==-1){
return 0;
}
newnode->data=x;
printf("enter left child of %d,",x);
newnode->left=create();
printf("enter right child of %d,",x);
newnode->right=create();
return newnode;

}
void main(){
    struct node *root;
    root=create();
    //inorder(root);
    //preorder(root);
    postorder(root);

}
void inorder(struct node *root){
    
    if(root==0)
    return ;
    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);
    
    }
void preorder(struct node *root){
    if(root==0)
    return;

    printf("%d\t",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node *root){
    if(root ==0)
    return ;
    postorder(root->left);
    postorder(root->right);
    printf("%d\t",root->data);
}