#include<stdio.h>
void mergs(int *arr,int low,int mid,int high);
void mergsort(int *arr,int low,int high);

int main(){
int size,i;
printf("enter size:\n");
scanf("%d",&size);
int arr[size];
printf("enter elements:\n");
for(i=0;i<size;i++){
    scanf("%d",&arr[i]);
}
mergsort(arr,0,size-1);
printf("\nsorted elements:\n");
for(i=0;i<size;i++){
    printf("%d\t",arr[i]);
}
return 0;

    
}
void mergsort(int *arr,int low,int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        mergsort(arr,0,mid);
        mergsort(arr,mid+1,high);
        mergs(arr,low,mid,high);
    }
}
void mergs(int *arr,int low,int mid,int high){
    int i,j,k,b[50];
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid &&j<=high){
        if(arr[i]<=arr[j]){
        b[k++]=arr[i++];
        }
        else{
            b[k++]=arr[j++];
        }

    }
    if(i>mid){
        while(j<=high){
            b[k++]=arr[j++];
        }
    }
    else{
        while(i<=mid){
            b[k++]=arr[i++];
        }
    }
    for(k=low;k<=high;k++){
        arr[k]=b[k];
    }
}