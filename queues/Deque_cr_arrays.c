#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>//implementation of deque using circular array...
#define N 10
int Deque[N];
int fr=-1,re=-1;
void enque_front();
void deque_front();
void enque_rear();
void deque_rear();
void get_front();
void get_rear();
void display();
void main(){
   int op;
   do{
    printf("\n---MAIN--MENU---\n1.enque_front\n2.enque_rear\n3.deque_front\n4.deque_rear\n5.get_front\n6.get_rear\n7.display\n8.exit..\n");
   scanf("%d",&op);
   switch(op){
        case 1:enque_front();//insertion
        break;
        case 2:enque_rear();//insertion
        break;
        case 3:deque_front();//deletiion
        break;
        case 4:deque_rear();//deletiion
        break;
        case 5:get_front();
        break;
        case 6:get_rear();
        break;
        case 7:display();//printing values...
        break;
        default:printf("TRY AGAIN\n");
        
    }
   }while(op!=0);


}
void enque_front(){
    int x;
    printf("enter data\n");
    scanf("%d",&x);
    while(x!=-1){
    if((fr==0&&re==N-1)||fr==(re+1))
    printf("Dequeue is full\n");
    else if(fr==-1&&re==-1){
        fr=re=0;
        Deque[fr]=x;
    }
    else if(fr==0){
        fr=N-1;
        Deque[fr]=x;

    }
    fr--;
    Deque[fr]=x;
    printf("enter data && -1 stop -1\n");
    scanf("%d",&x);
    }

}
void enque_rear(){
    int x;
        printf("enter data\n");
    scanf("%d",&x);

    if((fr==0&&re==N-1)||fr==(re+1))
    printf("Dequeue is full\n");
    else if(fr==-1&&re==-1){
    fr=re=0;
    Deque[re]=x;
    }
    else if(re==N-1){
    re=0;
    Deque[re]=x;
    }
    else{
        re++;
        Deque[re]=x;
    }

}
void deque_front(){
    if(fr==-1&&re==-1)
    printf("Dequeue is empty\n");
    else if(fr==re)
    fr=re=-1;
    else if(fr==N-1)
    fr=0;
    else{
        fr++;
    }
}
void deque_rear(){
    if(fr==-1&&re==-1)
    printf("Dequeue is empty\n");
    else if(fr==re)
    fr=re=-1;
    else if(re==0)
    re=N-1;
    else{
        re--;
    }
}
void display(){
    int op;
    int i=fr;
     if(fr==-1&&re==-1)
    printf("Dequeue is empty\n");

   
    else{
    printf("The values are:\n");
    while(i!=re){
        printf("%d\t",Deque[i]);
        i=(i+1)%N;
    }
    printf("%d\n",Deque[re]);
    }
}
void get_front(){

if(fr==-1&&re==-1)
    printf("Dequeue is empty\n");
else{
    printf("%d\n",Deque[fr]);
}
}
void get_rear(){

if(fr==-1&&re==-1)
    printf("Dequeue is empty\n");
else{
    printf("%d\n",Deque[re]);
}
}