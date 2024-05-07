#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev,*next;
}*tail;
struct node *head=NULL;
struct node *create(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *head);
//struct node *insert_beg(struct node *);
void main(){
int choice;
do{
    printf("\n1.create\n2.display.\n3.insert_beg\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:head=create(head); break;
        case 2: head=display(head); break;
        case 3: head=insert_beg(head); break;
    }
}while(choice!=0);
}
struct node *create(struct node *head){
    struct node *newnode;
    int num;
    printf("enter number:\n");
    scanf("%d",&num);
    while(num!=-1){
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=0;
    newnode->prev=0;
    if(head==0){
        head=tail=newnode;
    }
    else{
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;

    }
    printf("enter number:\n");
    scanf("%d",&num);
    }
    return head;
}
struct node *display(struct node *head){
    struct node *temp;
    temp=head;
    while(temp!=0){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    return head;
}
struct node *insert_beg(struct node *head){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
  printf("enter data\n");
    scanf("%d",&newnode->data);
    newnode->next=head;
    head->prev=newnode;
    head =newnode;
    return head;
}