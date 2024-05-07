#include<stdio.h>//bt with tree...
#define max 20
int a[max];
void create();
void preorder(int index);
void inorder(int index);
void postorder(int index);
int left(int index);
int right(int index);
int main(){
    create();
    create();
    create();
    create();
    create();
    create();
    printf("inorder traversal");
    inorder(0);

    return 0;
}
void create(){
    int val,i=0;
//    int a[max];
    printf("enter val");
    scanf("%d",&val);
   // while(val!=-1){
        if(i<max)
    a[i++]=val;
    else
    printf("array is fulled");

    //  printf("enter val");
    // scanf("%d",&val);

  //  }
}
void inorder(int index){
    inorder(left(index));
    printf("%d\t",a[index]);
    inorder(right(index));
}
int left(int index){

return (2*index)+1;
}
int right(int index){
return (2*index)+2;
}