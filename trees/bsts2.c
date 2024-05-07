#include<stdio.h>

#include<stdlib.h>// implementation of bst...
struct node {
    int data;
    struct node *left,*right;
}*root=0;
void inorder(struct node *root){
    if(root==0)
    return ;
    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);
}
void preorder(struct node *root){
    if(root==0)
    return ;
    printf("%d\t",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node *root){
    if(root==0)
    return ;  //insert,search,findmin,del
    postorder(root->left);
    postorder(root->right);
    printf("%d\t",root->data);
}
struct node *insert(struct node *root,int val){
if(root==0){
struct node *newnode=(struct node*)malloc(sizeof(struct node));
// printf("enter data");
// scanf("%d",&val);
newnode->data=val;
newnode->left=newnode->right=0;
return newnode;
}
if(val < root->data)
root->left=insert(root->left,val);
else if(val>root->data)
root->right=insert(root->right,val);

return root;

}
struct node *search(struct node *root,int key){
    if(root==0)
    return 0;
    if(key <root->data)
    return search(root->left,key);
    else if(key >root->data)
    return search(root->right,key);
    else 
    return 1;
}
struct node *findmin(struct node *node){
    while(node->left!=0){
        node=node->left;
    }
    return node;
}
struct node *delnode(struct node *root,int key){
if(root==0)
return root;
if(key <root->data)
root->left=delnode(root->left,key);
else if(key >root->data)
root->right=delnode(root->right,key);

//if node has 1 or no child..then
else{
if(root->left==0){
struct node *temp=root->right;
free(root);
return temp;
}
// else if(root->right=0){
//     struct node *temp=root->left;
//     free(root);
//     return temp;
// }
// //if node has 2 childs...
// struct node *temp =findmin(root->right);
// root->data=temp->data;
// root->right=delnode(root->right,temp->data);

else if(root->right=0){
     struct node *temp=root->left;
     free(root);
     return temp;
}
     //if node has 2 childs....
     struct node *temp=findmin(root->right);
     root->data=temp->data;
     root->right=delnode(root->right,temp->data);
}
return root;

}

int main(){
    int n;
    printf("enter size");
    scanf("%d",&n);
    int array[n];
    printf("enter elements");
    for(int i=0;i<n;i++){
        scanf("%d",&array[i]);
    }
    for(int i=0;i<n;i++){
        root=insert(root,array[i]);
    }
    printf("\nINORDER \n");
    inorder(root);
    printf("\npreORDER \n");
    preorder(root);
    printf("\nPOSTORDER \n");
    postorder(root);
    printf("\n");

    int sch,del;
    printf("enter search element:");
    scanf("%d",&sch);
    
    if(search(root,sch))
    printf("found\n");
    else 
    printf("not found\n");

    printf("enter data to delete\n");
    scanf("%d",&del);

    root=delnode(root,del);
     printf("\nINORDER \n");
    inorder(root);
    printf("\npreORDER \n");
    preorder(root);
    printf("\nPOSTORDER \n");
    postorder(root);
    printf("\n");

    return 0;

}