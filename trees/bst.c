#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

 struct node *root = NULL;
 
void inorder(struct node *root)
{
   if(root == NULL)
   return;
   
   inorder(root->left);
   printf("%d\t",root->data);
   inorder(root->right);
}

void preorder(struct node *root)
{
   if(root == NULL)
   return;
   printf("%d\t",root->data);
   preorder(root->left);
 
   preorder(root->right);
}
//printf("\n");
void postorder(struct node *root)
{
   if(root == NULL)
   return;
  
   postorder(root->left);
 
   postorder(root->right);
   printf("%d\t",root->data);
}

struct node *implement(struct node *root,int val)
{
      if(root == NULL)
      {
          struct node *newnode = (struct node*)malloc(sizeof(struct node));
          newnode->data=val;
          newnode->left=newnode->right=NULL;
          return newnode;
      }
      if(val < root->data)
      {
         root->left = implement(root->left,val);
         
      }
      else if(val > root->data)
      {
          root->right = implement(root->right,val);
      }
      return root;
}


int *search(struct node *root,int key)
{
      if(root==0)
      {
        return 0;
      }
      if(root->data > key)
      {
         return search(root->left,key);
      }
      else if(root->data == key)
      {
        return 1;
      }
      else 
      {
         return search(root->right,key);
      }

}  


struct node *findmin(struct node *node)
{
    while( node->left != NULL )
    {
         node = node->left;
    }
    return node;
}

struct node *deletenode(struct node *root, int key )
 {
   if(root == NULL)
   {
       return root;
   }
   if(key < root->data)
   {
       root->left = deletenode( root->left, key );
   }
   else if(key > root->data)
   {
       root->right = deletenode( root->right, key );
   }
   else
   {
     //Node with one child or no child
     
     if(root->left == NULL)
     {
         struct node *temp=root->right;
         free(root);
         return temp;
     }
     else if( root->right == NULL )
     {
          struct node *temp=root->left;
          free(root);
          return temp;
     }
       // NOde with two children : get the inorder successsor (smallest in right sub -tree)
       struct node *temp =findmin(root->right );
       
       // copy the inorder sucessor 
       root->data =temp->data;
       
       // Delete the inorder successor 
       root->right = deletenode( root->right, temp->data );
   }
   return root;
}
           
int main()
{
     int del,sear,n;
     printf("Enter size :");
     scanf("%d",&n);
     int array[n];
   //  Printf("Enter elelments :");
     printf("Enter data :\n");
     for(int i=0;i<n;i++)
     {
          scanf("%d",&array[i]);
     }
     
     for(int i=0;i<n;i++)
     {
        root = implement(root,array[i]);
     }
    printf("Inorder traversal   :\n");
    inorder(root);
    printf("\npreorder traversal   :\n");
    preorder(root);
    printf("\npostorder traversal   :\n");
    postorder(root);
     printf("\n");
     
     printf("Enter to search :");
     scanf("%d",&sear);
     
     if(search(root,sear))
     {
        printf("Found :\n");
     }
     else 
     {
       printf("Not found :\n");
     }
       printf("\n");
    
    printf("Enter the data you want to delete :" );
    scanf("%d",&del);
    
    root = deletenode(root,del);
    printf("\nInorder traversal   :\n");
    inorder(root);
    printf("\npreorder traversal   :\n");
    preorder(root);
    printf("\npostorder traversal   :\n");
    postorder(root);
    return 0;
 }
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
     

