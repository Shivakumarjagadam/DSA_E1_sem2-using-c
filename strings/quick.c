#include<stdio.h>//sorting elements by quick sort...
void quicksort(int *arr,int low,int high);
void main(){
    int size,i;
    printf("enter size");
    scanf("%d",&size);
    int arr[size];
    printf("enter elements");
    for(i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    quicksort(arr,0,size-1);
    printf("after sorting:\n");
     for(i=0;i<size;i++){
        printf("%d\t",arr[i]);
    }

}
void quicksort(int *arr,int low,int high){
    if(low<high){
        int i,j,pivot,temp;
        i=low;
        j=high;
        pivot=low;
        while(i<j){
            while(arr[i]<=arr[pivot])
            i++;
            while(arr[j]>arr[pivot])
            j--;
            if(i<j){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
        temp=arr[pivot];
        arr[pivot]=arr[j];
        arr[j]=temp;
        quicksort(arr,0,j-1);
        quicksort(arr,j+1,high);

    }
}