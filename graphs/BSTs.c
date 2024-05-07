#include<stdio.h>//binary search tree...
#include<stdlib.h>
struct node{
    int data;
    struct node *left,*right;
}*root=0;
void inorder(struct node *root){
    if(root==0)
    return 0;
    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);
}
void preorder(struct node *root){
    if(root==0)
    return 0;
    printf("%d\t",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node *root){
    if(root==0)
    return 0;
    postorder(root->left);
    postorder(root->right);
    printf("%d\t",root->data);
}
struct node *insert(struct node *root,int val){
    if(root==0){
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=val;
        newnode->left=0;
        newnode->right=0;
        return newnode;
    }
    if(val<root->data){
        root->left=insert(root->left,val);
    }
    else if(val>root->data){
        root->right=insert(root->right,val);
    }
    return root;
}
struct node *search(struct node *root,int key){
     if(root==0)
     return 0;
     if(key < root->data)
     return search(root->left,key);
     else if(key >root->data)
     return search(root->right ,key);
     else
     return 1;
}
struct node *findmin(struct node *node){
    while(node->left!=0){
        node=node->left;
    }
    return node;
}
struct node *deletenode(struct node *root,int key){
    if(root==0){
        return root;
    }
    if(key<root->data){
        root->left=deletenode(root->left,key);

    }
    else if(key>root->data){
        root->right=deletenode(root->right,key);
    }
    else{
        //node with one child or no child...
        if(root->left==0){
            struct node *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==0){
            struct node *temp=root->left;
            free(root);
            return temp;
        }
        //nodes with 2 childs
        struct node *temp=findmin(root->right);
        root->data=temp->data;
        root->right=deletenode(root->right,temp->data);
    }

    return root;
}
int main(){
    int del,sear,n;
    printf("enter size");
    scanf("%d",&n);
    int array[n];
    printf("enter data:");
    for(int i=0;i<n;i++){
        scanf("%d",&array[i]);
    }
    for(int i=0;i<n;i++){
        root=insert(root,array[i]);//array elemets in to insertion
    }
    printf("\nINORDER TRAVERSAL\n");
    inorder(root);
    printf("\nPREORDER TRAVERSAL\n");
    preorder(root);
    printf("\nPOSTORDER TRAVERSAL\n");
    postorder(root);
    printf("\n");
    
    
    printf("enter to search\n");
    scanf("%d",&sear);
    if(search(root,sear)){
        printf("found\n");
    }
    else{
        printf("not fount\n");
    }
    printf("\n");

    printf("enter the data you want to delete\n");
    scanf("%d",&del);
    root=deletenode(root,del);
    printf("\nINORDER TRAVERSAL\n");
    inorder(root);
    printf("\nPREORDER TRAVERSAL\n");
    preorder(root);
    printf("\nPOSTORDER TRAVERSAL\n");
    postorder(root);
    return 0;

}