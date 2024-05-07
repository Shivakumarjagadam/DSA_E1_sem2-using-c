#include<stdio.h>
void main(){
    int a[50],i,size,num;
    printf("entre size:");
    scanf("%d",&size);
    printf("enter elements");
    for(i=0;i<size;i++){
        scanf("%d",&a[i]);
    }
    printf("enter an number to insert:\n");
    scanf("%d",&num);
    for(i=size;i>size-1;i--){        //insertion_at_end....
        a[i]=num;
    }
    size++;
    // for(i=size-1;i>=0;i--){
    //     a[i+1]=a[i];
    // }
    // a[0]=num;               //insertion_at_beginning.....
    // size++;
    for(i=0;i<size;i++){
        printf("%d\t",a[i]);
    }
}